#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QMainWindow>
#include"./model/student.h"
namespace Ui {
class StudentView;
}

class StudentView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentView(QWidget *parent = nullptr);
    ~StudentView();

private:
    Ui::StudentView *ui;
    Student* student;
};

#endif // STUDENTVIEW_H
