TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../gtest/googletest/src/gtest-all.cc \
    test.cpp

HEADERS += \
    merge_sort.h

INCLUDEPATH = \
    ../gtest/googletest/include \
    ../gtest/googletest
