#ifndef DATA_H
#define DATA_H
#include<QtCore>
struct StudentInfo{
    QString id;
    QString password;
    QString name;
public:
    StudentInfo();
    StudentInfo(QString id,QString password,QString name);

    QString getId() const;
    void setId(const QString &value);
    QString getPassword() const;
    void setPassword(const QString &value);
    QString getName() const;
    void setName(const QString &value);
};
struct TeacherInfo{
    int id;
    QString password;
    QString name;
};
class Course{
private:
    QString courseName;
    QHash<QString,TeacherInfo>teachers;
    QMap<QString,StudentInfo>students;
public:

};

class Data
{
public:
    Data();
private:
    QMap<int,StudentInfo>studentTable;
};

#endif // DATA_H
