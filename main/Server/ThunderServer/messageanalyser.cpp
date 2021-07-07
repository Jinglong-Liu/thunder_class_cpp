#include "messageanalyser.h"

MessageAnalyser::MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent)
{
    this->message = message;
    this->socket = socket;
}

void MessageAnalyser::handleStudentLoginRequest(Message message){
    QByteArray data = message.getData();
    int idLength = *(int*)data.mid(0,sizeof(int)).data();
    QString id = data.mid(sizeof(int),idLength);
    QString password = data.mid(sizeof(int) + idLength);
    qDebug()<<"id = " + id;//ok.
    qDebug()<<"password = " + password;//ok.
    StudentLoginRequestHandler *s = new StudentLoginRequestHandler();
    s->handle(socket,id,password);
}

void MessageAnalyser::handleBroadcastMessage(QByteArray data){
    qDebug()<<QString(data);//ok.
    StudentRequestHandler *handler = new StudentRequestHandler();
    handler->broadcastMessage(data);
}
