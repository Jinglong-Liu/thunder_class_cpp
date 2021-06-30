#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString x = "abcdefg";
    QByteArray bytes = QByteArray::number(0x11) + x.toUtf8();
    QString str = QString(bytes);
    QString sub = str.mid(2,5);//start len
    qDebug()<<str;
    qDebug()<<sub;
    return a.exec();
}

