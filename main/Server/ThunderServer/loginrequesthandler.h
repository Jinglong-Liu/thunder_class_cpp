#ifndef STUDENTLOGINREQUESTHANDLER_H
#define STUDENTLOGINREQUESTHANDLER_H

#include <QObject>
#include"datahandler.h"
#include"messagesender.h"
class LoginRequestHandler : public QObject
{
    Q_OBJECT
public:
    explicit LoginRequestHandler(QObject *parent = nullptr);
    void handle(QTcpSocket*socket,QString id,QString password,Status state){
        if(state == Status::student){
            handleStudentLoginRequest(socket,id,password);
        }
        else if(state == Status::teacher){
            handleTeacherLoginRequest(socket,id,password);
        }
    }
    void handleStudentLoginRequest(QTcpSocket*socket,QString id,QString password){
        if(!Data::instance()->getStudentTable().keys().contains(id)){
            sendLoginIdNotFound(socket,id);
        }
        else if(Data::instance()->getStudentTable().value(id)->getSocket()){
            sendLoginRepeatedly(socket,id);
        }
        else if(Data::instance()->getStudentTable().value(id)->getPassword()!=password){
            sendLoginPasswordError(socket,id);
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
    void handleTeacherLoginRequest(QTcpSocket*socket,QString id,QString password){
        if(!Data::instance()->getTeacherTable().keys().contains(id)){
            sendLoginIdNotFound(socket,id);
        }
        else if(Data::instance()->getTeacherTable().value(id)->getSocket()){
            sendLoginRepeatedly(socket,id);
        }
        else if(Data::instance()->getTeacherTable().value(id)->getPassword()!=password){
            sendLoginPasswordError(socket,id);
        }
        else{
            DataHandler* dataHandler = new DataHandler();
            dataHandler->addOnlineTeacher(socket,id);
            dataHandler->deleteLater();
            assert(Data::instance()->getTeacherSockets().contains(socket));
            sendTeacherLoginSuccessful(socket,id);
            broadcastNewTeacher(id);
            broadcaseOnlineNumber(Data::instance()->getOnlineNums());

            qDebug()<<Data::instance()->getTeacherSockets().size();
        }
    }
    void sendStudentLoginSuccessful(QTcpSocket*socket,QString id){

        Header header(ResponseType::StudentLoginSucceed);
        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        QByteArray d = info->toByteArray();
        Message m(header,d);
        //注意线程同步,这个需要最先发送!
        socket->write(m.toByteArray());
        if(socket->waitForBytesWritten()){
            semo.release();
        }
    }
    void sendTeacherLoginSuccessful(QTcpSocket*socket,QString id){

        Header header(ResponseType::TeacherLoginSucceed);
        TeacherInfo *info = Data::instance()->getTeacherTable().value(id);
        QByteArray d = info->toByteArray();
        Message m(header,d);
        //注意线程同步,这个需要最先发送!
        socket->write(m.toByteArray());
        if(socket->waitForBytesWritten()){
            semo.release();
        }
    }
    void sendLoginIdNotFound(QTcpSocket*socket,QString id);
    void sendLoginPasswordError(QTcpSocket*socket,QString id);
    void sendLoginRepeatedly(QTcpSocket*socket,QString id);

    void broadcastNewStudent(QString id){
        semo.acquire();

        StudentInfo *info = Data::instance()->getStudentTable().value(id);
        Header h(BroadcastType::AddNewStudent);
        Message message(h,info->toByteArray());

        for(auto& s:Data::instance()->getSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcastNewStudent";
            }
        }
        semo.release();
    }
    void broadcastNewTeacher(QString id){
        semo.acquire();

        TeacherInfo *info = Data::instance()->getTeacherTable().value(id);
        Header h(BroadcastType::AddNewTeacher);
        Message message(h,info->toByteArray());

        for(auto& s:Data::instance()->getSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcastNewTeacher";
            }
        }
        semo.release();
    }
    void broadcaseOnlineNumber(int num){

        semo.acquire();
        Header header(BroadcastType::CorrectOnlineNum);
        Message message(header);
        message.append(num);
        for(auto& s:Data::instance()->getSockets()){
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
