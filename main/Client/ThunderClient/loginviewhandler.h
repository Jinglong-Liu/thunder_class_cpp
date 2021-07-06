#ifndef LOGINVIEWHANDLER_H
#define LOGINVIEWHANDLER_H
#include"login.h"

class LoginViewHandler:public QObject

{
    Q_OBJECT
public:
    LoginViewHandler(Login* view,QObject *parent = nullptr);
    Login *getView() const;
    void setView(Login *value);
    void loginSuccessful(StudentInfo *info = nullptr){
        view->studentLoginSucceed();
    }
private:
    Login *view;
};

#endif // LOGINVIEWHANDLER_H
