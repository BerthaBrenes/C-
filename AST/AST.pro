TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    prefix.cpp \
    astnodetype.cpp \
    ../lab07/ast.cpp \
    ../lab07/st.cpp \
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
    ../lab07/ast.hpp \
    ../lab07/spl.lpp \
    ../lab07/spl.ypp \
    ../lab07/st.hpp \
    ../lab07/value.hpp \
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
    ../lab07/features.txt \
    ../lab07/Makefile
