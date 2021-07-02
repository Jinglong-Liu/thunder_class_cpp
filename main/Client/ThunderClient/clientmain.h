#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H
#include "login.h"
#include"recvmsg.h"
#include"msgsender.h"
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
    ConnectRequest* connectRequest;
    Analyser *analyser;
    QTcpSocket* socket;
    //thread
    RecvMsg* receiver;
    MsgSender *sender;
};

#endif // CLIENTMAIN_H
