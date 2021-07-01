#ifndef STUDENT_H
#define STUDENT_H
#include "config.h"
#include <QTcpSocket>

struct StudentInfo{
    //定长数据容易传输
    //QString id;
    //QString password;
    //QString name;
    wchar_t id[20] = {'\0'};
    wchar_t password[20] = {'\0'};
    wchar_t name[20] = {'\0'};
    int id_len;
    int pwd_len;
    int name_len;
    int isOnline = 0;
    //sizeof() =  132
public:
    StudentInfo();
    StudentInfo(QString id,QString password,QString name);

    QString getId() const;
    //void setId(const QString &value);
    QString getPassword() const;
    //void setPassword(const QString &value);
    QString getName() const;
    //void setName(const QString &value);
};

#endif // STUDENT_H
