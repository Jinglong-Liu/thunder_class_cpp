#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H
#include"message.h"
#include<QObject>
#include<QRunnable>
#include<QtCore>
#include"datahandler.h"
#include"error.h"
#include"studentloginrequesthandler.h"
#include"studentrequesthandler.h"
class MessageAnalyser: public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent = nullptr);
    void analyse(){
        int type = message.getHeader().getType();
        qDebug()<<"type == " + QString::number(type,16);
        switch(type){
        case 0x12:{
            handleStudentLoginRequest(message);
            break;
        }
        case BROADCAST_TYPE::BROADCAST_MESSAGE:{
            handleBroadcastMessage(message.getData());
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
    void handleStudentLoginRequest(Message message);
    void handleBroadcastMessage(QByteArray data);
};

#endif // MESSAGEANALYSER_H
