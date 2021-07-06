#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H

#include <QObject>
#include"message.h"
#include"studentviewhandler.h"
#include"loginviewhandler.h"
#include"login.h"
#include"error.h"
class MessageAnalyser : public QObject
{
    Q_OBJECT
public:
    explicit MessageAnalyser(QObject *parent = nullptr);
    void analyser(QByteArray bytes){
        Message message(bytes);
        Header header = message.getHeader();
        qDebug()<<"type = " + QString::number(header.getType(),16);
        QByteArray data = message.getData();
        switch(header.getType()){
        case 0x012:{
            StudentInfo* info = new StudentInfo(data);
           // qDebug()<<info->getId();
           // qDebug()<<info->getName();
           // qDebug()<<info->getPassword();
            emit studentLoginSuccessFul(info);
/*
            StudentViewHandler* hander = new StudentViewHandler();
            hander->handleStudentLoginSuccessful(data);

            Login::instance()->studentLoginSucceed();
            Login::instance()->hide();
*/
            break;
        }
        case ERROR_LOGIN_ERR::PASSWORD_ERR:
        case ERROR_LOGIN_ERR::ID_NOTFOUND_ERR:
        case ERROR_LOGIN_ERR::LOGIN_REPEATEDLY_ERR:{
            emit LoginError(header.getType());
            break;
        }

        case BROADCAST_TYPE::ADD_NEW_STUDENT:{
            StudentInfo* info = new StudentInfo(data);
            emit addNewStudent(info);
            break;
        }
        case BROADCAST_TYPE::CORRECT_ONLINENUM:{
            int num = *(int*)data.data();
            qDebug()<<"num == "  +QString::number(num);
            emit correctOnlineNum(num);
            break;
        }
        default:{

            break;
        }
        }
    }
signals:
    void studentLoginSuccessFul(StudentInfo *info = nullptr);
    void addNewStudent(StudentInfo *info);
    void LoginError(int type);
    void correctOnlineNum(int num);
public slots:
private:
};

#endif // MESSAGEANALYSER_H
