#ifndef STUDENT_H
#define STUDENT_H
#include "config.h"
#include <QTcpSocket>

struct StudentInfo{
    //定长数据容易传输
    wchar_t id[20] = {'\0'};
    wchar_t password[20] = {'\0'};
    wchar_t name[20] = {'\0'};
    int id_len;
    int pwd_len;
    int name_len;
    QTcpSocket *socket = nullptr;//emmmmmmm
public:
    StudentInfo();
    StudentInfo(QString id,QString password,QString name);
    StudentInfo(QByteArray data){
        //untested
        *this = *(StudentInfo*)data.data();
    }
    bool operator== (StudentInfo& info){
        return this->getId() == info.getId();
    }
    QString getId() const;
    //void setId(const QString &value);
    QString getPassword() const;
    //void setPassword(const QString &value);
    QString getName() const;
    //void setName(const QString &value);

    QTcpSocket *getSocket() const;
    void setSocket(QTcpSocket *value);
    QByteArray toByteArray(){
        QByteArray res((char*)this,sizeof(*this));
        return res;
    }
};

#endif // STUDENT_H
