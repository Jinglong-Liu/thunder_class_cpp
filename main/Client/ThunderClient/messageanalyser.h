#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H

#include <QObject>
#include"message.h"
#include"studentviewhandler.h"
#include"login.h"
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
            //该学生登录成功
            //
            //
            StudentInfo* info = new StudentInfo(data);
            qDebug()<<info->getId();
            qDebug()<<info->getName();
            qDebug()<<info->getPassword();
            emit studentLoginSuccessFul(info);
/*
            StudentViewHandler* hander = new StudentViewHandler();
            hander->handleStudentLoginSuccessful(data);

            Login::instance()->studentLoginSucceed();
            Login::instance()->hide();
*/
            break;
        }
        case 0x0f12:{
            break;
        }
        default:{
            break;
        }
        }
    }
signals:
    void studentLoginSuccessFul(StudentInfo *info = nullptr);
public slots:
private:
    Message message;
};

#endif // MESSAGEANALYSER_H
