QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rese2
TEMPLATE = app


HEADERS += \
    pasuot.h \
    suruh.h \
    widget.h

SOURCES += \
    pasuot.cpp \
    main.cpp \
    suruh.cpp \
    widget.cpp

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/ -lssh

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include
