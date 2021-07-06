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
 * //4字节表示类型，4字节表示长度
 *
 *
 * 客户端发向服务器
 *
 * 暂定
 * 客户端发送的报文头部标识：
 * 0x00 10:教师登录请求 接下来4字节表示id的长度，然后是id和密码
 * 0x00 12:学生登录请求 接下来4字节表示id的长度，然后是id和密码
 *
 * 服务器发给客户端:
 * 单播
 * 0x00 10:教师登录成功
 * 0x00 11:教师登录失败
 * 0x00 12:学生登录成功，然后是一个StudentInfo结构体
 *
 * 0x0f 01:学生登录密码错误
 * 0x0f 02:学生登录不存在用户名
 * 0x0f 03:学生重复登录
 *
 * 广播
 * 0x7f 10: 教师上线
 * 0x7f 11: 教师下线
 * 0x7f 12: 学生登录，后面是学生信息 sizeof(studentInfo)
 * 0x7f 13: 学生退出，后面是学生信息
 */

#endif // CONFIG_H
