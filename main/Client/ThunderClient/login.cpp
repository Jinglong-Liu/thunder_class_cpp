#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->ip->setText("127.0.0.1");
    ui->port->setText("7788");
    ui->id->setDisabled(true);
    ui->password->setDisabled(true);
    connectRequest = new ConnectRequest;
    connect(this,&Login::requestForConnect,connectRequest,&ConnectRequest::recvAddr);
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

    connectRequest->getSocket()->connectToHost(QHostAddress(ip),port);
    ui->connectBtn->setDisabled(true);
    if(connectRequest->getSocket()->waitForConnected(1000)){
        qDebug()<<"连接成功";
        ui->connectBtn->setDisabled(true);
        ui->connectBtn->setText("连接成功");
        ui->ip->setDisabled(true);
        ui->port->setDisabled(true);
        ui->id->setEnabled(true);
        ui->password->setEnabled(true);
        QMessageBox::information(nullptr,"提示","连接成功");
        QThreadPool::globalInstance()->start(connectRequest);
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

    //QByteArray msg = ((unsigned short)0x11) + id.toUtf8() + password.toUtf8();
    //connectRequest->getSocket()->write(());

}
