#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H

#include <QObject>
#include"studentviewhandler.h"
#include"loginviewhandler.h"
#include"error.h"
#include"../config/config.h"

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
            Mydata::instance()->setStudentInfo(info);
            emit studentLoginSuccessFul(info);
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
            emit correctOnlineNum(num);
            break;
        }
        case BROADCAST_TYPE::BROADCAST_MESSAGE:{
            StudentInfo info(data.mid(0,sizeof(StudentInfo)));
            QString stu = info.getName() + "  " + QTime::currentTime().toString() + "\n";
            QString text(data.mid(sizeof(StudentInfo)));
            QString ret = stu + text;
            emit appendText(ret);

            //在ui显示
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
    void appendText(QString str);
public slots:
private:
    //QQueue<QByteArray>MessageQueue;
public:

};

#endif // MESSAGEANALYSER_H
