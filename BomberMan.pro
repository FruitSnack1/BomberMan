#-------------------------------------------------
#
# Project created by QtCreator 2017-05-26T08:49:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BomberMan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    map.cpp \
    player.cpp \
    enemy.cpp \
    bomb.cpp

HEADERS  += mainwindow.h \
    view.h \
    map.h \
    player.h \
    enemy.h \
    bomb.h

FORMS    += mainwindow.ui
