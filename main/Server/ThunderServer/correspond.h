#ifndef CORRESPOND_H
#define CORRESPOND_H

#include<QTcpServer>
#include<QTcpSocket>
#include <QMainWindow>
#include<QRunnable>
#include"data.h"
#include"config.h"
class Correspond: public QObject,public QRunnable
{
    Q_OBJECT
public:
    Correspond();
    Correspond(Data *data);
    void startListen(QString ip,unsigned short port);
    void run()override;
    void recvAddr(QString ip,unsigned short port);
private:
    QString ip;
    unsigned short port;
    QTcpServer* server;
    QSet<QTcpSocket*>sockets;
    Data *data;
signals:
    void online_num(int num);
};

#endif // CORRESPOND_H
