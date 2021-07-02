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

class Util{
public:
    static QByteArray toHexByteArray(uint32_t num);
    //static QByteArray toHexByteArray(int num);
    static uint32_t toUint32_t(QByteArray hexByteArray);
    static uint32_t toUint32_t(QByteArray hexByteArray,int start,int size);
};
#endif // UTIL_H
