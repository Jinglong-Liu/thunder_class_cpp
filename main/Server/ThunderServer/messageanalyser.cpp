#include "messageanalyser.h"

MessageAnalyser::MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent)
{
    this->message = message;
    this->socket = socket;
}

void MessageAnalyser::handleLoginRequest(Message message,Status state){
    QByteArray data = message.getData();
    int idLength = *(int*)data.mid(0,sizeof(int)).data();
    QString id = data.mid(sizeof(int),idLength);
    QString password = data.mid(sizeof(int) + idLength);
    qDebug()<<"id = " + id;//ok.
    qDebug()<<"password = " + password;//ok.
    LoginRequestHandler *s = new LoginRequestHandler();
    s->handle(socket,id,password,state);
}

void MessageAnalyser::handleBroadcastMessage(QByteArray data,Status state){
    qDebug()<<QString(data);//ok.
    if(state == Status::student){
        StudentRequestHandler *handler = new StudentRequestHandler();
        handler->broadcastMessage(data);
        handler->deleteLater();
    }
    else{
        TeacherRequestHandler *handler = new TeacherRequestHandler();
        handler->broadcastMessage(data);
        handler->deleteLater();
    }
}
