#include"../../include/control/messagesender.h"
MessageSender::MessageSender(QTcpSocket *socket,QObject *parent) : QObject(parent)
{
    this->socket = socket;
}
