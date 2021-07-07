#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "studentview.h"

#include"../config/config.h"
#include"../model/student.h"
#include"../control/connectrequest.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    void initView(QString ip,unsigned short port);
    void studentLoginSucceed();
    void studentLoginFail();
    void studentLoginNotFound();

    void connectSucceed();
    void connectFail();
    Ui::Login *ui;
    ~Login();
signals:
    void requestForConnect(QString ip,unsigned short port);
    void requestForLogin(QString id,QString password);

    void studentLoginRequest(QString id,QString password);
    void teacherLoginRequest(QString id,QString password);
private slots:
    void on_connectBtn_clicked();

    void on_loginStudentBtn_clicked();

    void on_loginTeacherBtn_clicked();

private:
    ConnectRequest* connectRequest;
    StudentView *studentView;
    QTcpSocket* socket;
};

#endif // LOGIN_H
