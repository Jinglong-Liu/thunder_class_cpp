#ifndef STUDENTLOGOUTHANDLER_H
#define STUDENTLOGOUTHANDLER_H

#include <QObject>
#include"config.h"
#include"message.h"
#include"datahandler.h"
class StudentLogoutHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentLogoutHandler(QObject *parent = nullptr);
    void handle(QTcpSocket *socket){
        DataHandler* dataHandler = new DataHandler();
        dataHandler->setStudentOffline(socket);

        broadcaseOnlineNumber(Data::instance()->getOnlineNums());
    }
    void broadcaseOnlineNumber(int num){

        Header header(BROADCAST_TYPE::CORRECT_ONLINENUM);
        Message message(header);
        message.append(num);

        for(auto& s:Data::instance()->getStudentSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcaseOnlineNumber";
            }
        }
        qDebug()<<"学生人数:"<<Data::instance()->getOnlineStudentNumber();
    }
signals:

public slots:
private:
    QSemaphore semo;
};

#endif // STUDENTLOGOUTHANDLER_H
