#ifndef ERROR_H
#define ERROR_H
/*
* 0x0f 01:学生登录密码错误
* 0x0f 02:学生登录不存在用户名
* 0x0f 03:学生重复登录
*/
class ERROR
{
public:
};

enum STUDENT_LOGIN_ERR{


    PASSWORD_ERR = 0x0f1,
    ID_NOTFOUND_ERR = 0x0f02,
    LOGIN_REPEATEDLY = 0x0f03,
};
int f(){
    int x = STUDENT_LOGIN_ERR::PASSWORD_ERR;
}


#endif // ERROR_H
