TEMPLATE = app
CONFIG += console c++11 \
    c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.cpp \
    porter2_stemmer.cpp \
    csvparser.c

HEADERS += catch.hpp \
    porter2_stemmer.h \
    util/hash.h \
    util/stringview.h \
    avltree.hpp \
    hashtable.hpp \
    indexinterface.hpp \
    csvparser.h

DISTFILES += \
    ../../fast-cpp-csv-parser-master.zip
