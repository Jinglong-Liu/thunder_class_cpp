#include "recvmsg.h"

RecvMsg::RecvMsg(QTcpSocket *socket)
{
    this->tcpsocket = socket;
}

void RecvMsg::run()
{
    receive();
}

void RecvMsg::receive()
{
    //ok!!!!
    connect(tcpsocket,&QTcpSocket::readyRead,this,[=](){
        qDebug()<<"to receive..";
        QByteArray datas = tcpsocket->readAll();
        Message m(datas);
        qDebug()<<"m = " + m.toByteArray();//ok
        QList<Message> messages = m.splitMessage();
        for(Message message:messages){
            emit recvMsg(message.toByteArray());
        }
    });
}
