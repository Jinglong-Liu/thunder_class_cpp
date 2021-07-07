#ifndef TEACHERVIEW_H
#define TEACHERVIEW_H

#include <QMainWindow>
#include"../model/teacher.h"
#include"../model/student.h"
namespace Ui {
class TeacherView;
}

class TeacherView : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherView(QWidget *parent = nullptr);
    ~TeacherView();

    void addOnlineStudent(StudentInfo *info);
    void addOnlineTeacher(TeacherInfo *info);
    void displayTeacherInfo(TeacherInfo* info);
    void setOnlineNumber(int count);
    void appendText(QString str);
signals:
    void broadcastMessage(QString str,Status state);
private slots:
    void on_sendMsg_clicked();

private:
    Ui::TeacherView *ui;
};

#endif // TEACHERVIEW_H
