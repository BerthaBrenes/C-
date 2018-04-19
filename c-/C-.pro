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
    json.hpp \
    codeeditor.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    json_copy.hpp \
    linenumberarea.h \
    codeeditor.h

FORMS    += mainwindow.ui

DISTFILES += \
    uml_c-.qmodel

 # install
 target.path = $$[QT_INSTALL_EXAMPLES]/widgets/codeeditor
 sources.files = $$SOURCES $$HEADERS *.pro
 sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/codeeditor
 INSTALLS += target sources
