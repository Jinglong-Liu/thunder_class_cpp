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
        clientmain.cpp \
        connectrequest.cpp \
        error.cpp \
        loginviewhandler.cpp \
        main.cpp \
        login.cpp \
        message.cpp \
        messageanalyser.cpp \
        messagesender.cpp \
        model/student.cpp \
        msgsender.cpp \
        mydata.cpp \
        onlinedata.cpp \
        recvmsg.cpp \
        studentoperationhandler.cpp \
        studentview.cpp \
        studentviewhandler.cpp \
        util.cpp

HEADERS += \
        clientmain.h \
        config.h \
        connectrequest.h \
        error.h \
        login.h \
        loginviewhandler.h \
        message.h \
        messageanalyser.h \
        messagesender.h \
        model/student.h \
        msgsender.h \
        mydata.h \
        onlinedata.h \
        recvmsg.h \
        studentoperationhandler.h \
        studentview.h \
        studentviewhandler.h \
        util.h

FORMS += \
        login.ui \
        studentview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
