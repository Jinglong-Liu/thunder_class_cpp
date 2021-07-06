#ifndef STUDENTLOGINREQUESTHANDLER_H
#define STUDENTLOGINREQUESTHANDLER_H

#include <QObject>
#include"datahandler.h"
#include"messagesender.h"
class StudentLoginRequestHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentLoginRequestHandler(QObject *parent = nullptr);
    void handle(QTcpSocket*socket,QString id,QString password){
        if(!Data::instance()->getStudentTable().keys().contains(id)){
            sendStudentLoginIdNotFound(socket,id);
        }
        else if(Data::instance()->getStudentTable().value(id)->getSocket()){
            sendStudentLoginRepeatedly(socket,id);
        }
        else if(Data::instance()->getStudentTable().value(id)->getPassword()!=password){
            sendStudentLoginPasswordError(socket,id);
        }
        else{
            //succeed
            DataHandler* dataHandler = new DataHandler();
            dataHandler->addOnlineStudent(socket,id);
            dataHandler->deleteLater();

            sendStudentLoginSuccessful(socket,id);
            broadcastNewStudent(id);
            //
            DataHandler* handler = new DataHandler();
            handler->addOnlineStudent(socket,id);
            handler->deleteLater();
            //send and broadcast
        }
    }
    void sendStudentLoginSuccessful(QTcpSocket*socket,QString id){
        //Message message;
        Header header(0x12);
        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        QByteArray d = info->toByteArray();
        Message m(header,d);
        socket->write(m.toByteArray());
    }
    void sendStudentLoginIdNotFound(QTcpSocket*socket,QString id);
    void sendStudentLoginPasswordError(QTcpSocket*socket,QString id);
    void sendStudentLoginRepeatedly(QTcpSocket*socket,QString id);

    void broadcastNewStudent(QString id){
        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        Header h(BROADCAST_TYPE::ADD_NEW_STUDENT);
        Message message(h,info->toByteArray());
        for(QTcpSocket* s:Data::instance()->getSocketsExcepted(id)){
            qDebug()<<"emm";
            s->write(message.toByteArray());
        }
    }
signals:

public slots:
};

#endif // STUDENTLOGINREQUESTHANDLER_H
