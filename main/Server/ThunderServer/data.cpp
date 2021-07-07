#include "data.h"
Data* Data::data = new Data();
Data::Data()
{
    initStudents();
    initTeachers();
}

QMap<QString, TeacherInfo *> Data::getTeacherTable() const
{
    return teacherTable;
}

QMap<QString, StudentInfo *> Data::getStudentTable() const
{
    return studentTable;
}

QList<QTcpSocket *> Data::getSocketsExcepted(QString id){
    QList<QTcpSocket*>ret;
    for(auto _id:studentTable.keys()){
        if(_id == id || studentTable.value(_id)->getSocket() == nullptr){
            continue;
        }
        ret.append(studentTable.value(_id)->getSocket());
    }
    //teacher?
    return ret;
}


void Data::initStudents()
{
    for(int i = 1;i<=20;i++){
        StudentInfo *st = new StudentInfo(QString::number(191000000 + i),"123456",QString::number(10000 + i));
        studentTable.insert(st->getId(),st);
    }
}

void Data::initTeachers()
{
    TeacherInfo *ta = new TeacherInfo(QString::number(10001),"123456","teacher a");
    TeacherInfo *tb = new TeacherInfo(QString::number(10002),"123456","teacher b");
    teacherTable.insert(ta->getId(),ta);
    teacherTable.insert(tb->getId(),tb);
}

QTcpSocket *StudentInfo::getSocket() const
{
    return socket;
}

void StudentInfo::setSocket(QTcpSocket *value)
{
    socket = value;
}

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

TeacherInfo::TeacherInfo(QByteArray data){
    *this = *(TeacherInfo*)data.data();
}
QTcpSocket *TeacherInfo::getSocket() const
{
    return socket;
}

void TeacherInfo::setSocket(QTcpSocket *value)
{
    socket = value;
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
