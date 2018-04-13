#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T21:01:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = C-
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    tcpclient.h

FORMS    += mainwindow.ui
