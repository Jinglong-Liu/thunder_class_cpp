#ifndef RECVMSG_H
#define RECVMSG_H
#include"config.h"

class RecvMsg:public QObject,public QRunnable
{
    Q_OBJECT
public:
    RecvMsg(QTcpSocket *socket);
    void run()override;
signals:
    void recvMsg(QByteArray message);
private:
    QTcpSocket *tcpsocket;
};

#endif // RECVMSG_H
