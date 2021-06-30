#include "connectrequest.h"
#include<QMessageBox>
ConnectRequest::ConnectRequest()
{

socket = new QTcpSocket;

}

void ConnectRequest::run()
{

    //socket->connectToHost(QHostAddress(ip),port);

    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QByteArray data = socket->readAll();
        //TODO:处理不同类型的报文
    });

    //if(socket->waitForConnected(3000)){
        //QMessageBox::information(nullptr,"提示","连接成功");
   // }
    //else{
        //QMessageBox::information(nullptr,"提示","连接失败，请重试");
    //}
}

void ConnectRequest::recvAddr(QString ip, unsigned short port)
{
    this->ip = ip;
    this->port = port;
}

QTcpSocket *ConnectRequest::getSocket()
{
    return socket;
}
