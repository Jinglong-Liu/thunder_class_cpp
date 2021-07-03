#ifndef MSGRECEVIER_H
#define MSGRECEVIER_H

#include <QObject>
#include"msganalyser.h"
#include"config.h"
//只运行一次就销毁
class MsgRecevier : public QThread
{
    Q_OBJECT
public:
    //explicit MsgRecevier(QObject *parent = nullptr);
    explicit MsgRecevier(QTcpSocket* socket,QObject *parent = nullptr);
    void receive();
    void run()override;
signals:

public slots:

private:
    QTcpSocket *socket;
    MsgAnalyser *analyser;
};

#endif // MSGRECEVIER_H
