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
enum BroadcastType{
    AddNewStudent = 0x7fff0001,
    AddNewTeacher = 0x7fff0002,
    CorrectOnlineNum = 0x7fff0003,
    BroadcastMessageFromStudent = 0x7fff0004,
    BroadcastMessageFromTeacher = 0x7fff0005
};
enum RequestType{
    StudentLogin = 0x12,
    TeachetLogin = 0X13
};
enum ResponseType{
    StudentLoginSucceed = 0x010012,
    TeacherLoginSucceed = 0x010013
};
enum Status{
    teacher = 1,
    student = 2
};

#endif // ERROR_H
