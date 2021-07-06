#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <QObject>
#include"message.h"
#include"config.h"
class MessageSender : public QObject
{
    Q_OBJECT
public:
    explicit MessageSender(QObject *parent = nullptr);
    void send(QTcpSocket* socket,Message message){

    }
    void send(QList<QTcpSocket*>sockets, Message message);
signals:

public slots:
};

#endif // MESSAGESENDER_H
