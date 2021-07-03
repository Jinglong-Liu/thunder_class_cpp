#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include"data.h"
#include"msgsender.h"
class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QTcpSocket* socket,QObject *parent = nullptr);
    void handleStudentLoginRequest(QString id,QString password);
signals:

public slots:
private:
    Data *data;
    MsgSender *sender;
    QTcpSocket *socket;
};

#endif // DATAHANDLER_H
