#include "msgsender.h"

MsgSender::MsgSender(QTcpSocket *socket)
{
    this->tcpsocket = socket;
}


void MsgSender::sendStudentLoginRequest(QString id, QString password)
{
    //向服务器发送请求
    //学生登录请求报文：0x12 + id_len + id + password
    //解析为18,我需要的是0x0012
    uint32_t head = 0x12;
    uint32_t id_len = id.length();

    QByteArray msg = Util::toHexByteArray(head)
            + Util::toHexByteArray(id_len)
            + id.toUtf8()
            + password.toUtf8();

    tcpsocket->write(msg);//

}
