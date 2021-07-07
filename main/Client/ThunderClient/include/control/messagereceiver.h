#ifndef RECVMSG_H
#define RECVMSG_H
#include"../config/config.h"
#include"../model/message.h"
class MessageReceiver:public QThread
{
    Q_OBJECT
public:
    MessageReceiver(QTcpSocket *socket);
    void run()override;
    void receive();
signals:
    void recvMsg(QByteArray message);
private:
    QTcpSocket *tcpsocket;
    QQueue<Message>massageQueue;

};

#endif // RECVMSG_H
