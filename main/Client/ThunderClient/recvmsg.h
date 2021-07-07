#ifndef RECVMSG_H
#define RECVMSG_H
#include"config.h"
#include"message.h"
class RecvMsg:public QThread
{
    Q_OBJECT
public:
    RecvMsg(QTcpSocket *socket);
    void run()override;
    void receive();
signals:
    void recvMsg(QByteArray message);
private:
    QTcpSocket *tcpsocket;
    QQueue<Message>massageQueue;

};

#endif // RECVMSG_H
