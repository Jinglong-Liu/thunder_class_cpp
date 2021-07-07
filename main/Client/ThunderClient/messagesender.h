#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <QObject>
#include"config.h"
#include"message.h"
#include"mydata.h"
class MessageSender : public QObject
{
    Q_OBJECT
public:
    explicit MessageSender(QTcpSocket *socket,QObject *parent = nullptr);
    void sendStudentLoginRequest(QString id,QString password){
        Header header(0x12);

        int idLength = id.length();
        Message message(header);
        message.append(idLength);
        message.append(id);
        message.append(password);
        QByteArray array = message.toByteArray();
        qDebug()<<array;
        qDebug()<<QString(array);
        socket->write(message.toByteArray());
    }
    void sendBroadcastMessage(QString str){
        Header header(BROADCAST_TYPE::BROADCAST_MESSAGE);
        Message message(header);
        message.append(Mydata::instance()->getStudentInfo()->toByteArray());
        message.append(str);

        socket->write(message.toByteArray());
    }
signals:

public slots:
private:
    QTcpSocket *socket;
};

#endif // MESSAGESENDER_H
