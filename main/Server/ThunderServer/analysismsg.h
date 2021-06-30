#ifndef ANALYSISMSG_H
#define ANALYSISMSG_H

#include <QObject>
#include"config.h"
/**
 * @brief The AnalysisMsg class
 * 分析信息，得到转发信息和转发对象
 * 转发对象大致有以下情况：
 * 0、不必发送
 * 1、发给发出socket的人发送信息的socket(登录，修改信息)
 * 2、发给所有socket：聊天，发布测试题
 * 3、发给指定socket：发给教师或满足一定条件的学生：教师学生可以用id区分，信息保存在服务端
 */
class AnalysisMsg : public QObject,QRunnable
{
    Q_OBJECT
public:
    explicit AnalysisMsg(QObject *parent = nullptr);
    void run()override;
    void setMessage(QByteArray message);
    void setSocket(QTcpSocket *socket);
    int getHead();
signals:

public slots:
private:
    QByteArray message;
    QTcpSocket *socket;
    const int headLength = 4;
    int head;//4字节
    //QTcpSocket
    //tcpSocket->read((char*)&total,4);
};

#endif // ANALYSISMSG_H