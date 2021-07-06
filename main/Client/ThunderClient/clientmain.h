#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H
#include "login.h"
#include"recvmsg.h"
#include"msgsender.h"
#include"loginviewhandler.h"
#include"studentviewhandler.h"
class ClientMain:public QObject
{
    Q_OBJECT
public:
    ClientMain();
    void init();
    void addNewStudent(StudentInfo* info);
    void studentLoginSucceed(StudentInfo* info);
    void doConnectRequest(QString ip,unsigned short port);
    void tryToRecvMsg(QTcpSocket *socket);
signals:
    //to login ui
    void initLoginUi(QString ip,int port);

    //to studentView
private:
    //model
    //TeacherInfo* teacher;
    StudentInfo *student;
    OnlineData* onlineData;
    //ui
    Login* login;
    StudentView *studentView;
    //control
    LoginViewHandler* loginViewHandler;
    StudentViewHandler* studentViewHandler;

    ConnectRequest* connectRequest;
    Analyser *analyser;
    //互斥资源socket
    QTcpSocket* socket;
    //thread
    RecvMsg* receiver;
    MsgSender *sender;
};

#endif // CLIENTMAIN_H
