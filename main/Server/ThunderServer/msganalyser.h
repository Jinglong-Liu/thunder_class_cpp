#ifndef MSGANALYSER_H
#define MSGANALYSER_H

#include <QObject>
#include"config.h"
#include "datahandler.h"
/**
 * @brief The MsgAnalyser class
 * analyser message,check the type and info,then emit to data handler which will emit to sender...
 */
class MsgAnalyser : public QThread
{
    Q_OBJECT
public:
    explicit MsgAnalyser(Message message,QTcpSocket *tcpSocket,QObject *parent = nullptr);

    Message getMessage() const;
    void setMessage(const Message &value);
    void analyse();
    void run()override;
signals:
    //emit to data handler.
    void studentLoginRequest(QString id,QString password);
public slots:
private:
    Message message;
    QTcpSocket *tcpSocket;
    void handleStudentLoginRequest(QByteArray data);
};

#endif // MSGANALYSER_H
