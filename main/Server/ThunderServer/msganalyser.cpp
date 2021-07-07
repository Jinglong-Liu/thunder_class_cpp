#include "msganalyser.h"


MsgAnalyser::MsgAnalyser(Message message,QTcpSocket *tcpSocket,QObject *parent)
{
    this->message = message;

    this->tcpSocket = tcpSocket;
    DataHandler* handler = new DataHandler(tcpSocket);
    connect(this,&MsgAnalyser::studentLoginRequest,handler,&DataHandler::handleStudentLoginRequest);
    //connect....................
}

Message MsgAnalyser::getMessage() const
{
    return message;
}

void MsgAnalyser::setMessage(const Message &value)
{
    message = value;
}

void MsgAnalyser::analyse()
{

    qDebug()<<"analyser";
    Header head = message.getHeader();
    short type = head.getType();
    QByteArray data = message.getData();
    //switch type....
    //qDebug()<<"type = " + QString::number(type);
    //qDebug()<<"data = " + data;
    switch(type){
    case 0x12:{
        handleStudentLoginRequest(data);
        break;
    }
    default:{
        break;
    }
    }
}

void MsgAnalyser::run()
{
    analyse();
}

void MsgAnalyser::handleStudentLoginRequest(QByteArray data)
{
    //
    int idLength = *(int*)data.mid(0,4).data();
    QString id = data.mid(4,idLength);
    QString password = data.mid(4+idLength);
    qDebug()<<"id = " + id;
    qDebug()<<"password = " + password;
    emit studentLoginRequest(id,password);
}
