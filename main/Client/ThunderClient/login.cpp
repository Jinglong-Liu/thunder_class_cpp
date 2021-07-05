#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include"messagesender.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    initView("127.0.0.1",7788);
    //socket = new QTcpSocket();
    /*
    onlineData = new OnlineData();
    student = new StudentInfo();
    socket = new QTcpSocket;
    studentView = new StudentView();
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
        studentView->displayStudentInfo(stuInfo);
    });*/
    /*
    connect(analyser,&Analyser::studentLoginFail,this,[=](){
        QMessageBox::information(nullptr,"警告","密码错误,请重新登录");
    });
    connect(analyser,&Analyser::studentLoginNotFound,this,[=](){
        QMessageBox::information(nullptr,"提示","id不存在,请重新确认");
    });
    connect(analyser,&Analyser::newStudent,this,[=](StudentInfo* info){
        onlineData->setOnlineNum(onlineData->getOnlineNum()+1);
        studentView->addOnlineStudent(info);
    });*/
}

void Login::initView(QString ip, unsigned short port)
{
    ui->ip->setText(ip);
    ui->port->setText(QString::number(port));
    ui->id->setDisabled(true);
    ui->password->setDisabled(true);
}

void Login::studentLoginSucceed()
{
    this->ui->loginStudentBtn->setDisabled(true);
    ui->loginTeacherBtn->setDisabled(true);
    ui->loginStudentBtn->setText("学生登录成功");
}

void Login::studentLoginFail()
{
    QMessageBox::information(nullptr,"警告","密码错误,请重新登录");
}

void Login::studentLoginNotFound()
{
    QMessageBox::information(nullptr,"提示","id不存在,请重新确认");
}

void Login::connectSucceed()
{
    ui->connectBtn->setDisabled(true);
    ui->connectBtn->setText("连接成功");
    ui->ip->setDisabled(true);
    ui->port->setDisabled(true);
    ui->id->setEnabled(true);
    ui->password->setEnabled(true);
    QMessageBox::information(nullptr,"提示","连接成功");
}

void Login::connectFail()
{
    ui->connectBtn->setText("尝试重连");
    ui->connectBtn->setEnabled(true);
    QMessageBox::information(nullptr,"提示","连接失败");
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
}

void Login::on_loginStudentBtn_clicked()
{

    //传送和请求数据到clientMain
    //学生登录
    QString id = ui->id->text();
    QString password = ui->password->text();
    emit studentLoginRequest(id,password);

    //MessageSender sender(socket);
    //sender.sendStudentLoginRequest(id,password);
    /*
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
    socket->write(msg);*/

}
