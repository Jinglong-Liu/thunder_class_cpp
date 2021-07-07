#include "msgreceiver.h"

MsgReceiver::MsgReceiver(QTcpSocket* socket,QObject *parent) : QThread(parent)
{
    this->socket = socket;
    //this->analyser = new Analyser();
}

Message MsgReceiver::receive()
{
    qDebug()<<"try to receive..";
    Header header;
    //加锁
    Util::tcpSocketMutex.lock();
    socket->read((char*)&header,sizeof(header));
    char buffer[8192];
    socket->read(buffer,header.getDataSize());

    qDebug()<<QString::number(header.getType(),16)<<" "<<header.getDataSize()<<header.getHeadSize();
    QByteArray data(buffer);
    Util::tcpSocketMutex.unlock();
    Message message(header,data);

    MsgAnalyser* analyser = new MsgAnalyser(message);
    analyser->start();
    //analyser->analyse(message);
    //analyser->deleteLater();
    //
    return message;
    //
}

void MsgReceiver::run()
{

}
