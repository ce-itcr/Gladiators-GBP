include(../defaults.pri)

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  main.cpp \
	default/tst_default.cpp

HEADERS += \
	default/tst_default.h

LIBS += -L../src -lmylib
