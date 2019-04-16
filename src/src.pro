include(../defaults.pri)

QT += network
QT += core

CONFIG += console
CONFIG -= app_bundle

TARGET = mylib
TEMPLATE = lib

SOURCES += \
	client/client.cpp \
	client/clientinterface.cpp \
	entities/gladiator.cpp

HEADERS += \
	client/client.h \
	client/clientinterface.h \
	entities/gladiator.h
