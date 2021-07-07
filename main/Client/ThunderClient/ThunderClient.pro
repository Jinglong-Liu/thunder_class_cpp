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
        ./src/main/clientmain.cpp \
        ./src/main/main.cpp \
        ./src/control/connectrequest.cpp \
        ./src/control/loginviewhandler.cpp \
        ./src/control/messageanalyser.cpp \
        ./src/control/messagereceiver.cpp \
        ./src/control/messagesender.cpp \
        ./src/control/studentoperationhandler.cpp \
        ./src/control/studentviewhandler.cpp \
        ./src/control/teacherviewhandler.cpp \
        ./src/model/student.cpp \
        ./src/model/message.cpp \
        ./src/model/mydata.cpp \
        ./src/model/teacher.cpp \
        ./src/utils/error.cpp \
        ./src/utils/util.cpp \
        ./src/view/teacherview.cpp \
        ./src/view/login.cpp \
        ./src/view/studentview.cpp

HEADERS += \
        ./include/main/clientmain.h \
        ./include/config.h \
        ./include/config/config.h \
        ./include/control/control.h \
        ./include/control/connectrequest.h \
        ./include/control/loginviewhandler.h \
        ./include/control/messageanalyser.h \
        ./include/control/messagereceiver.h \
        ./include/control/messagesender.h \
        ./include/control/studentoperationhandler.h  \
        ./include/control/studentviewhandler.h \
        ./include/control/teacherviewhandler.h \
        ./include/model/message.h \
        ./include/model/student.h \
        ./include/model/mydata.h  \
        ./include/model/model.h \
        ./include/model/teacher.h \
        ./include/view/login.h \
        ./include/view/studentview.h\
        ./include/view/teacherview.h\
        ./include/utils/util.h \
        ./include/utils/error.h

FORMS += \
        login.ui \
        studentview.ui \
        teacherview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
