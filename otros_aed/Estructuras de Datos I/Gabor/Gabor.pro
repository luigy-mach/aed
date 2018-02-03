#-------------------------------------------------
#
# Project created by QtCreator 2011-11-22T21:39:46
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Gabor
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    image.cpp \
    gradicador.cpp \
    grafo.cpp

LIBS+=-O2 -L/usr/X11R6/lib -lm -lpthread -lX11\
    -lgraph-lgvc\
    -L/home/josemiki/Library/Torch3vision2.1/lib/Linux_DGB_FLOAT/-ltorch\
    -lpthread\
    /home/josemiki/Library/Torch3vision2.1/core\
    /home/josemiki/Library/Torch3vision2.1/vision2.1/core

HEADERS += \
    image.h \
    gradicador.h \
    grafo.h
