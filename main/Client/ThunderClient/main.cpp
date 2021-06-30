#include "login.h"
#include <QApplication>

#include "clientmain.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    new ClientMain();

    return a.exec();
}
