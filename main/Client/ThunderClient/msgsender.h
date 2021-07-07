#ifndef MSGSENDER_H
#define MSGSENDER_H

#include <QObject>
#include"config.h"
class MsgSender:public QObject
{
public:
    MsgSender(QTcpSocket *socket);
    //void run()override;

    void sendStudentLoginRequest(QString id,QString password);
private:
    QTcpSocket*tcpsocket;
};

#endif // MSGSENDER_H
