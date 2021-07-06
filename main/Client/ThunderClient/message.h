#ifndef MESSAGE_H
#define MESSAGE_H
#include<QByteArray>
struct Header{
    int type;
    int headSize;
    int dataSize;
public:
    Header(){}
    Header(int type){
        this->type = type;
        this->headSize = sizeof(*this);
        this->dataSize = -1;
    }
    QByteArray toByteArray(){
        return QByteArray((char*)&type,sizeof(type))
                +QByteArray((char*)&headSize,sizeof(headSize))
                +QByteArray((char*)&dataSize,sizeof(dataSize));
    }
    int getType() const;
    void setType(int value);
    int getHeadSize() const;
    void setHeadSize(int value);
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
    Message(Header header,QByteArray data = QByteArray()){
        this->header = header;
        this->data = data;
        this->header.setDataSize(data.size());
    }
    QByteArray toByteArray(){
        return header.toByteArray() + data;
    }
    void append(int x){
        this->data.append((char*)&x,sizeof(x));
        this->header.setDataSize(data.size());
    }
    void append(QString& str){
        this->data.append(str);
    }
    QByteArray getData() const;
    Header getHeader() const;
};

#endif // MESSAGE_H
