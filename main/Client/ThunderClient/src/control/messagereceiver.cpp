#include"../../include/control/messagereceiver.h"
MessageReceiver::MessageReceiver(QTcpSocket *socket)
{
    this->tcpsocket = socket;
}

void MessageReceiver::run()
{
    receive();
}

void MessageReceiver::receive()
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
