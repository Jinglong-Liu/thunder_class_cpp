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
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();
    void addOnlineStudent(StudentInfo *info);
    void updateOnlineData(OnlineData* data);

    void displayStudentInfo(StudentInfo* info);
    void setOnlineNumber(int count);
    void appendText(QString str);
signals:
    void broadcastMessage(QString str);
private slots:
    void on_sendMsg_clicked();

private:
    Ui::StudentView *ui;

    //Student* student;

};

#endif // STUDENTVIEW_H
