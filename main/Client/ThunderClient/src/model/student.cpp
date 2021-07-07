#include"../../include/model/model.h"

StudentInfo::StudentInfo()
{

}

StudentInfo::StudentInfo(QString id, QString password, QString name)
{
    this->id_len = id.toWCharArray(this->id);
    this->pwd_len = password.toWCharArray(this->password);
    this->name_len = name.toWCharArray(this->name);
}

QString StudentInfo::getId() const
{
    return QString::fromWCharArray(id);
}


QString StudentInfo::getName() const
{
    return QString::fromWCharArray(name);
}



QString StudentInfo::getPassword() const
{
    return QString::fromWCharArray(password);
}
