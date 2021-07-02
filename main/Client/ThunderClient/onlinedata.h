#ifndef ONLINEDATA_H
#define ONLINEDATA_H

#include"./model/student.h"
class OnlineData
{
public:
    OnlineData();
    int getOnlineNum() const;
    void setOnlineNum(int value);
    void studentOnline(StudentInfo *info);
    void studentOffline(StudentInfo* info);
    //void setStudentInfo(StudentInfo* info);
private:
    int onlineNum;
};

#endif // ONLINEDATA_H
