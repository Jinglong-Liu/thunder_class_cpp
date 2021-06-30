#ifndef CONFIG_H
#define CONFIG_H

#endif // CONFIG_H
#include<QtCore>
#include<QtGui>
#include<QRunnable>
#include<QObject>
#include<QTcpSocket>
#include<QHostAddress>
#include<QMutex>
/**
 * @brief
 * 客户端发向服务器
 * 报文头部表面类型(4字节32位,相当于int)
 * 暂定
 * 客户端发送的报文头部标识：
 * 0x0011:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x0012:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 */
