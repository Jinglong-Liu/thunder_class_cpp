#ifndef DATA_H
#define DATA_H
#include<QtCore>
#include<QMap>
#include"config.h"
struct StudentInfo{
    //定长数据容易传输
    wchar_t id[20] = {'\0'};
    wchar_t password[20] = {'\0'};
    wchar_t name[20] = {'\0'};
    int id_len;
    int pwd_len;
    int name_len;
    QTcpSocket *socket = nullptr;
public:
    StudentInfo();
    StudentInfo(QString id,QString password,QString name);
    bool operator== (StudentInfo& info){
        return this->getId() == info.getId();
    }
    QString getId() const;
    //void setId(const QString &value);
    QString getPassword() const;
    //void setPassword(const QString &value);
    QString getName() const;
    //void setName(const QString &value);
    int getState() const;
    void setState(int value);
    QTcpSocket *getSocket() const;
    void setSocket(QTcpSocket *value);
};
struct TeacherInfo{
    QString id;
    QString password;
    QString name;

public:
    QString getId() const;
    void setId(const QString &value);
};

class Data
{
public:
    static Data* instance(){
        return data;
    }
    QMap<QString, StudentInfo *> getStudentTable() const;
private:
    Data();
    QMap<QString,StudentInfo*>studentTable;
    QMutex studentTableMutex;
    QMap<StudentInfo,QTcpSocket*>studentSockets;
    QMutex studentSocketsMutex;

    void initStudents();
    static Data* data;

};

#endif // DATA_H
