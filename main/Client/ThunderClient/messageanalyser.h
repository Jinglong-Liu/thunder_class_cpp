#ifndef MESSAGEANALYSER_H
#define MESSAGEANALYSER_H

#include <QObject>
#include"message.h"
class MessageAnalyser : public QObject
{
    Q_OBJECT
public:
    explicit MessageAnalyser(Message message,QObject *parent = nullptr);
    void analyser(){
        short type = message.getHeader().getType();
        switch(type){

        }
    }
signals:

public slots:
private:
    Message message;
};

#endif // MESSAGEANALYSER_H
