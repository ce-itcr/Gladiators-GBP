include(../defaults.pri)

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  main.cpp \
	default/tst_default.cpp \
	game/tst_maptest.cpp \
	graph/tst_mapfilestest.cpp \
	json/tst_jsonconvertertest.cpp

HEADERS += \
	default/tst_default.h \
	game/tst_maptest.h \
	graph/tst_mapfilestest.h \
	json/tst_jsonconvertertest.h

LIBS += -L../src -lmylib
