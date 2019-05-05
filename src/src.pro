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
	graph/node.cpp \
	json/jsonconverter.cpp \
	json/jsonserializer.cpp \
	game/populations.cpp \
	game/entities/gladiator.cpp \
	game/entities/tower.cpp \
    util/math.cpp \
    util/collision.cpp \
    game/populationsmock.cpp \
    graph/PathFinding/astar.cpp \
    graph/PathFinding/backtrack.cpp \
    graph/PathFinding/list.cpp \
    graph/PathFinding/nodelinkedlist.cpp \
    graph/PathFinding/vector.cpp \
    graph/PathFinding/point.cpp \
    graph/PathFinding/astardata.cpp \
    graph/PathFinding/map.cpp

HEADERS += \
	client/client.h \
	client/clientinterface.h \
	graph/map.h \
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
    game/populationsmock.h \
    graph/PathFinding/astar.h \
    graph/PathFinding/backtrack.h \
    graph/PathFinding/list.h \
    graph/PathFinding/nodelinkedlist.h \
    graph/PathFinding/vector.h \
    graph/PathFinding/point.h \
    graph/PathFinding/astardata.h \
    graph/PathFinding/map.h

