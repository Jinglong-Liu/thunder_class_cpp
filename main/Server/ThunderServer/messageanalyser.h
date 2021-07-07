#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H
#include"message.h"
#include<QObject>
#include<QRunnable>
#include<QtCore>
#include"datahandler.h"
#include"error.h"
#include"loginrequesthandler.h"
#include"studentrequesthandler.h"
#include"teacherrequesthandler.h"
class MessageAnalyser: public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent = nullptr);
    void analyse(){
        int type = message.getHeader().getType();
        qDebug()<<"type == " + QString::number(type,16);
        switch(type){
        case RequestType::StudentLogin:{
            handleLoginRequest(message,Status::student);
            break;
        }
        case RequestType::TeachetLogin:{
            handleLoginRequest(message,Status::teacher);
            break;
        }
        case BroadcastType::BroadcastMessageFromStudent:{
            handleBroadcastMessage(message.getData(),Status::student);
            break;
        }
        case BroadcastType::BroadcastMessageFromTeacher:{
            handleBroadcastMessage(message.getData(),Status::teacher);
            break;
        }
        default:{
            //todo
        }
        }
    }
    void run()override{
        analyse();
    }
private:
    Message message;
    QTcpSocket *socket;
    void handleLoginRequest(Message message,Status state);
    void handleBroadcastMessage(QByteArray data,Status state);
};

#endif // MESSAGEANALYSER_H
