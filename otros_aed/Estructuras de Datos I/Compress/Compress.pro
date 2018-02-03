#-------------------------------------------------
#
# Project created by QtCreator 2011-12-09T21:35:49
#
#-------------------------------------------------

QT       += core gui
TARGET = Compress
TEMPLATE = app

soundFiles.sources = /home/rene/Escritorio/Compress-build-desktop/sonido.wav;
DEPLOYMENT += soundFiles

CONFIG += mobility
MOBILITY = multimedia

SOURCES += main.cpp\
        mainwindow.cpp \
    binarizacion.cpp
LIBS += -fopenmp -lgomp

HEADERS  += mainwindow.h \
    quadtree.h \
    matrize.h \
    binarizacion.h \
    CImg.h \
    comprensor.h

FORMS    += mainwindow.ui

