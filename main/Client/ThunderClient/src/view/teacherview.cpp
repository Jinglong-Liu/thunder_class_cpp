#include "../../include/view/teacherview.h"
#include "ui_teacherview.h"

TeacherView::TeacherView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeacherView)
{
    ui->setupUi(this);
}

TeacherView::~TeacherView()
{
    delete ui;
}

void TeacherView::addOnlineStudent(StudentInfo *info)
{
    ui->textRecv->append("学生 " + info->getId() + " " + info->getName() + "已上线.");
}
void TeacherView::addOnlineTeacher(TeacherInfo *info)
{
    ui->textRecv->append("教师 " + info->getName() + "已上线.");
}
void TeacherView::displayTeacherInfo(TeacherInfo *info)
{
    ui->id->setText(info->getId());
    ui->name->setText(info->getName());
}

void TeacherView::setOnlineNumber(int count)
{
    ui->onlineNum->setNum(count);
}

void TeacherView::appendText(QString str){
    ui->textRecv->append(str);
}

void TeacherView::on_sendMsg_clicked()
{
    if(ui->textToSend->toPlainText().size()!=0){
        emit broadcastMessage(ui->textToSend->toPlainText(),Status::teacher);
        ui->textToSend->clear();
    }
}
