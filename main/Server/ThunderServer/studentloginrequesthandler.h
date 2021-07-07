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
            assert(Data::instance()->getStudentSockets().contains(socket));
            sendStudentLoginSuccessful(socket,id);
            broadcastNewStudent(id);
            broadcaseOnlineNumber(Data::instance()->getOnlineNums());

            qDebug()<<Data::instance()->getStudentSockets().size();
        }
    }
    void sendStudentLoginSuccessful(QTcpSocket*socket,QString id){

        Header header(0x12);
        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        QByteArray d = info->toByteArray();
        Message m(header,d);
        //注意线程同步,这个需要最先发送!
        socket->write(m.toByteArray());
        if(socket->waitForBytesWritten()){
            semo.release();
        }
    }
    void sendStudentLoginIdNotFound(QTcpSocket*socket,QString id);
    void sendStudentLoginPasswordError(QTcpSocket*socket,QString id);
    void sendStudentLoginRepeatedly(QTcpSocket*socket,QString id);

    void broadcastNewStudent(QString id){
        semo.acquire();

        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        Header h(BROADCAST_TYPE::ADD_NEW_STUDENT);
        Message message(h,info->toByteArray());

        for(auto& s:Data::instance()->getStudentSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcastNewStudent";
            }
        }

        semo.release();
    }
    void broadcaseOnlineNumber(int num){

        semo.acquire();
        Header header(BROADCAST_TYPE::CORRECT_ONLINENUM);
        Message message(header);
        message.append(num);
        for(auto& s:Data::instance()->getStudentSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcaseOnlineNumber";
            }
        }
        qDebug()<<"学生人数:"<<Data::instance()->getOnlineStudentNumber();
        semo.release();
    }
signals:

public slots:
private:
    QMutex mutex;
    QSemaphore semo;

};

#endif // STUDENTLOGINREQUESTHANDLER_H
