#ifndef MYDATA_H
#define MYDATA_H

#include <QObject>
#include"student.h"
class Mydata : public QObject
{
    Q_OBJECT
public:
    static Mydata* instance(){
        return data;
    }
    StudentInfo *getStudentInfo() const;
    void setStudentInfo(StudentInfo *value);

signals:

public slots:
private:
    static Mydata* data;
    StudentInfo *studentInfo;

    explicit Mydata(QObject *parent = nullptr);
};

#endif // MYDATA_H
