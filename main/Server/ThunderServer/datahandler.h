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

signals:

public slots:
private:
    Data *data;
};

#endif // DATAHANDLER_H
