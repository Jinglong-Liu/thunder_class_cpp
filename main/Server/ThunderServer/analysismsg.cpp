#include "analysismsg.h"
#include <QMutex>
#include<QThread>

AnalysisMsg::AnalysisMsg(QTcpSocket *socket, QByteArray byteArray,Data *data,QObject *parent)

{
    this->socket = socket;
    this->message = byteArray;
    this->data = data;
}

void AnalysisMsg::run()
{
    //analyse different type of msg
    //analyse();
}

void AnalysisMsg::setMessage(QByteArray message)
{
    this->message = message;
}

void AnalysisMsg::setSocket(QTcpSocket* socket)
{
    this->socket = socket;
    this->message = socket->readAll();
}

int AnalysisMsg::getHead()
{
    //socket->read((char*)head,4);
    head = (int)(Util::toUint32_t(message,0,8));
    return head;
}
/*
void AnalysisMsg::analyse()
{
    int head = getHead();
    qDebug()<<"head==" + QString::number(head);
    if(head == 0x12){
        qDebug()<<"head == 0x12";

        StudentInfo *info = studentLoginRequest(message);


        //socket = old socket
        if(info == nullptr){
            Prepare notFound;
            notFound.socketsToSend.insert(socket);//发给自己即可
            notFound.messageToSend = Util::toHexByteArray(0x14);//用户名不存在
            //queue.push_back(prepare);
            emit send(notFound);
        }
        else if(info->state == 1){

            Prepare p1;
            p1.socketsToSend.insert(socket);//先发给自己成功登录
            p1.messageToSend = Util::toHexByteArray(0x12);
            p1.messageToSend.append((char*)info,sizeof(*info));//传一个info
            qDebug()<<"send back p1";
            //queue.push_back(p1);
            emit send(p1);

            //然后广播到所有socket，告诉大家登录的在线学生+1,学生xx已上线
            //这样不能广播自己：注意进程同步,可以广播给其他所有人...
            Prepare p2;
            //添加socket
            //
            Util::tcpSocketMutex.lock();
            p2.socketsToSend = Util::tcpSockets;
            p2.messageToSend = Util::toHexByteArray(0x0f000012);
            //Util::onlineData->addNewStudent(info);
            p2.messageToSend.append((char*)info,sizeof(*info));

            //广播学生上线
            //queue.push_back(p2);
            qDebug()<<"broadcast p2";
            emit send(p2);
            Util::tcpSocketMutex.unlock();

            //
            //emit broadcastOnlineNumber(Util::onlineData->getOnlineStudentCount());//这里不对


        }
        else{
            //密码错误
            Prepare err;
            err.socketsToSend.insert(socket);//发给自己
            err.messageToSend = Util::toHexByteArray(0x13);//密码错误
            qDebug()<<"send back err";
            //queue.push_back(p1);
            emit send(err);
        }
    }
}
*/
StudentInfo* AnalysisMsg::studentLoginRequest(QByteArray message)
{

    //head(4) + id_len(4) + id(id_len) + password(left);
    QString str = QString(message);

    int id_len = str.mid(8,8).toInt();
    QString id = str.mid(16,id_len);
    QString password = str.mid(16+id_len);
    qDebug()<<"id:" + id;
    qDebug()<<"password:" + password;
    //ok.
    if(!data->getStudentTable().contains(id)){
        qDebug()<<"can't match id";
        return nullptr;
    }
    StudentInfo* info = data->getStudentTable().value(id);
    if(info->getPassword() == password){
        qDebug()<<"matched.";
        //if(info->state == 1){
            //重复登录//TODO
            return nullptr;
        //}
        //info->setState(1);
    }
    return info;
}

Data *AnalysisMsg::getData() const
{
    return data;
}

void AnalysisMsg::setData(Data *value)
{
    data = value;
}

