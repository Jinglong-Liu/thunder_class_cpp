#ifndef STUDENTLOGOUTHANDLER_H
#define STUDENTLOGOUTHANDLER_H

#include <QObject>
#include"config.h"
#include"message.h"
#include"datahandler.h"
class LogoutHandler : public QObject
{
    Q_OBJECT
public:
    explicit LogoutHandler(QObject *parent = nullptr);
    void handle(QTcpSocket *socket){
        DataHandler* dataHandler = new DataHandler();
        dataHandler->setStudentOffline(socket);
        dataHandler->setTeacherOffline(socket);
        broadcaseOnlineNumber(Data::instance()->getOnlineNums());
    }
    void broadcaseOnlineNumber(int num){

        Header header(BroadcastType::CorrectOnlineNum);
        Message message(header);
        message.append(num);

        for(auto& s:Data::instance()->getSockets()){
            if(s->bytesAvailable() == 0){
                s->write(message.toByteArray());
                qDebug()<<"broadcaseOnlineNumber";
            }
        }
        //qDebug()<<"学生人数:"<<Data::instance()->getOnlineStudentNumber();
    }
signals:

public slots:
private:
    QSemaphore semo;
};

#endif // STUDENTLOGOUTHANDLER_H
