#ifndef CONFIG_H
#define CONFIG_H
#include<QDebug>
#include<QRunnable>
#include<QtCore>
#include<QTcpServer>
#include<QTcpSocket>
#endif // CONFIG_H
/**
 * @brief
 * 客户端发向服务器
 * 报文头部表明类型(4字节32位,相当于int)
 * 暂定
 * 客户端发送的报文头部标识：
 * 前2字节表示发送对象：
 * 00 00 表示自己
 * 11 11 表示广播
 * 0x00 00 00 11:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x00 00 00 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码 成功则需要回发学生信息，群发人数，在线学生id
 */
