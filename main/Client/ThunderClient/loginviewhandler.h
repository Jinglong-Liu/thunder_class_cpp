#ifndef LOGINVIEWHANDLER_H
#define LOGINVIEWHANDLER_H
#include<QMessageBox>
#include"login.h"
#include"error.h"
class LoginViewHandler:public QObject

{
    Q_OBJECT
public:
    LoginViewHandler(Login* view,QObject *parent = nullptr);
    Login *getView() const;
    void setView(Login *value);
    void loginSuccessful(StudentInfo *info = nullptr);
    void loginError(int type){
        switch(type){
        case ERROR_LOGIN_ERR::PASSWORD_ERR:{
            loginPassWordErr();
            break;
        }
        case ERROR_LOGIN_ERR::ID_NOTFOUND_ERR:{
            loginIdNotFoundErr();
            break;
        }
        case ERROR_LOGIN_ERR::LOGIN_REPEATEDLY_ERR:{
            loginRepeatedlyErr();
        }
        }
    }
    void loginIdNotFoundErr(){
        QMessageBox::information(view,"提示","非法的Id,请确认后重试");
    }
    void loginRepeatedlyErr(){
        QMessageBox::information(view,"提示","您已经登录,请不要重复登录");
    }
    void loginPassWordErr(){
        QMessageBox::information(view,"提示","密码错误,请确认后重试");
    }
private:
    Login *view;
};

#endif // LOGINVIEWHANDLER_H
