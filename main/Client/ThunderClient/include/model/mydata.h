#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include"student.h"
#include"teacher.h"
class Mydata : public QObject
{
    Q_OBJECT
public:
    static Mydata* instance(){
        return data;
    }
    StudentInfo *getStudentInfo() const;
    void setStudentInfo(StudentInfo *value);

    TeacherInfo *getTeacherInfo() const;
    void setTeacherInfo(TeacherInfo *value);

signals:

public slots:
private:
    static Mydata* data;
    StudentInfo *studentInfo;
    TeacherInfo *teacherInfo;
    explicit Mydata(QObject *parent = nullptr);
};

#endif // MYDATA_H
