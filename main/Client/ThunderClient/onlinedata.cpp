#include "onlinedata.h"

OnlineData::OnlineData()
{
    onlineNum = 0;
}

int OnlineData::getOnlineNum() const
{
    return onlineNum;
}

void OnlineData::setOnlineNum(int value)
{
    onlineNum = value;
}

void OnlineData::studentOffline(StudentInfo *info)
{
    onlineNum --;
}

void OnlineData::studentOnline(StudentInfo *info)
{
    onlineNum ++;
}
