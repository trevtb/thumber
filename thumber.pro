#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T11:33:50
#
#-------------------------------------------------

QT  += core gui concurrent

TARGET = thumber
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    thumbcreator.cpp

INCLUDEPATH += /usr/include/ImageMagick/

HEADERS += \
    thumbcreator.h
