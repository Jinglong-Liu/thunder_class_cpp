#include "studentview.h"
#include "ui_studentview.h"

StudentView::StudentView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentView)
{
    ui->setupUi(this);
}

StudentView::~StudentView()
{
    delete ui;
}
