include(../defaults.pri)

QT += network
QT += core

CONFIG += console
CONFIG -= app_bundle

TARGET = mylib
TEMPLATE = lib

SOURCES += \
	client/client.cpp

HEADERS += \
	client/client.h
