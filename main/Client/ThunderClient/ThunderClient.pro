#-------------------------------------------------
#
# Project created by QtCreator 2021-06-30T09:28:29
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThunderClient
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ./src/clientmain.cpp \
        ./src/control/connectrequest.cpp \
        ./src/error.cpp \
        ./src/control/loginviewhandler.cpp \
        ./src/main.cpp \
        ./src/view/login.cpp \
        ./src/model/message.cpp \
        ./src/control/messageanalyser.cpp \
        ./src/control/messagereceiver.cpp \
        ./src/control/messagesender.cpp \
        ./src/model/student.cpp \
        ./src/model/mydata.cpp \
        ./src/control/studentoperationhandler.cpp \
        ./src/view/studentview.cpp \
        ./src/control/studentviewhandler.cpp \
        ./src/utils/util.cpp

HEADERS += \
        ./include/clientmain.h \
        ./include/config/config.h \
        ./include/control/connectrequest.h \
        ./include/config/error.h \
        ./include/view/login.h \
        ./include/control/loginviewhandler.h \
        ./include/model/message.h \
        ./include/control/messageanalyser.h \
        ./include/control/messagereceiver.h \
        ./include/control/messagesender.h \
        ./include/model/student.h \
        ./include/model/mydata.h \
        ./include/control/studentoperationhandler.h \
        ./include/view/studentview.h \
        ./include/control/studentviewhandler.h \
        ./include/utils/util.h \
        ./include/config.h \
        ./include/control/control.h \
        ./include/model/model.h

FORMS += \
        login.ui \
        studentview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
