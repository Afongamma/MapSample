#-------------------------------------------------
#
# Project created by QtCreator 2016-12-02T09:20:08
#
#-------------------------------------------------

QT += core
QT += core gui
QT += network

CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapSample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cmap.cpp \
    c_config.cpp \
    c_camera.cpp

HEADERS  += mainwindow.h \
    cmap.h \
    c_config.h \
    c_camera.h

FORMS    += mainwindow.ui
