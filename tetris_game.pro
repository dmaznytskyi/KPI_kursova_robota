#-------------------------------------------------
#
# Project created by QtCreator 2017-04-23T16:08:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tetris_game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        gamewidget.cpp \
    game.cpp \
    state.cpp \
    gameobject.cpp \
    log.cpp \
    loading.cpp \
    menu.cpp \
    factory.cpp \
    block.cpp \
    tetris.cpp \
    tetrimino.cpp \
    text.cpp \
    data_player.cpp \
    scoreboard.cpp \
    about.cpp

HEADERS  += gamewidget.h \
    game.h \
    state.h \
    gameobject.h \
    log.h \
    loading.h \
    menu.h \
    factory.h \
    block.h \
    tetris.h \
    tetrimino.h \
    text.h \
    data_player.h \
    scoreboard.h \
    about.h
     

RESOURCES += \
    res.qrc
