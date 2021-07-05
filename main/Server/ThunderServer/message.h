#ifndef MESSAGE_H
#define MESSAGE_H
#include<QByteArray>
struct Header{
    short type;
    short headSize;
    int dataSize;

public:
    short getType() const;
    void setType(short value);
    short getHeadSize() const;
    void setHeadSize(short value);
    int getDataSize() const;
    void setDataSize(int value);
};

class Message
{
    Header header;
    QByteArray data;
public:
    Message();
    Message(QByteArray message){
        this->header = *(Header*)(message.mid(0,sizeof(header)).data());
        this->data = message.mid(sizeof(header));
    }
    Message(Header header,QByteArray data){
        this->header = header;
        this->data = data;
    }
    QByteArray getData() const;
    Header getHeader() const;
};

#endif // MESSAGE_H
