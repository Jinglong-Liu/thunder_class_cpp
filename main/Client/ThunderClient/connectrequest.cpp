#include "connectrequest.h"
#include<QMessageBox>
ConnectRequest::ConnectRequest()
{

socket = new QTcpSocket;

}

ConnectRequest::ConnectRequest(QTcpSocket *socket)
{
    this->socket = socket;
}

void ConnectRequest::run()
{

    //socket->connectToHost(QHostAddress(ip),port);
    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QByteArray data = socket->readAll();
        //TODO:处理不同类型的报文
    });
}

void ConnectRequest::recvAddr(QString ip, unsigned short port)
{
    this->ip = ip;
    this->port = port;
}

void ConnectRequest::doConnectRequest(QString ip, unsigned short port)
{

}

QTcpSocket *ConnectRequest::getSocket()
{
    return socket;
}
