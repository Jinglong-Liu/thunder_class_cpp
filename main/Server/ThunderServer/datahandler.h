#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include"data.h"
class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr);
    void addOnlineStudent(QTcpSocket*socket,QString id){
        Data::instance()->setStudentOnline(socket,id);
    }
    void setStudentOffline(QTcpSocket *socket){
        Data::instance()->setStudentOffline(socket);
    }
    //unused
    void addOnlineTeacher(QTcpSocket*socket,QString id){
        Data::instance()->setTeacherOnline(socket,id);
    }
    void setTeacherOffline(QTcpSocket *socket){
        Data::instance()->setTeacherOffline(socket);
    }
signals:

public slots:
private:
    Data *data;
};

#endif // DATAHANDLER_H
