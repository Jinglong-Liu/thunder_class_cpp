#include "clientmain.h"
#include"config.h"
#include<QtCore>
ClientMain::ClientMain()
{
    login = new Login();
    onlineData = new OnlineData();
    student = new StudentInfo();
    socket = new QTcpSocket;
    studentView = new StudentView();

    analyser = new Analyser();
    receiver = new RecvMsg(socket);
    sender = new MsgSender(socket);
    emit initLoginUi("127.0.0.1",7788);

    /*
     * emit to ui.
    ui->ip->setText("127.0.0.1");
    ui->port->setText("7788");
    ui->id->setDisabled(true);
    ui->password->setDisabled(true);
    */
    connectRequest = new ConnectRequest(socket);
    //connect(login,&Login::requestForConnect,connectRequest,&ConnectRequest::recvAddr);
    connect(login,&Login::requestForConnect,this,&ClientMain::doConnectRequest);//request for connection.
    //login ui
    connect(this,&ClientMain::initLoginUi,login,&Login::initView);


    connect(analyser,&Analyser::newStudent,this,[=](){
        qDebug()<<"新同学加入";
    });
    connect(analyser,&Analyser::studentLoginSucceed,this,&ClientMain::studentLoginSucceed);//
    connect(analyser,&Analyser::studentLoginFail,login,&Login::studentLoginFail);
    connect(analyser,&Analyser::studentLoginNotFound,login,&Login::studentLoginNotFound);

    //发送
    connect(login,&Login::studentLoginRequest,sender,&MsgSender::sendStudentLoginRequest);//发送学生登录请求
    //接收
    connect(receiver,&RecvMsg::recvMsg,analyser,&Analyser::analyse);

    login->show();
}

void ClientMain::addNewStudent(StudentInfo *info)
{
    //to data
    onlineData->studentOnline(info);
    //to ui

    //login ui
    login->studentLoginSucceed();
    //student ui
    studentView->addOnlineStudent(info);
    studentView->updateOnlineData(onlineData);//更新信息(人数)
}

void ClientMain::studentLoginSucceed(StudentInfo *info)
{
    //client作为学生登录成功
    //ui
    login->studentLoginSucceed();
    //display this student's info in the ui.
    studentView->displayStudentInfo(info);
    studentView->show();
    //data
    student = info;
}

void ClientMain::doConnectRequest(QString ip, unsigned short port)
{
    socket->connectToHost(QHostAddress(ip),port);//尝试连接
    if(socket->waitForConnected(500)){
        qDebug()<<"连接成功";
        //ui
        login->connectSucceed();
        //QThreadPool::globalInstance()->start(connectRequest);
        //
        tryToRecvMsg(this->socket);
        //socket->write("123");
        //
    }
    else {
        qDebug()<<"连接失败";
        login->connectFail();
    }
}

void ClientMain::tryToRecvMsg(QTcpSocket *socket)
{
    /*
    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QByteArray data = socket->readAll();
        qDebug()<<"data:" + data;
        analyser->setMessage(data);
        analyser->analyse();
        //TODO:处理不同类型的报文
    });*/
    //sender = new MsgSender(socket);
    //receiver = new RecvMsg(socket);
    //QThreadPool::globalInstance()->start(receiver);//这样无法接收信息
    receiver->run();//只可以单线运行...
}

