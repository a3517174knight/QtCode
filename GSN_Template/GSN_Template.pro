#-------------------------------------------------
#
# Project created by QtCreator 2020-08-17T11:47:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GSN_Template
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RC_ICONS = lufei.ico

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release/ -lgts
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug/ -lgts
else:unix: LIBS += -L$$PWD/ -lgts

INCLUDEPATH += $$PWD/debug
DEPENDPATH += $$PWD/debug
