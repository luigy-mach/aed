#-------------------------------------------------
#
# Project created by QtCreator 2014-12-08T09:55:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crawler_part_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crawler.cpp \
    archivo.cpp

HEADERS  += mainwindow.h \
    crawler.h \
    archivo.h

FORMS    += mainwindow.ui

CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11
