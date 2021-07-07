#ifndef MESSAGESENDER_H
#define MESSAGESENDER_H

#include <QObject>
#include"../config/config.h"
#include"../model/model.h"
class MessageSender : public QObject
{
    Q_OBJECT
public:
    explicit MessageSender(QTcpSocket *socket,QObject *parent = nullptr);
    void sendStudentLoginRequest(QString id,QString password){
        Header header(RequestType::StudentLogin);

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
    void sendTeacherLoginRequest(QString id,QString password){
        Header header(RequestType::TeachetLogin);
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
    void sendBroadcastMessage(QString str,Status state){
        Message message;
        if(state == Status::student){
            Header header(BroadcastType::BroadcastMessageFromStudent);
            message = Message(header);
            message.append(Mydata::instance()->getStudentInfo()->toByteArray());
        }
        else{
            Header header(BroadcastType::BroadcastMessageFromTeacher);
            message = Message(header);
            message.append(Mydata::instance()->getTeacherInfo()->toByteArray());
        }
        message.append(str);

        socket->write(message.toByteArray());
    }
signals:

public slots:
private:
    QTcpSocket *socket;
};

#endif // MESSAGESENDER_H
