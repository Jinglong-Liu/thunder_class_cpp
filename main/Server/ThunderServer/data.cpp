#include "data.h"

Data::Data()
{
    initStudents();
}

QMap<QString, StudentInfo *> Data::getStudentTable() const
{
    return studentTable;
}

void Data::initStudents()
{
    for(int i = 1;i<=20;i++){
        StudentInfo *st = new StudentInfo(QString::number(191000000 + i),"123456",QString::number(10000 + i));
        //studentTable.insert(st->getId(),st);
        studentTable.insert(st->getId(),st);
    }
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

