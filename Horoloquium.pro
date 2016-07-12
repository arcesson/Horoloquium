#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T16:24:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Horoloquium
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/about.cpp

HEADERS  += src/mainwindow.h \
    src/about.h

FORMS    += src/mainwindow.ui \
    src/about.ui

TRANSLATIONS = \
        translations/Horoloquium_en.ts \
