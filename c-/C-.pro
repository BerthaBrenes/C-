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
    codeeditor.cpp \
    prefix.cpp \
    prueba.cpp \
    parseoascii.cpp \
    operaciones.cpp \
    factorydepends.cpp \
    desicion.cpp \
    astnode.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    json_copy.hpp \
    linenumberarea.h \
    codeeditor.h \
    client.h \
    intiger.h \
    structs.h \
    prueba.h \
    prefix.h \
    parseoascii.h \
    operaciones.h \
    longer.h \
    intermediario.h \
    interfaces.h \
    floating.h \
    factorydepends.h \
    doubles.h \
    desicion.h \
    chars.h \
    astnode.h

FORMS    += mainwindow.ui

DISTFILES += \
    uml_c-.qmodel
