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
            qDebug()<<"check the id and try again!";
        }
        else if(Data::instance()->getStudentTable().value(id)->getSocket()){
            qDebug()<<"you have login... don't login again";
        }
        else if(Data::instance()->getStudentTable().value(id)->getPassword()!=password){
            qDebug()<<"password error";
        }
        else{
            //succeed
            DataHandler* dataHandler = new DataHandler();
            dataHandler->addOnlineStudent(socket,id);
            dataHandler->deleteLater();

            sendStudentLoginSuccessful(socket,id);

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

        Header h2(0x0f12);
        Message m2(h2,info->toByteArray());
        for(QTcpSocket* s:Data::instance()->getStudentSockets()){
            socket->write(m2.toByteArray());
        }

        DataHandler* handler = new DataHandler();
        handler->addOnlineStudent(socket,id);
    }
signals:

public slots:
};

#endif // STUDENTLOGINREQUESTHANDLER_H
