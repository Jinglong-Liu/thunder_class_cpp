#include "datahandler.h"

DataHandler::DataHandler(QTcpSocket* socket,QObject *parent)
{
    this->data = Data::getInstance();
    this->sender = new MsgSender();
    this->socket = socket;
    //connect to sender
    //connect()
}

void DataHandler::handleStudentLoginRequest(QString id, QString password)
{
    //sender->sendStudentLoginSuccess();
    //run here.
    if(!data->getStudents()->contains(id)){
        qDebug()<<"can't match id";
        //emit
    }
    else if(data->getOnlineStudents()->contains(socket)){
        qDebug()<<"you have already login...";
        //emit
    }
    else if(data->getStudents()->value(id)->getPassword()!=password){
        qDebug()<<"password error";
        //
    }
    else{
        data->getOnlineStudents()->insert(socket,data->getInstance()->getStudents()->value(id));
        //成功：发送给本人；并广播给全部
        qDebug()<<"login success";
    }
}
