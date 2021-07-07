#include"../../include/model/model.h"
Mydata* Mydata::data = new Mydata();
StudentInfo *Mydata::getStudentInfo() const
{
    return studentInfo;
}

void Mydata::setStudentInfo(StudentInfo *value)
{
    studentInfo = value;
}

Mydata::Mydata(QObject *parent) : QObject(parent)
{

}
