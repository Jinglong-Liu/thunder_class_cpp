#ifndef TOOL_H
#define TOOL_H
#include<QByteArray>
#include<QString>
#include<QtCore>
#include<QTcpSocket>
#include<QMutex>
#include "onlinedata.h"
//18 = 0x12(4字节) ->"00 00 00 12"->
class Util{
public:
    static QByteArray toHexByteArray(uint32_t num);
    static uint32_t toUint32_t(QByteArray hexByteArray);
    static uint32_t toUint32_t(QByteArray hexByteArray,int start,int size);
    static QSet<QTcpSocket*>tcpSockets;
    static QMutex tcpSocketMutex;
    static OnlineData *onlineData;
};
#endif // TOOL_H
