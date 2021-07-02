#include "onlinedata.h"

OnlineData::OnlineData()
{

}
void OnlineData::addNewStudent(StudentInfo *studentInfo)
{
    this->online_students.insert(studentInfo->getId(),studentInfo);
}

int OnlineData::getOnlineStudentCount(){
    return online_students.size();
}
