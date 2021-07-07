#ifndef CONFIG_H
#define CONFIG_H
#include<QDebug>
#include<QRunnable>
#include<QtCore>
#include<QTcpServer>
#include<QTcpSocket>
#include <QMetaType>
#include "error.h"
#include "util.h"
/**
 * @brief AnalysisMsg::AnalysisMsg
 * @param parent
 *
 * 报文格式见message.h
 *
 *
 * 客户端发向服务器
 *
 * 暂定
 * 客户端发送的报文头部标识：
 * 0x0000 10:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x0000 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 *
 * 服务器发给客户端:
 * 单播
 * 0x0000 10:教师登录成功
 * 0x0000 11:教师登录失败
 * 0x0000 12:学生登录成功，然后是一个StudentInfo结构体
 *
 */

#endif // CONFIG_H
