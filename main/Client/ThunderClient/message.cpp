#include "message.h"

QByteArray Message::getData() const
{
    return data;
}

Header Message::getHeader() const
{
    return header;
}

Message::Message()
{

}



int Header::getHeadSize() const
{
    return headSize;
}

void Header::setHeadSize(int value)
{
    headSize = value;
}

int Header::getDataSize() const
{
    return dataSize;
}

void Header::setDataSize(int value)
{
    dataSize = value;
}

int Header::getType() const
{
    return type;
}

void Header::setType(int value)
{
    type = value;
}
