#ifndef ANALYSER_H
#define ANALYSER_H

#include"config.h"
#include"./model/student.h"
class Analyser:public QObject
{
    Q_OBJECT
public:
    Analyser();
    //Analyser(QByteArray message);
    void analyse(QByteArray message);//TODO
    //QByteArray getMessage() const;
    //void setMessage(const QByteArray &value);

signals:
    void studentLoginSucceed(StudentInfo* stuInfo);
    void studentLoginFail();//密码错误
    void studentLoginNotFound();//用户名不存在
    void teacherLoginSucceed(QString id,QString name);
    void newStudent(StudentInfo* info);//有新的学生登录
    void teacherLoginFail();
    void UpdateonlineNumber(int num);
private:
    QByteArray message;
    int head;
};

#endif // ANALYSER_H
