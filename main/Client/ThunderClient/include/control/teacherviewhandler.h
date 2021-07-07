#ifndef TEACHERVIEWHANDLER_H
#define TEACHERVIEWHANDLER_H

#include <QObject>
#include"../config/config.h"
#include"../model/student.h"
#include"../view/teacherview.h"
class TeacherViewHandler : public QObject
{
    Q_OBJECT
public:
    explicit TeacherViewHandler(TeacherView *teacherView,QObject *parent = nullptr);
    void handleTeacherLoginSuccessful(TeacherInfo *info);
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
    TeacherView *view;
};

#endif // TEACHERVIEWHANDLER_H
