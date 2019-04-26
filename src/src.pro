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
	game/map.cpp \
	game/node.cpp \
	json/jsonconverter.cpp \
	json/jsonserializer.cpp \
	game/populations.cpp \
	game/entities/gladiator.cpp \
	game/entities/tower.cpp

HEADERS += \
	client/client.h \
	client/clientinterface.h \
	game/entities/entity.h \
	game/map.h \
	game/node.h \
	json/jsonconverter.h \
	json/jsonserializable.h \
	json/jsonserializer.h \
	game/populations.h \
	game/entities/gladiator.h \
	game/entities/tower.h
