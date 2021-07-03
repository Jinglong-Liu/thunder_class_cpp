#include "recvmsg.h"

RecvMsg::RecvMsg(QTcpSocket *socket)
{
    this->tcpsocket = socket;
}

void RecvMsg::run()
{
    connect(tcpsocket,&QTcpSocket::readyRead,this,[=](){
        //QByteArray message = tcpsocket->readAll();

        Util::tcpSocketMutex.lock();
        Message message;

        Util::tcpSocketMutex.unlock();
    });
}
