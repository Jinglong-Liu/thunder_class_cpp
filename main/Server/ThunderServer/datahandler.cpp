#include "datahandler.h"

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    this->data = Data::instance();
}
