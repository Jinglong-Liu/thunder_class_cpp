#include "correspond.h"
#include "mainwindow.h"
#include"config.h"
#include<QThreadPool>
#include"messageanalyser.h"
#include"logouthandler.h"
Correspond::Correspond()
{
    this->data = Data::instance();
}

Correspond::Correspond(Data *data){
    this->data = data;
}


void Correspond::startListen(QString ip, unsigned short port)
{
    server = new QTcpServer();
    server->listen(QHostAddress(ip),port);

    connect(server,&QTcpServer::newConnection,this,[=](){
        QTcpSocket* socket = server->nextPendingConnection();

        sockets.insert(socket);

        emit online_num(sockets.size());
        emit online_student_num(Data::instance()->getOnlineStudentNumber());

        //检测是否可以接受数据
        connect(socket,&QTcpSocket::readyRead,this,[=](){
            QByteArray messages = socket->readAll();
            //TODO:处理数据，传入这个socket和其他所有socket
            qDebug()<<"recv:"+messages;
            Message m(messages);
            for(Message msg:m.splitMessage()){
                MessageAnalyser *a = new MessageAnalyser(msg,socket);
                a->run();//单线程可以收发的
            }
            //QThreadPool::globalInstance()->start(a);//可以接收，不可以发送...(子线程)
        });
        //学生退出(暂时没有考虑老师)
        connect(socket,&QTcpSocket::disconnected,this,[=](){
            //TODO
            socket->close();
            sockets.remove(socket);

            emit online_num(sockets.size());//这个不大对
            //emit online_teacher_num()
            LogoutHandler *handler = new LogoutHandler();
            handler->handle(socket);
            emit online_student_num(Data::instance()->getOnlineStudentNumber());
            emit online_teacher_num(Data::instance()->getOnlineTeacherNumber());
            socket->deleteLater();
        });
    });
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
