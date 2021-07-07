#ifndef CONNECTREQUEST_H
#define CONNECTREQUEST_H

#include <QObject>
#include "../config/config.h"
class ConnectRequest:public QObject,public QRunnable
{
    Q_OBJECT
public:
    ConnectRequest();
    ConnectRequest(QTcpSocket* socket);
    void run()override;
    void recvAddr(QString ip,unsigned short port);
    void doConnectRequest(QString ip,unsigned short port);
    QTcpSocket* getSocket();
private:
    QString ip;
    unsigned short port;
    QTcpSocket* socket;
};

#endif // CONNECTREQUEST_H
