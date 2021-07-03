#ifndef MSGRECEIVER_H
#define MSGRECEIVER_H

#include <QObject>
#include"config.h"
#include<QThread>
#include"msganalyser.h"
class MsgReceiver : public QThread
{
    Q_OBJECT
public:
    //explicit MsgRecevier(QObject *parent = nullptr);
    explicit MsgReceiver(QTcpSocket* socket,QObject *parent = nullptr);
    Message receive();
    void run()override;
signals:

public slots:

private:
    QTcpSocket *socket;
    //Analyser *analyser;
};
#endif // MSGRECEIVER_H
