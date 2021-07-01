#include "studentview.h"
#include "ui_studentview.h"
#include"config.h"
StudentView::StudentView(OnlineData *data,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentView)
{
    ui->setupUi(this);
    this->onlineData = data;
}

StudentView::~StudentView()
{
    delete ui;
}

void StudentView::updateInfo(StudentInfo *info)
{
    ui->id->setText(info->getId());
    ui->name->setText(info->getName());
}

void StudentView::addOnlineStudent(StudentInfo *info)
{
    updateOnlineData();
    ui->textRecv->append("学生 " + info->getId() + " " + info->getName() + "已上线.");
}

void StudentView::updateOnlineData()
{
    ui->onlineNum->setNum(onlineData->getOnlineNum());
}
