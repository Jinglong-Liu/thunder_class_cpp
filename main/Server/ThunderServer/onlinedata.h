#ifndef ONLINEDATA_H
#define ONLINEDATA_H
#include"data.h"
//#include"config.h"
class OnlineData
{
public:
    OnlineData();
    void addNewStudent(StudentInfo* studentInfo);
    int getOnlineStudentCount();
private:
    //QSet<QTcpSocket*>online_socket;
    //人数变化，广播到所有在线socket
    QMap<QString,StudentInfo*>online_students;
    QMap<QString,TeacherInfo*>online_teachers;

};

#endif // ONLINEDATA_H
