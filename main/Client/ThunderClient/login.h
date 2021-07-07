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
private slots:
    void on_connectBtn_clicked();

    void on_loginStudentBtn_clicked();

private:

    //static Login* loginView;
    ConnectRequest* connectRequest;
    StudentView *studentView;
    StudentInfo* student;
    Analyser *analyser;

    QTcpSocket* socket;
    OnlineData* onlineData;
};

#endif // LOGIN_H
