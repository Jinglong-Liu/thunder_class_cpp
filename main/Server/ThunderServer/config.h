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
 * 报文需要一次性读完
 *
 * 报文 = 报文头 + 数据(根据报文头的信息可以进一步解析)
 * 报文头 首部长(short) + 服务类型(short) + 数据长(int)
 * 首部长 = 2 + 2 + 4 = 8字节

 * 暂定
 * 客户端发送的【服务类型】标识：
 * 0x00 10:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x00 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 *
 * 服务器发给客户端:
 * 单播
 * 0x00 10:教师登录成功
 * 0x00 11:教师登录失败
 * 0x00 12:学生登录成功，然后是一个StudentInfo结构体
 * 0x00 13:学生登录密码错误
 * 0x00 14:学生登录不存在用户名
 *
 * 广播
 * 0x0f 10: 教师上线
 * 0x0f 11: 教师下线
 * 0x0f 12: 学生登录，后面是学生信息 sizeof(studentInfo)
 * 0x0f 13: 学生退出，后面是学生信息
 * 0x0f 01: 广播在线人数，后面是人数
 */

#endif // CONFIG_H
