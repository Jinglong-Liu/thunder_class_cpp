#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    StudentInfo st("1000000","123456","456789");
    qDebug()<<sizeof (st);
    Data *data = Data::getInstance();

    for(QString str:data->getStudents()->keys()){
        StudentInfo *info = data->getStudents()->value(str);
        qDebug()<<info->getId()<<info->getName()<<info->getPassword();
    }

    int x = 45689;
    QByteArray _x((char*)&x,sizeof(x));
    qDebug()<<"_x:" + _x;
    _x += "你是猪";
    QByteArray xhead = _x.mid(0,4);
    QByteArray other = _x.mid(4);
    int __x = *(int*)_x.data();
    qDebug()<<__x<<endl;
    qDebug()<<QString(other);
    return a.exec();
}

