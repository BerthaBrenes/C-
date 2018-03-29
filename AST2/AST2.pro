TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parseo.cpp \
    astnode.cpp

HEADERS += \
    parseo.h \
    astnode.h
