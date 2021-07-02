#ifndef MSGSENDER_H
#define MSGSENDER_H

#include <QObject>
#include"config.h"
class MsgSender : public QObject
{
    Q_OBJECT
public:
    explicit MsgSender(QObject *parent = nullptr);
    void broadcastToAll();
    void broadcastToAllStudents();
    void broadcastOnlineNum(int num);
    void send(Prepare p);
signals:

public slots:
private:
    QTcpServer *tcpServer;
};

#endif // MSGSENDER_H
