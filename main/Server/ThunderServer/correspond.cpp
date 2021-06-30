#include "correspond.h"
#include "mainwindow.h"
Correspond::Correspond()
{
    //emit online_num(0);
}


void Correspond::startListen(QString ip, unsigned short port)
{

    server = new QTcpServer();

    server->listen(QHostAddress(ip),port);
    //emit online_num(0);
    //
    connect(server,&QTcpServer::newConnection,this,[=](){
        QTcpSocket* socket = server->nextPendingConnection();
        sockets.insert(socket);
        qDebug()<<sockets.size();
        emit online_num(sockets.size());
        //m_status->setPixmap(QPixmap(":/img/ok.jpg").scaled(20,20));
        //statuBa->setText("在线人数" + QString(sockets.size()));
        //检测是否可以接受数据
        connect(socket,&QTcpSocket::readyRead,this,[=](){
            QByteArray data = socket->readAll();
            //TODO:处理数据，传入这个socket和其他所有socket
            //多线程处理，注意线程互斥
            //QByteArray backData = /
            //QTcpSocket backSocket =
            //TODO:回发数据
            //ui->record->append("client say:" + data);
        });

        connect(socket,&QTcpSocket::disconnected,this,[=](){
            socket->close();
            sockets.remove(socket);
            socket->deleteLater();
            emit online_num(sockets.size());
        });
    });

    //状态栏
    //m_status = new QLabel;
}

void Correspond::run()
{
    startListen(ip,port);
}

void Correspond::recvAddr(QString ip, unsigned short port)
{
    this->ip = ip;
    this->port = port;
}
