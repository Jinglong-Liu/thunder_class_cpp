#include "../../include/control/studentviewhandler.h"

StudentViewHandler::StudentViewHandler(StudentView *view,QObject *parent) : QObject(parent)
{
    this->view = view;
}

void StudentViewHandler::handleStudentLoginSuccessful(StudentInfo *info){
    view->displayStudentInfo(info);
    view->show();
}
