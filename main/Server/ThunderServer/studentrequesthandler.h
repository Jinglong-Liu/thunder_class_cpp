#ifndef STUDENTREQUESTHANDLER_H
#define STUDENTREQUESTHANDLER_H

#include <QObject>
#include"data.h"
#include"message.h"
class StudentRequestHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentRequestHandler(QObject *parent = nullptr);
    void broadcastMessage(QByteArray data){
        for(auto&socket:Data::instance()->getSockets()){
            Header header(BROADCAST_TYPE::BROADCAST_MESSAGE);
            Message message(header,data);
            socket->write(message.toByteArray());
        }
    }
signals:

public slots:
};

#endif // STUDENTREQUESTHANDLER_H
