#include "msgrecevier.h"

MsgRecevier::MsgRecevier(QTcpSocket *socket, QObject *parent)
{
    this->socket = socket;
}
/**
 * @brief MsgRecevier::receive
 * 能读取的只有一小段时间内的buffer的数据！经检验，多次read可能只有第一次能成功读取
 */
void MsgRecevier::receive(){
    qDebug()<<"receive()";
    Header header;
    //加锁
    Util::tcpSocketMutex.lock();
    QByteArray all = socket->readAll();//read once!
    header = *(Header*)all.mid(0,sizeof(header)).data();
    QByteArray data = all.mid(sizeof(header));
    Util::tcpSocketMutex.unlock();

    Message message(header,data);
    MsgAnalyser *analyser = new MsgAnalyser(message,socket);
    analyser->analyse();
    analyser->deleteLater();
}

void MsgRecevier::run()
{
    receive();
}
