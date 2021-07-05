#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H
#include"message.h"
#include<QObject>
#include<QRunnable>
#include<QtCore>
class MessageAnalyser: public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MessageAnalyser(Message message,QObject *parent = nullptr);
    void analyse(){
        short type = message.getHeader().getType();
        switch(type){
        case 0x12:{
            handleStudentLoginRequest(message);
            break;
        }
        default:{
            qDebug()<<"type == " + QString::number(type);
        }
        }
    }
    void run()override{
        analyse();
    }
private:
    Message message;
    void handleStudentLoginRequest(Message message){
        QByteArray data = message.getData();
        int idLength = *(int*)data.mid(0,sizeof(int)).data();
        QString id = data.mid(sizeof(int),idLength);
        QString password = data.mid(sizeof(int) + idLength);
        qDebug()<<"id = " + id;
        qDebug()<<"password = " + password;
    }
};

#endif // MESSAGEANALYSER_H
