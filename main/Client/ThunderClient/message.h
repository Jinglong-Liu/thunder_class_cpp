#ifndef MESSAGE_H
#define MESSAGE_H
#include<QByteArray>
#include <QList>
#include<QDebug>
#include"error.h"
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
    //解析
    Message(QByteArray message){
        this->header = *(Header*)(message.mid(0,sizeof(header)).data());
        this->data = message.mid(sizeof(header));
    }
    //发送
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
        this->header.setDataSize(data.size());
    }
    void append(QByteArray byte){
        this->data.append(byte);
        this->header.setDataSize(data.size());
    }
    QByteArray getData() const;
    Header getHeader() const;
    bool isSingle(){
        return data.size() == header.getDataSize();
    }
    QList<Message> splitMessage(){
        QList<Message>list;
        Message next;
        QByteArray leftByte = this->toByteArray();

        qDebug()<<"---------------------------------------------------";
        qDebug()<<"all:" + leftByte;
        while(leftByte.size()!=0){
            next = Message(leftByte);
            qDebug()<<"---------------------------------------------------";
            //qDebug()<<"next = " << next.toByteArray();
            //qDebug()<<QString::number(next.getHeader().getType(),16)<<" "<<next.getHeader().getDataSize();//ok!
            int nextSize = next.getHeader().getHeadSize() + next.getHeader().getDataSize();
            qDebug()<<"nextSize = " <<nextSize;
            Message nextMessage(leftByte.mid(0,nextSize));
            //qDebug()<<nextMessage.getHeader().getType();
            //qDebug()<<nextMessage.getHeader().getDataSize();
            list.append(nextMessage);
            leftByte = leftByte.mid(nextSize);
        }
        return list;
    }
};

#endif // MESSAGE_H
