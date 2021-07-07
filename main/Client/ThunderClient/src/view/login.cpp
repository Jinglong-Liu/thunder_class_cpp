#include "../../include/view/login.h"
#include "ui_login.h"
#include<QMessageBox>
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    initView("127.0.0.1",7788);
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
    this->hide();
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
}
