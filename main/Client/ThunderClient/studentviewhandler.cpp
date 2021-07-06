#include "studentviewhandler.h"

StudentViewHandler::StudentViewHandler(StudentView *view,QObject *parent) : QObject(parent)
{
    this->view = view;
}
