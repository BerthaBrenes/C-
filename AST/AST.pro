TEMPLATE = app
CONFIG += console C++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    prefix.cpp \
    astnodetype.cpp \
    parseoascii.cpp \
    factorydepends.cpp \
    prueba.cpp \
    desicion.cpp \
    operaciones.cpp \
    client.cpp \
    tcpclient.cpp

HEADERS += \
    prefix.h \
    astnodetype.h \
    parseoascii.h \
    chars.h \
    doubles.h \
    factorydepends.h \
    prueba.h \
    json.hpp \
    interfaces.h \
    intermediario.h \
    floating.h \
    intiger.h \
    longer.h \
    structs.h \
    desicion.h \
    operaciones.h \
    tcpclient.h

DISTFILES += \
