#include "recvmsg.h"

RecvMsg::RecvMsg(QTcpSocket *socket)
{
    this->tcpsocket = socket;
}

void RecvMsg::run()
{
    connect(tcpsocket,&QTcpSocket::readyRead,this,[=](){
        QByteArray message = tcpsocket->readAll();
        qDebug()<<"receive message:"+message;
        emit recvMsg(message);
    });
}
