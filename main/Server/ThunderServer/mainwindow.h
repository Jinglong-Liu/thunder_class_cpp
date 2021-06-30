#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QThread>
#include"correspond.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void start(QString ip,unsigned short port);
private slots:
    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    Correspond* correspond;
    //QThread* correspondThread;
};

#endif // MAINWINDOW_H
