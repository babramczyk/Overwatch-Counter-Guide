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
    herocontroller.cpp \
    role.cpp

HEADERS  += mainwindow.h \
    hero.h \
    herocontroller.h \
    herolistitem.h \
    role.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc

DEFINES += MYSQL_USER=\\\"root\\\"
DEFINES += MYSQL_PASS=\\\"\\\"
DEFINES += MYSQL_HOST=\\\"127.0.0.1\\\"
DEFINES += MYSQL_DB=\\\"overwatch_counter_guide\\\"
