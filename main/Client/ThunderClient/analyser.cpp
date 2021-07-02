#include "analyser.h"

Analyser::Analyser()
{

}
/*
Analyser::Analyser(QByteArray message)
{
    this->message = message;
    this->head = Util::toUint32_t(message,0,8);
}
*/
void Analyser::analyse(QByteArray message)
{
    qDebug()<<"analyse..";
    this->head = Util::toUint32_t(message,0,8);
    qDebug()<<"head == " + QString::number(head,16);
    switch (this->head) {
        case 0x12:{
            //学生登录成功,接下来是一个info
            StudentInfo* info = new StudentInfo();
            //socket->read((char*)info,sizeof(*info));
            QByteArray m = message.mid(8);
            info = (StudentInfo*)m.data();
            qDebug()<<info->getId();
            qDebug()<<info->getName();
            qDebug()<<info->getPassword();
            emit studentLoginSucceed(info);
            break;
        }
        case 0x13:{
            //密码错误
            emit studentLoginFail();
            break;
        }
        case 0x14:{
            emit studentLoginNotFound();
            break;
        }
        case 0x0f000012: //学生人数+1，后面是学生信息,
        {
            qDebug()<<"get here";

            StudentInfo* info = new StudentInfo();
            QByteArray m = message.mid(8);
            info = (StudentInfo*)m.data();
            emit newStudent(info);

            break;
        }
        default:
            break;
    }
}
/*
QByteArray Analyser::getMessage() const
{
    return message;
}

void Analyser::setMessage(const QByteArray &value)
{
    message = value;
    this->head = Util::toUint32_t(message,0,8);
}*/
