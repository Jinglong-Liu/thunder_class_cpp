#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    onlineData = new OnlineData();
    student = new StudentInfo();
    socket = new QTcpSocket;
    studentView = new StudentView(onlineData);
    ui->setupUi(this);
    ui->ip->setText("127.0.0.1");
    ui->port->setText("7788");
    ui->id->setDisabled(true);
    ui->password->setDisabled(true);
    connectRequest = new ConnectRequest(socket);
    connect(this,&Login::requestForConnect,connectRequest,&ConnectRequest::recvAddr);

    analyser = new Analyser();
    connect(analyser,&Analyser::studentLoginSucceed,this,[=](StudentInfo* stuInfo){

        //登录成功
        //QMessageBox::information(nullptr,"提示","登录成功!");
        this->ui->loginStudentBtn->setDisabled(true);
        ui->loginTeacherBtn->setDisabled(true);
        ui->loginStudentBtn->setText("学生登录成功");
        this->student = stuInfo;
        studentView->show();
        //studentView->ui->id->setText(stuInfo->getId())
        studentView->updateInfo(stuInfo);
    });
    connect(analyser,&Analyser::studentLoginFail,this,[=](){
        QMessageBox::information(nullptr,"警告","密码错误,请重新登录");
    });
    connect(analyser,&Analyser::studentLoginNotFound,this,[=](){
        QMessageBox::information(nullptr,"提示","id不存在,请重新确认");
    });
    connect(analyser,&Analyser::newStudent,this,[=](StudentInfo* info){
        onlineData->setOnlineNum(onlineData->getOnlineNum()+1);
        studentView->addOnlineStudent(info);
    });
}

Login::~Login()
{
    delete ui;
}

void Login::on_connectBtn_clicked()
{
    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();
    emit requestForConnect(ip,port);

    socket->connectToHost(QHostAddress(ip),port);//尝试连接
    ui->connectBtn->setDisabled(true);
    if(socket->waitForConnected(1000)){
        qDebug()<<"连接成功";
        ui->connectBtn->setDisabled(true);
        ui->connectBtn->setText("连接成功");
        ui->ip->setDisabled(true);
        ui->port->setDisabled(true);
        ui->id->setEnabled(true);
        ui->password->setEnabled(true);
        QMessageBox::information(nullptr,"提示","连接成功");
        //QThreadPool::globalInstance()->start(connectRequest);
        //
        connect(socket,&QTcpSocket::readyRead,this,[=](){
            QByteArray data = socket->readAll();
            qDebug()<<"data:" + data;
            analyser->setMessage(data);
            analyser->analyse();
            //TODO:处理不同类型的报文
        });
        //
    }
    else {
        qDebug()<<"连接失败";
        QMessageBox::information(nullptr,"提示","连接失败");
        ui->connectBtn->setText("尝试重连");
        ui->connectBtn->setEnabled(true);
    }

    //connectRequest->run();
}

void Login::on_loginStudentBtn_clicked()
{
    //学生登录
    QString id = ui->id->text();
    QString password = ui->password->text();
    //向服务器发送请求
    //学生登录请求报文：0x12 + id_len + id + password
    //解析为18,我需要的是0x0012
    uint32_t head = 0x12;
    uint32_t id_len = id.length();

    QByteArray msg = Util::toHexByteArray(head)
            + Util::toHexByteArray(id_len)
            + id.toUtf8()
            + password.toUtf8();
    //qDebug()<<msg;
    socket->write(msg);

}
