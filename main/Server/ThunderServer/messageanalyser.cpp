#include "messageanalyser.h"

MessageAnalyser::MessageAnalyser(Message message,QTcpSocket *socket,QObject *parent)
{
    this->message = message;
    this->socket = socket;
}
