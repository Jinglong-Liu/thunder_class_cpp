#ifndef UTIL_H
#define UTIL_H
#include<QtCore>
#include<QtGui>
#include<QRunnable>
#include<QThread>
#include<QObject>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMutex>
#include<QMessageBox>
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
    Message getMessageFromSocket(QTcpSocket tcpSocket){
        tcpSocket.read((char*)&header,sizeof(header));
        tcpSocket.read((char*)&data,header.dataSize);
        return *this;
    }
    Message(){}
    //this constructor will correct the dataSize.
    Message(Header header,QByteArray data){
        this->header = header;
        this->data = data;
        this->header.dataSize = data.size();//don't use sizeof(data),which always equals 4(like an pointer).
    }
    void sendBy(QTcpSocket* socket){
        socket->write(this->toByteArray());
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
    //static QSet<QTcpSocket*>tcpSockets;
    static QMutex tcpSocketMutex;
};

#endif // UTIL_H
