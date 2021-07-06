#include "correspond.h"
#include "mainwindow.h"
#include "analysismsg.h"
#include"config.h"
#include<QThreadPool>
#include"messageanalyser.h"
Correspond::Correspond()
{
    //emit online_num(0);
}

Correspond::Correspond(Data *data){
    this->data = data;
}


void Correspond::startListen(QString ip, unsigned short port)
{
    MsgSender* sender = new MsgSender();
    server = new QTcpServer();

    server->listen(QHostAddress(ip),port);
    //
    connect(server,&QTcpServer::newConnection,this,[=](){
        QTcpSocket* socket = server->nextPendingConnection();
        Util::tcpSocketMutex.lock();
        Util::tcpSockets.insert(socket);
        qDebug()<<Util::tcpSockets.size();
        emit online_num(Util::tcpSockets.size());

        Util::tcpSocketMutex.unlock();
        //m_status->setPixmap(QPixmap(":/img/ok.jpg").scaled(20,20));
        //statuBa->setText("在线人数" + QString(sockets.size()));
        //检测是否可以接受数据
        connect(socket,&QTcpSocket::readyRead,this,[=](){
            QByteArray message = socket->readAll();
            //TODO:处理数据，传入这个socket和其他所有socket
            qDebug()<<"recv:"+message;
            Message m(message);

            MessageAnalyser *a = new MessageAnalyser(m,socket);
            a->run();//单线程可以收发的
            //QThreadPool::globalInstance()->start(a);//可以接收，不可以发送...(子线程)
        });

        connect(socket,&QTcpSocket::disconnected,this,[=](){
            //TODO
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
