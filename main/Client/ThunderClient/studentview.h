#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include"./model/student.h"
#include "onlinedata.h"
namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentView(OnlineData *data,QWidget *parent = nullptr);
    ~StudentView();
    Ui::StudentView *ui;
    void updateInfo(StudentInfo *info);
    void addOnlineStudent(StudentInfo *info);
    void updateOnlineData();
private:
    OnlineData *onlineData;
    //Student* student;
};

#endif // STUDENTVIEW_H
