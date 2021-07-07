#include "../../include/model/teacher.h"


TeacherInfo::TeacherInfo(QByteArray data){
    *this = *(TeacherInfo*)data.data();
}
TeacherInfo::TeacherInfo()
{

}

TeacherInfo::TeacherInfo(QString id, QString password, QString name)
{
    this->id_len = id.toWCharArray(this->id);
    this->pwd_len = password.toWCharArray(this->password);
    this->name_len = name.toWCharArray(this->name);
}

QString TeacherInfo::getId() const
{
    return QString::fromWCharArray(id);
}


QString TeacherInfo::getName() const
{
    return QString::fromWCharArray(name);
}



QString TeacherInfo::getPassword() const
{
    return QString::fromWCharArray(password);
}
