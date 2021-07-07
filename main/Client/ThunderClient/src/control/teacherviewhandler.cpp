#include "../../include/control/teacherviewhandler.h"

TeacherViewHandler::TeacherViewHandler(TeacherView *teacherView,QObject *parent) : QObject(parent)
{
    this->view = teacherView;
}
void TeacherViewHandler::handleTeacherLoginSuccessful(TeacherInfo *info){
    view->displayTeacherInfo(info);
    view->show();
}
