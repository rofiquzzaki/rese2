#-------------------------------------------------
#
# Project created by QtCreator 2015-12-21T20:56:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rese1
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    suruh.cpp \
    pasuot.cpp

HEADERS  += widget.h \
    suruh.h \
    pasuot.h

FORMS    += widget.ui

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lssh

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include
