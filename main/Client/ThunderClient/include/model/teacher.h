#ifndef TEACHER_H
#define TEACHER_H
#include "../config/config.h"
#include <QObject>
struct TeacherInfo{
    //定长数据容易传输
    wchar_t id[20] = {'\0'};
    wchar_t password[20] = {'\0'};
    wchar_t name[20] = {'\0'};
    int id_len;
    int pwd_len;
    int name_len;
    QTcpSocket *socket = nullptr;
public:
    TeacherInfo();
    TeacherInfo(QString id,QString password,QString name);
    TeacherInfo(QByteArray data);
    bool operator== (TeacherInfo& info){
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

#endif // TEACHER_H
