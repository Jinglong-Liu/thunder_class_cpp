#include "msganalyser.h"

MsgAnalyser::MsgAnalyser(Message message,QObject *parent) : QThread(parent)
{
    this->message = message;
}
void MsgAnalyser::analyse()
{
    qDebug()<<"analyse..";
    Header head = message.getHeader();
    QByteArray data = message.getData();
    qDebug()<<"type == " + QString::number(head.getType(),16);
    switch (head.getType()) {
        case 0x12:{
            //学生登录成功,接下来是一个info
            StudentInfo* info = new StudentInfo();
            //socket->read((char*)info,sizeof(*info));

            info = (StudentInfo*)message.getData().data();
            qDebug()<<info->getId();
            qDebug()<<info->getName();
            qDebug()<<info->getPassword();
            emit studentLoginSuccess(info);
            break;
        }
        case 0x13:{
            //密码错误
            //emit studentLoginFail();
            break;
        }
        case 0x14:{
            //emit studentLoginNotFound();
            break;
        }
        case 0x0f000012: //学生人数+1，后面是学生信息,
        {
            qDebug()<<"get here";
/*
            StudentInfo* info = new StudentInfo();
            QByteArray m = message.mid(8);
            info = (StudentInfo*)m.data();
            emit newStudent(info);
*/
            break;
        }
    case 0x0fff0001://人数
    {
        qDebug()<<"broadcast online num";

        break;
    }
        default:
            break;
    }
}
void MsgAnalyser::run(){

}
