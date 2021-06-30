#ifndef STUDENT_H
#define STUDENT_H
#include "config.h"
#include <QTcpSocket>
class Student
{
private:
    QString id;
    QString password;
    QString name;
    QTcpSocket* socket;
public:
    Student();
    void sendMsg(QString msg);
    bool login();
};

#endif // STUDENT_H
