#include "messageanalyser.h"

MessageAnalyser::MessageAnalyser(Message message,QObject *parent) : QObject(parent)
{
    this->message = message;
}
