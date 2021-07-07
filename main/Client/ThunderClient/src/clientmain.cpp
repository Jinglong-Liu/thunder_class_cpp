#include"../include/clientmain.h"
ClientMain::ClientMain()
{

    login = new Login();
    loginViewHandler = new LoginViewHandler(login);
    studentView = new StudentView();
    studentViewHandler = new StudentViewHandler(studentView);

    socket = new QTcpSocket;


    //analyser = new Analyser();
    receiver = new MessageReceiver(socket);
    //sender = new MsgSender(socket);
    MessageSender* sender = new MessageSender(socket);
    MessageAnalyser *analyser = new MessageAnalyser();

    connect(receiver,&MessageReceiver::recvMsg,analyser,&MessageAnalyser::analyser);

    connect(analyser,&MessageAnalyser::studentLoginSuccessFul,loginViewHandler,&LoginViewHandler::loginSuccessful);
    connect(analyser,&MessageAnalyser::studentLoginSuccessFul,studentViewHandler,&StudentViewHandler::handleStudentLoginSuccessful);
    connect(analyser,&MessageAnalyser::addNewStudent,studentViewHandler,&StudentViewHandler::handleAddNewStudent);
    connect(analyser,&MessageAnalyser::LoginError,loginViewHandler,&LoginViewHandler::loginError);
    connect(analyser,&MessageAnalyser::correctOnlineNum,studentViewHandler,&StudentViewHandler::handleCorrectOnlineNum);
    connect(analyser,&MessageAnalyser::appendText,studentViewHandler,&StudentViewHandler::appendText);
    emit initLoginUi("127.0.0.1",7788);

    connectRequest = new ConnectRequest(socket);
    connect(login,&Login::requestForConnect,this,&ClientMain::doConnectRequest);//request for connection.
    //login ui
    connect(this,&ClientMain::initLoginUi,login,&Login::initView);
    connect(studentView,&StudentView::broadcastMessage,sender,&MessageSender::sendBroadcastMessage);//发送信息

    //发送
    connect(login,&Login::studentLoginRequest,sender,&MessageSender::sendStudentLoginRequest);//发送学生登录请求
    //接收
    //connect(receiver,&RecvMsg::recvMsg,analyser,&Analyser::analyse);//接收信息
    login->show();
}

void ClientMain::doConnectRequest(QString ip, unsigned short port)
{
    socket->connectToHost(QHostAddress(ip),port);//尝试连接
    if(socket->waitForConnected(500)){
        qDebug()<<"连接成功";
        //ui
        login->connectSucceed();
        tryToRecvMsg(this->socket);
    }
    else {
        qDebug()<<"连接失败";
        login->connectFail();
    }
}

void ClientMain::tryToRecvMsg(QTcpSocket *socket)
{
    //receiver->run();//只可以单线运行...
    receiver->start();//这样貌似是可以的
    //receiver->receive();
}

