#ifndef DATA_H
#define DATA_H
#include<QtCore>
#include<QMap>
#include<QTcpSocket>
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
    int state;//0不在线，1在线
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
    int getState() const;
    void setState(int value);
};
struct TeacherInfo{
    QString id;
    QString password;
    QString name;

public:
    QString getId() const;
    void setId(const QString &value);
};
class Course{
private:
    QString courseName;
    QHash<QString,TeacherInfo*>teachers;
    QMap<QString,StudentInfo*>students;
public:

};

class Data
{
public:
    static Data* getInstance(){
        return dataInstance;
    }
    static void release(){
        if(dataInstance != nullptr){
            delete dataInstance;
            dataInstance = nullptr;
        }
    }
    QMap<QString, StudentInfo *>* getStudents() const;



    QMap<QTcpSocket *, StudentInfo *> *getOnlineStudents() const;

private:
    static Data *dataInstance;

    QMap<QString,StudentInfo*>*students;
    void initStudents();


    //QSet<QString>onlineStudentId;
    QMap<QTcpSocket*,StudentInfo*>*onlineStudents;
    //QSet<QTcpSocket*>*studentSockets;
    QTcpSocket*teacherSocket;

private:
    Data(const Data&);
    //Data& operator=(const Data&);//
    Data();
};
#endif // DATA_H
