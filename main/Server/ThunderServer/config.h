#ifndef CONFIG_H
#define CONFIG_H
#include<QDebug>
#include<QRunnable>
#include<QtCore>
#include<QTcpServer>
#include<QTcpSocket>
#include <QMetaType>
#include "util.h"
constexpr int STUDENT_LOGIN_WRONG = 0X13;
/**
 * @brief AnalysisMsg::AnalysisMsg
 * @param parent
 *
 * @brief
 * 报文头：8 + 8 = 16，分别表示类型和数据的长度(均以QByteArray计算)
 * //4字节表示类型，4字节表示长度(不包含前16个01串)
 * 客户端发向服务器
 * 报文头部表面类型(4字节32位,相当于int)
 * 暂定
 * 客户端发送的报文头部标识：
 * 0x00 00 00 10:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x00 00 00 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 *
 * 服务器发给客户端:
 * 单播
 * 0x00 00 00 10:教师登录成功
 * 0x00 00 00 11:教师登录失败
 * 0x00 00 00 12:学生登录成功，然后是一个StudentInfo结构体
 * 0x00 00 00 13:学生登录密码错误
 * 0x00 00 00 14:学生登录不存在用户名
 *
 * 广播
 * 0x0f 00 00 10: 教师上线
 * 0x0f 00 00 11: 教师下线
 * 0x0f 00 00 12: 学生登录，后面是学生信息 sizeof(studentInfo)
 * 0x0f 00 00 13: 学生退出，后面是学生信息
 * 0x0f ff 00 01: 广播在线人数，后面是人数
 */


#endif // CONFIG_H
