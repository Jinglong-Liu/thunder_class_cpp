#ifndef MSGANALYSER_H
#define MSGANALYSER_H
#include"config.h"
#include"util.h"
#include <QThread>
class MsgAnalyser : public QThread
{
    Q_OBJECT
public:
    explicit MsgAnalyser(Message message,QObject *parent = nullptr);

    Message getMessage() const;
    void setMessage(const Message &value);
    void analyse();
    void run()override;
signals:
    //emit to data handler and ui.
    void studentLoginSuccess(StudentInfo*);
public slots:
private:
    Message message;
};
#endif // MSGANALYSER_H
