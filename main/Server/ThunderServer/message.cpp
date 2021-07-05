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

short Header::getHeadSize() const
{
    return headSize;
}

void Header::setHeadSize(short value)
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

short Header::getType() const
{
    return type;
}

void Header::setType(short value)
{
    type = value;
}
