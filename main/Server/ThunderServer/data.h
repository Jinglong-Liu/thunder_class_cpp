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
    QTcpSocket *socket = nullptr;//emmmmmmm
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
    QTcpSocket *getSocket() const;
    void setSocket(QTcpSocket *value);
    QByteArray toByteArray(){
        QByteArray res((char*)this,sizeof(*this));
        return res;
    }
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
    QList<QTcpSocket*> getStudentSockets(){
        QList<QTcpSocket*>res;
        studentSocketsMutex.lock();
        for(auto& info:studentTable.values()){
            if(info->getSocket()!=nullptr){
                res.push_back(info->getSocket());
            }
        }
        studentSocketsMutex.unlock();
        return res;
    }
    void setStudentOnline(QTcpSocket *socket,QString id){
        studentTableMutex.lock();
        for(QString _id:studentTable.keys()){
            if(_id == id){
                studentTable.value(_id)->setSocket(socket);
            }
        }
        studentTableMutex.unlock();
    }
    void setStudentOffline(QTcpSocket *socket,StudentInfo*info){
        studentTableMutex.lock();
        for(QString id:studentTable.keys()){
            if(id == info->id){
                studentTable.value(id)->setSocket(nullptr);
            }
        }
        studentTableMutex.unlock();
    }
    void setStudentOffline(QTcpSocket *socket){
        for(auto &info:studentTable.values()){
            if(socket == info->socket){
                info->setSocket(nullptr);
                qDebug()<<"a student off line";
            }
        }
    }
    int getOnlineStudentNumber()const{
        int count = 0;
        for(auto info:studentTable.values()){
            if(info->getSocket()!=nullptr){
                count++;
            }
        }
        return count;
    }
    QList<QTcpSocket*> getSocketsExcepted(QString id);
    int getOnlineNums(){
        int ret = 0;
        for(auto info:studentTable.values()){
            if(info->getSocket()!=nullptr){
                ret++;
            }
        }
        return ret;
    }
    //教师还没有加上
    QList<QTcpSocket*>getSockets(){
        QList<QTcpSocket*>list = getStudentSockets();
        return list;
    }
private:
    Data();
    QMap<QString,StudentInfo*>studentTable;
    QMutex studentTableMutex;
    QMutex studentSocketsMutex;

    void initStudents();
    static Data* data;

};

#endif // DATA_H
