#-------------------------------------------------
#
# Project created by QtCreator 2014-10-14T15:55:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diccionario
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    recursos/word.cpp \
    recursos/record.cpp

HEADERS  += mainwindow.h \
    recursos/defines.h \
    recursos/nodo.h \
    recursos/lista_doble.h \
    recursos/estructura.h \
    recursos/btree.h \
    recursos/avl.h \
    recursos/word.h \
    recursos/record.h

FORMS    += mainwindow.ui
