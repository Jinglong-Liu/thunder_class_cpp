#include"../../include/control/loginviewhandler.h"
LoginViewHandler::LoginViewHandler(Login *view, QObject *parent)
{
    this->view = view;
}

Login *LoginViewHandler::getView() const
{
    return view;
}

void LoginViewHandler::setView(Login *value)
{
    view = value;
}

void LoginViewHandler::loginSuccessful(void *info){
    view->studentLoginSucceed();
}
