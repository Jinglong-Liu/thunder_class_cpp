#ifndef STUDENTVIEWHANDLER_H
#define STUDENTVIEWHANDLER_H

#include <QObject>
#include"config.h"
#include"message.h"
#include"./model/student.h"
#include"studentview.h"
class StudentViewHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentViewHandler(StudentView *view,QObject *parent = nullptr);
    void handleStudentLoginSuccessful(StudentInfo *info){
        view->displayStudentInfo(info);
        view->addOnlineStudent(info);
        view->show();
    }
signals:

public slots:
private:
    StudentView *view;
};

#endif // STUDENTVIEWHANDLER_H
