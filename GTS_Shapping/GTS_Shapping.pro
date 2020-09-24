#-------------------------------------------------
#
# Project created by QtCreator 2020-08-13T22:57:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GTS_Shapping
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
RC_ICONS = lufei.ico
CONFIG += C++11

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release/ -lgts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug/ -lgts
else:unix: LIBS += -L$$PWD/ -lgts

INCLUDEPATH += $$PWD/debug
DEPENDPATH += $$PWD/debug

