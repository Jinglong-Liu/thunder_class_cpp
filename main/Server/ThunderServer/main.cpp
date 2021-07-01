#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    StudentInfo st("1000000","123456","456789");
    qDebug()<<sizeof (st);
    Data *data = new Data();
    for(QString str:data->getStudentTable().keys()){
        StudentInfo *info = data->getStudentTable().value(str);
        qDebug()<<info->getId()<<info->getName()<<info->getPassword();
    }
    qDebug()<<Util::toHexByteArray(0x80000000); //7f ff ff ff
    qDebug()<<Util::toUint32_t(QByteArray("80000000"));
    return a.exec();
}

