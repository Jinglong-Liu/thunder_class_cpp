#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Data *data = Data::instance();

    for(QString str:data->getStudentTable().keys()){
        StudentInfo *info = data->getStudentTable().value(str);
        qDebug()<<info->getId()<<info->getName()<<info->getPassword();
    }
    return a.exec();
}

