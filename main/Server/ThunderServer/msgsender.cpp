#include "msgsender.h"

MsgSender::MsgSender(QObject *parent) : QObject(parent)
{

}

void MsgSender::broadcastOnlineNum(int num)
{
    /*
    int head = 0x0fff0001;
    Prepare p;
    p.messageToSend = Util::toHexByteArray(head)
                    +Util::toHexByteArray(num);
    Util::tcpSocketMutex.lock();
    p.socketsToSend = Util::tcpSockets;
    Util::tcpSocketMutex.unlock();
    qDebug()<<"size:" + QString::number(p.socketsToSend.size());
    send(p);
    */
}

void MsgSender::send(Prepare p)
{
    for(auto socket:p.socketsToSend){
        socket->write(p.messageToSend);
    }
}

void MsgSender::sendStudentLoginSuccess(QTcpSocket *socket, StudentInfo *info)
{
    Header header(0x12);
    QByteArray data;

}
