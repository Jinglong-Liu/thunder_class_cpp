#ifndef ERROR_H
#define ERROR_H
/*
* 0x0f 01:学生登录密码错误
* 0x0f 02:学生登录不存在用户名
* 0x0f 03:学生重复登录
*/
//00 00 00 00
//错误  00 ff xx xx
//广播  7f ff xx xx
//正常回应 0x 01 xx xx
enum ERROR_LOGIN_ERR{
    PASSWORD_ERR = 0x00ff0001,
    ID_NOTFOUND_ERR = 0x00ff0002,
    LOGIN_REPEATEDLY_ERR = 0x00ff0003,
};

#endif // ERROR_H
