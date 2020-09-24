#-------------------------------------------------
#
# Project created by QtCreator 2020-06-03T15:20:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_MESSAGELOGCONTEXT
TARGET = GT_GoHome
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    mylabel.cpp

HEADERS  += mymainwindow.h \
    mylabel.h

FORMS    += mymainwindow.ui

unix|win32: LIBS += -L$$PWD/ -lgts

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

RESOURCES += \
    image.qrc
CONFIG += C++11
