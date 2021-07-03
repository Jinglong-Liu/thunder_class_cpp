#ifndef TOOL_H
#define TOOL_H
#include<QByteArray>
#include<QString>
#include<QtCore>
#include<QTcpSocket>
#include<QMutex>
#include "onlinedata.h"
//18 = 0x12(4字节) ->"00 00 00 12"->
struct Prepare{
    QSet<QTcpSocket*>socketsToSend;
    QByteArray messageToSend;
};
struct Header{
    short headSize;
    short type;
    int dataSize;
    Header(short _type = 0,int _dataSize = 0){
        type = _type;
        dataSize = _dataSize;
        headSize = sizeof (*this);// = 8
    }
    QByteArray toByteArray(){
        return QByteArray((char*)&headSize,sizeof(headSize))
                 + QByteArray((char*)&type,sizeof(type))
                 + QByteArray((char*)&dataSize,sizeof(dataSize));
    }

public:
    short getHeadSize() const;
    void setHeadSize(short value);
    short getType() const;
    void setType(short value);
    int getDataSize() const;
    void setDataSize(int value);
};
struct Message{
    Header header;
    QByteArray data;

    QByteArray toByteArray(){
        return header.toByteArray() + data;
    }
    Message(){}
    Message(Header header,QByteArray data){
        this->header = header;
        this->data = data;
        //this->header.dataSize = data.size();//don't use sizeof(data),which always equals 4(like an pointer).
    }

public:
    Header getHeader() const;
    void setHeader(const Header &value);
    QByteArray getData() const;
    void setData(const QByteArray &value);
};

class Util{
public:
    static QByteArray toHexByteArray(uint32_t num);
    static uint32_t toUint32_t(QByteArray hexByteArray);
    static uint32_t toUint32_t(QByteArray hexByteArray,int start,int size);
    static QSet<QTcpSocket*>tcpSockets;
    static QMutex tcpSocketMutex;
    static OnlineData *onlineData;
};
class MessageReader{
    static Message getMessage(QTcpSocket tcpSocket){
        Message message;
        Util::tcpSocketMutex.lock();
        tcpSocket.read((char*)&message.header,sizeof(message.header));
        tcpSocket.read((char*)&message.data,message.header.dataSize);
        Util::tcpSocketMutex.unlock();
        return message;
    }
};






#endif // TOOL_H
