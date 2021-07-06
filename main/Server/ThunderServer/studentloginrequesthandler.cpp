#include "studentloginrequesthandler.h"

StudentLoginRequestHandler::StudentLoginRequestHandler(QObject *parent) : QObject(parent)
{

}

void StudentLoginRequestHandler::sendStudentLoginIdNotFound(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::ID_NOTFOUND_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}

void StudentLoginRequestHandler::sendStudentLoginPasswordError(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::PASSWORD_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}

void StudentLoginRequestHandler::sendStudentLoginRepeatedly(QTcpSocket *socket, QString id){
    Header header(ERROR_LOGIN_ERR::LOGIN_REPEATEDLY_ERR);
    Message m(header);
    socket->write(m.toByteArray());
}
