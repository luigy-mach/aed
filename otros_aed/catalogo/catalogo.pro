#-------------------------------------------------
#
# Project created by QtCreator 2014-10-04T19:35:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = catalogo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    recursos/record.cpp \
    recursos/load_file.cpp \
    dialog_button_insertar.cpp

HEADERS  += mainwindow.h \
    recursos/record.h \
    recursos/nodo.h \
    recursos/estructura.h \
    recursos/btree.h \
    recursos/avl.h \
    recursos/lista_doble.h \
    recursos/defines.h \
    dialog_button_insertar.h

FORMS    += mainwindow.ui \
    dialog_button_insertar.ui
