#include "loginrequesthandler.h"
LoginRequestHandler::LoginRequestHandler(QObject *parent) : QObject(parent)
{

}

void LoginRequestHandler::sendLoginIdNotFound(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::ID_NOTFOUND_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}

void LoginRequestHandler::sendLoginPasswordError(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::PASSWORD_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}

void LoginRequestHandler::sendLoginRepeatedly(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::LOGIN_REPEATEDLY_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}
