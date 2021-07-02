#include "studentview.h"
#include "ui_studentview.h"
#include"config.h"
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

void StudentView::addOnlineStudent(StudentInfo *info)
{
    ui->textRecv->append("学生 " + info->getId() + " " + info->getName() + "已上线.");
}

void StudentView::updateOnlineData(OnlineData* data)
{
    ui->onlineNum->setNum(data->getOnlineNum());
}

void StudentView::displayStudentInfo(StudentInfo *info)
{
    ui->id->setText(info->getId());
    ui->name->setText(info->getName());
}

void StudentView::setOnlineNumber(int count)
{
    ui->onlineNum->setNum(count);
}
