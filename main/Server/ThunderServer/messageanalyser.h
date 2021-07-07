#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H
#include"message.h"
#include<QObject>
#include<QRunnable>
#include<QtCore>
#include"datahandler.h"
#include"studentloginrequesthandler.h"
class MessageAnalyser: public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent = nullptr);
    void analyse(){
        int type = message.getHeader().getType();
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
    QTcpSocket *socket;
    void handleStudentLoginRequest(Message message){
        QByteArray data = message.getData();
        int idLength = *(int*)data.mid(0,sizeof(int)).data();
        QString id = data.mid(sizeof(int),idLength);
        QString password = data.mid(sizeof(int) + idLength);
        qDebug()<<"id = " + id;//ok.
        qDebug()<<"password = " + password;//ok.
        StudentLoginRequestHandler *s = new StudentLoginRequestHandler();
        s->handle(socket,id,password);
    }

};

#endif // MESSAGEANALYSER_H
