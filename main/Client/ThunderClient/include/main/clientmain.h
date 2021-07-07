#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H
#include"../config.h"
class ClientMain:public QObject
{
    Q_OBJECT
public:
    ClientMain();
    void init();
    void doConnectRequest(QString ip,unsigned short port);
    void tryToRecvMsg(QTcpSocket *socket);
signals:
    //to login ui
    void initLoginUi(QString ip,int port);

    //to studentView
private:
    //model
    //TeacherInfo* teacher;
    //ui
    Login* login;
    StudentView *studentView;
    //control
    LoginViewHandler* loginViewHandler;
    StudentViewHandler* studentViewHandler;

    ConnectRequest* connectRequest;

    //互斥资源socket
    QTcpSocket* socket;
    //thread
    MessageReceiver* receiver;
    //
    Mydata* mydata;
};

#endif // CLIENTMAIN_H
