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
    desicion.cpp \
    factorydepends.cpp \
    operaciones.cpp \
    parseoascii.cpp \
    prefix.cpp \
    prueba.cpp \

    astnode.cpp

HEADERS  += mainwindow.h \
    tcpclient.h \
    json_copy.hpp \
    linenumberarea.h \
    codeeditor.h \
    desicion.h \
    doubles.h \
    factorydepends.h \
    floating.h \
    interfaces.h \
    intermediario.h \
    intiger.h \
    chars.h \
    longer.h \
    operaciones.h \
    parseoascii.h \
    prefix.h \
    prueba.h \
    structs.h \
    astnode.h

FORMS    += mainwindow.ui

DISTFILES += \
    uml_c-.qmodel
