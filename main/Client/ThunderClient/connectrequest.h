#ifndef CONNECTREQUEST_H
#define CONNECTREQUEST_H

#include <QObject>
#include<config.h>
class ConnectRequest:public QObject,public QRunnable
{
    Q_OBJECT
public:
    ConnectRequest();
    void run()override;
    void recvAddr(QString ip,unsigned short port);
    QTcpSocket* getSocket();
private:
    QString ip;
    unsigned short port;
    QTcpSocket* socket;
};

#endif // CONNECTREQUEST_H
