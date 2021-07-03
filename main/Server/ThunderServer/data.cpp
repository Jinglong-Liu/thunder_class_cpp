#include "data.h"
Data *Data::dataInstance = new Data();

void Data::initStudents()
{

    for(int i = 1;i<=20;i++){
        StudentInfo *st = new StudentInfo(QString::number(191000000 + i),"123456",QString::number(10000 + i));
        //studentTable.insert(st->getId(),st);
        students->insert(st->getId(),st);
    }
}

QMap<QTcpSocket *, StudentInfo *> *Data::getOnlineStudents() const
{
    return onlineStudents;
}


Data::Data()
{
    students = new QMap<QString,StudentInfo*>();
    onlineStudents = new QMap<QTcpSocket*,StudentInfo*>();
    teacherSocket = new QTcpSocket();
    initStudents();
}


QMap<QString, StudentInfo *>* Data::getStudents() const
{
    return students;
}

int StudentInfo::getState() const
{
    return state;
}

void StudentInfo::setState(int value)
{
    state = value;
}

StudentInfo::StudentInfo()
{

}

StudentInfo::StudentInfo(QString id, QString password, QString name)
{
    this->id_len = id.toWCharArray(this->id);
    this->pwd_len = password.toWCharArray(this->password);
    this->name_len = name.toWCharArray(this->name);
}

QString StudentInfo::getId() const
{
    return QString::fromWCharArray(id);
}


QString StudentInfo::getName() const
{
    return QString::fromWCharArray(name);
}

QString StudentInfo::getPassword() const
{
    return QString::fromWCharArray(password);
}

