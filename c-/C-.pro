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
    client.cpp \
    json.hpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    json_copy.hpp

FORMS    += mainwindow.ui

DISTFILES += \
    uml_c-.qmodel
