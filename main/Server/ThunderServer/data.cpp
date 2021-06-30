#include "data.h"

Data::Data()
{

}

QString StudentInfo::getId() const
{
    return id;
}

void StudentInfo::setId(const QString &value)
{
    id = value;
}

QString StudentInfo::getName() const
{
    return name;
}

void StudentInfo::setName(const QString &value)
{
    name = value;
}

QString StudentInfo::getPassword() const
{
    return password;
}

void StudentInfo::setPassword(const QString &value)
{
    password = value;
}
