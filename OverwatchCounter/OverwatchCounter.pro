#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T12:18:52
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OverwatchCounter
QTPLUGIN += QSQLMYSQL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hero.cpp \
    herocontroller.cpp

HEADERS  += mainwindow.h \
    hero.h \
    herocontroller.h \
    herolistitem.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
