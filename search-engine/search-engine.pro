TEMPLATE = app
CONFIG += console c++11 \
    c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.cpp \
    porter2_stemmer.cpp \
    documentparser.cpp \
    csvparser.c

HEADERS += catch.hpp \
    porter2_stemmer.h \
    util/hash.h \
    util/stringview.h \
    avltree.hpp \
    hashtable.hpp \
    indexinterface.hpp \
    documentparser.h \
    csv.h \
    csvparser.h

DISTFILES += \
    ../../fast-cpp-csv-parser-master.zip
