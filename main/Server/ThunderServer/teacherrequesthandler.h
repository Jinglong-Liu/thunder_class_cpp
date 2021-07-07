#ifndef TEACHERREQUESTHANDLER_H
#define TEACHERREQUESTHANDLER_H

#include <QObject>
#include"data.h"
#include"message.h"
class TeacherRequestHandler : public QObject
{
    Q_OBJECT
public:
    explicit TeacherRequestHandler(QObject *parent = nullptr);
    void broadcastMessage(QByteArray data){
        for(auto&socket:Data::instance()->getSockets()){
            Header header(BroadcastType::BroadcastMessageFromTeacher);
            Message message(header,data);
            socket->write(message.toByteArray());
        }
    }
signals:

public slots:
};

#endif // TEACHERREQUESTHANDLER_H
