#include"../../include/main/clientmain.h"
ClientMain::ClientMain()
{

    login = new Login();
    loginViewHandler = new LoginViewHandler(login);
    studentView = new StudentView();
    studentViewHandler = new StudentViewHandler(studentView);
    teacherView = new TeacherView();
    teacherViewHandler = new TeacherViewHandler(teacherView);
    socket = new QTcpSocket;
    receiver = new MessageReceiver(socket);

    MessageSender* sender = new MessageSender(socket);
    MessageAnalyser *analyser = new MessageAnalyser();

    connect(receiver,&MessageReceiver::recvMsg,analyser,&MessageAnalyser::analyser);

    connect(analyser,&MessageAnalyser::studentLoginSuccessFul,loginViewHandler,&LoginViewHandler::loginSuccessful);
    connect(analyser,&MessageAnalyser::studentLoginSuccessFul,studentViewHandler,&StudentViewHandler::handleStudentLoginSuccessful);
    connect(analyser,&MessageAnalyser::addNewStudent,studentViewHandler,&StudentViewHandler::handleAddNewStudent);
    connect(analyser,&MessageAnalyser::addNewStudent,teacherViewHandler,&TeacherViewHandler::handleAddNewStudent);


    connect(analyser,&MessageAnalyser::teacherLoginSuccessFul,loginViewHandler,&LoginViewHandler::loginSuccessful);
    connect(analyser,&MessageAnalyser::teacherLoginSuccessFul,teacherViewHandler,&TeacherViewHandler::handleTeacherLoginSuccessful);
    connect(analyser,&MessageAnalyser::addNewTeacher,teacherViewHandler,&TeacherViewHandler::handleAddNewTeacher);
    connect(analyser,&MessageAnalyser::addNewTeacher,studentViewHandler,&StudentViewHandler::handleAddNewTeacher);




    connect(analyser,&MessageAnalyser::LoginError,loginViewHandler,&LoginViewHandler::loginError);
    connect(analyser,&MessageAnalyser::correctOnlineNum,studentViewHandler,&StudentViewHandler::handleCorrectOnlineNum);
    connect(analyser,&MessageAnalyser::correctOnlineNum,teacherViewHandler,&TeacherViewHandler::handleCorrectOnlineNum);
    connect(analyser,&MessageAnalyser::appendText,studentViewHandler,&StudentViewHandler::appendText);
    connect(analyser,&MessageAnalyser::appendText,teacherViewHandler,&TeacherViewHandler::appendText);
    emit initLoginUi("127.0.0.1",7788);

    connectRequest = new ConnectRequest(socket);
    connect(login,&Login::requestForConnect,this,&ClientMain::doConnectRequest);//request for connection.
    //login ui
    connect(this,&ClientMain::initLoginUi,login,&Login::initView);
    connect(studentView,&StudentView::broadcastMessage,sender,&MessageSender::sendBroadcastMessage);//????????????
    connect(teacherView,&TeacherView::broadcastMessage,sender,&MessageSender::sendBroadcastMessage);//????????????

    //??????
    connect(login,&Login::studentLoginRequest,sender,&MessageSender::sendStudentLoginRequest);//????????????????????????
    connect(login,&Login::teacherLoginRequest,sender,&MessageSender::sendTeacherLoginRequest);//????????????????????????
    //??????
    //connect(receiver,&RecvMsg::recvMsg,analyser,&Analyser::analyse);//????????????
    login->show();
}

void ClientMain::doConnectRequest(QString ip, unsigned short port)
{
    socket->connectToHost(QHostAddress(ip),port);//????????????
    if(socket->waitForConnected(500)){
        qDebug()<<"????????????";
        //ui
        login->connectSucceed();
        tryToRecvMsg(this->socket);
    }
    else {
        qDebug()<<"????????????";
        login->connectFail();
    }
}

void ClientMain::tryToRecvMsg(QTcpSocket *socket)
{
    //receiver->run();//?????????????????????...
    receiver->start();//????????????????????????
    //receiver->receive();
}

