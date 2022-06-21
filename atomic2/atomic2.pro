#-------------------------------------------------
#
# Project created by QtCreator 2022-06-14T14:57:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = atomic2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    board2.cpp \
    pinball.cpp \
    bomb.cpp \
    shop.cpp

HEADERS  += mainwindow.h \
    board2.h \
    pinball.h \
    bomb.h \
    shop.h

FORMS    += mainwindow.ui \
    board2.ui \
    pinball.ui \
    bomb.ui \
    shop.ui

RESOURCES += \
    res.qrc
