#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "correspond.h"
#include <QLabel>
#include<QThreadPool>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qRegisterMetaType<Prepare>("Prepare");
    data = new Data();//一份，注意线程同步
    onlineData = new OnlineData();
    //analyser = new AnalysisMsg();
    //correspondThread = new QThread();
    correspond = new Correspond(data);
    //correspond->moveToThread(correspondThread);
    ui->setupUi(this);
    setWindowTitle("服务器");
    ui->ip->setText("127.0.0.1");
    ui->port->setText("7788");

    connect(this,&MainWindow::start,correspond,&Correspond::recvAddr);
    connect(correspond,&Correspond::online_num,this,[=](int num){
        qDebug()<<"人数：" + QString::number(num);
        ui->online_num->setNum(num);
        //在线人数变化
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    ui->start->setText("服务器已启动");
    ui->start->setDisabled(true);
    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();
    //server->listen(QHostAddress::Any,port);
    emit start(ip,port);

    //QThreadPool::globalInstance()->start(correspond);//can't listen?客户端可以连接，服务器没法监听

    correspond->run();//单线程倒是可以...
}
