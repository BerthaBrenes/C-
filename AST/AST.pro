TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    prefix.cpp \
    astnodetype.cpp \
    ../lab07/ast.cpp \
    ../lab07/st.cpp \
    parseoascii.cpp

HEADERS += \
    prefix.h \
    astnodetype.h \
    ../lab07/ast.hpp \
    ../lab07/spl.lpp \
    ../lab07/spl.ypp \
    ../lab07/st.hpp \
    ../lab07/value.hpp \
    parseoascii.h

DISTFILES += \
    ../lab07/features.txt \
    ../lab07/Makefile
