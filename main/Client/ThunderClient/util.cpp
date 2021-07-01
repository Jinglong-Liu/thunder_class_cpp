#include"util.h"
QByteArray Util::toHexByteArray(uint32_t num){
    //一个数，32位，返回用16进制表示的8个字符组成的字符串
    //QString qnum= QString::number(num,16).fill('0',8);
    QString qnum;
    qnum = QString("%1").arg(QString::number(num,16),8,'0');
    return qnum.toUtf8();
}
uint32_t Util::toUint32_t(QByteArray hexByteArray){
    //16进制字符串，转成数字
    uint32_t value = hexByteArray.toUInt(nullptr,16);
    return value;
}
uint32_t Util::toUint32_t(QByteArray hexByteArray, int start, int size)
{
    QByteArray subBytes = hexByteArray.mid(start,size);
    return Util::toUint32_t(subBytes);
}