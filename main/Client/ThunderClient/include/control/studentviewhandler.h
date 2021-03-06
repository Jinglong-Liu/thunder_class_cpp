#ifndef STUDENTVIEWHANDLER_H
#define STUDENTVIEWHANDLER_H

#include <QObject>
#include"../config/config.h"
#include"../model/student.h"
#include"../view/studentview.h"
class StudentViewHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentViewHandler(StudentView *view,QObject *parent = nullptr);

    void handleStudentLoginSuccessful(StudentInfo *info);
    void handleAddNewStudent(StudentInfo *info){
        view->addOnlineStudent(info);
    }
    void handleAddNewTeacher(TeacherInfo *info){
        view->addOnlineTeacher(info);
    }
    void handleCorrectOnlineNum(int num){
        view->setOnlineNumber(num);
    }
    void appendText(QString str){
        view->appendText(str);
    }
signals:

public slots:
private:
    StudentView *view;
};

#endif // STUDENTVIEWHANDLER_H
