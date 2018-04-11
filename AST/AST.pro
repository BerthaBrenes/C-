TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    prefix.cpp \
    astnodetype.cpp \
    parseoascii.cpp \
    intiger.cpp \
    chars.cpp \
    longer.cpp \
    floating.cpp \
    doubles.cpp \
    structs.cpp \
    factorydepends.cpp \
    prueba.cpp

HEADERS += \
    prefix.h \
    astnodetype.h \
    parseoascii.h \
    intiger.h \
    chars.h \
    longer.h \
    floating.h \
    doubles.h \
    structs.h \
    factorydepends.h \
    prueba.h

DISTFILES += \
