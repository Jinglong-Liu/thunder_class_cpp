#ifndef STUDENTOPERATIONHANDLER_H
#define STUDENTOPERATIONHANDLER_H

#include <QObject>

class StudentOperationHandler : public QObject
{
    Q_OBJECT
public:
    explicit StudentOperationHandler(QObject *parent = nullptr);
    void broadcastMessage(QString message){

    }
signals:

public slots:
};

#endif // STUDENTOPERATIONHANDLER_H
