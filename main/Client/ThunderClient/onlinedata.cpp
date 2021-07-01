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
