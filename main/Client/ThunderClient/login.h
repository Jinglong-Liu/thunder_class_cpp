#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "connectrequest.h"
#include "studentview.h"
#include "analyser.h"
#include "config.h"
#include "onlinedata.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
signals:
    void requestForConnect(QString ip,unsigned short port);
    void requestForLogin(QString id,QString password);
private slots:
    void on_connectBtn_clicked();

    void on_loginStudentBtn_clicked();

private:
    Ui::Login *ui;
    ConnectRequest* connectRequest;
    StudentView *studentView;
    StudentInfo* student;
    Analyser *analyser;

    QTcpSocket* socket;
    OnlineData* onlineData;
};

#endif // LOGIN_H
