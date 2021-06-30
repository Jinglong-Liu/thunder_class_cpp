#include "analysismsg.h"
#include <QMutex>
/**
 * @brief AnalysisMsg::AnalysisMsg
 * @param parent
 *
 * @brief
 * 客户端发向服务器
 * 报文头部表面类型(4字节32位,相当于int)
 * 暂定
 * 客户端发送的报文头部标识：
 * 0x00 00 00 11:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x00 00 00 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 *
 *
 *
 */
AnalysisMsg::AnalysisMsg(QObject *parent) : QObject(parent)
{

}

void AnalysisMsg::run()
{
    //analyse different type of msg

}

void AnalysisMsg::setMessage(QByteArray message)
{
    this->message = message;
}

void AnalysisMsg::setSocket(QTcpSocket* socket)
{
    this->socket = socket;
    this->message = socket->readAll();
}

int AnalysisMsg::getHead()
{
    //socket->read((char*)head,4);
    head = QString(this->message).mid(0,4).toInt();
    return head;
}
