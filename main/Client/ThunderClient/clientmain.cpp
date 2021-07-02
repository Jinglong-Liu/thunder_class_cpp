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

    connectRequest = new ConnectRequest(socket);
    //connect(login,&Login::requestForConnect,connectRequest,&ConnectRequest::recvAddr);
    connect(login,&Login::requestForConnect,this,&ClientMain::doConnectRequest);//request for connection.
    //login ui
    connect(this,&ClientMain::initLoginUi,login,&Login::initView);


    connect(analyser,&Analyser::newStudent,this,&ClientMain::addNewStudent);
    connect(analyser,&Analyser::studentLoginSucceed,this,&ClientMain::studentLoginSucceed);//
    connect(analyser,&Analyser::studentLoginFail,login,&Login::studentLoginFail);
    connect(analyser,&Analyser::studentLoginNotFound,login,&Login::studentLoginNotFound);

    //发送
    connect(login,&Login::studentLoginRequest,sender,&MsgSender::sendStudentLoginRequest);//发送学生登录请求
    //接收
    connect(receiver,&RecvMsg::recvMsg,analyser,&Analyser::analyse);//接收信息

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
    //studentView->updateOnlineData(count);//更新信息(人数)
}

void ClientMain::studentLoginSucceed(StudentInfo *info)
{
    //client作为学生登录成功
    //ui
    login->studentLoginSucceed();
    login->hide();
    //display this student's info in the ui.
    studentView->displayStudentInfo(info);
    studentView->show();
    //data
    student = info;

    addNewStudent(info);
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
    //receiver->run();//只可以单线运行...
    receiver->start();//这样貌似是可以的
}

