#ifndef ERROR_H
#define ERROR_H
//00 00 00 00
//错误  00 ff xx xx
//广播  7f ff xx xx
//正常回应 0x 01 xx xx
enum ERROR_LOGIN_ERR{
    PASSWORD_ERR = 0x00ff0001,
    ID_NOTFOUND_ERR = 0x00ff0002,
    LOGIN_REPEATEDLY_ERR = 0x00ff0003,
};
enum BROADCAST_TYPE{
    ADD_NEW_STUDENT = 0x7fff0001,
    CORRECT_ONLINENUM = 0x7fff0002,
    BROADCAST_MESSAGE = 0x7fff0003
};
#endif // ERROR_H
