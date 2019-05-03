include(../defaults.pri)

QT += network
QT += core
QT += widgets

CONFIG += console
CONFIG -= app_bundle

TARGET = mylib
TEMPLATE = lib

SOURCES += \
	client/client.cpp \
	client/clientinterface.cpp \
	graph/map.cpp \
	graph/mapfiles.cpp \
	graph/node.cpp \
	json/jsonconverter.cpp \
	json/jsonserializer.cpp \
	game/populations.cpp \
	game/entities/gladiator.cpp \
	game/entities/tower.cpp \
    util/math.cpp \
    util/collision.cpp \
    game/populationsmock.cpp

HEADERS += \
	client/client.h \
	client/clientinterface.h \
	graph/map.h \
	graph/mapfiles.h \
	graph/node.h \
	json/jsonconverter.h \
	json/jsonserializable.h \
	json/jsonserializer.h \
	game/populations.h \
	game/entities/gladiator.h \
	game/entities/tower.h \
    util/math.h \
    game/entities/entity.h \
    util/collision.h \
    game/populationsmock.h
