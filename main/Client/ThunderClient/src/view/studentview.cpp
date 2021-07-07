#include "../../include/view/studentview.h"
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

void StudentView::addOnlineStudent(StudentInfo *info)
{
    ui->textRecv->append("学生 " + info->getId() + " " + info->getName() + "已上线.");
}

void StudentView::addOnlineTeacher(TeacherInfo *info)
{
    ui->textRecv->append("教师 " + info->getName() + "已上线.");
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

void StudentView::appendText(QString str){
    ui->textRecv->append(str);
}

void StudentView::on_sendMsg_clicked()
{
    if(ui->textToSend->toPlainText().size()!=0){
        emit broadcastMessage(ui->textToSend->toPlainText(),Status::student);
        ui->textToSend->clear();
    }
}
