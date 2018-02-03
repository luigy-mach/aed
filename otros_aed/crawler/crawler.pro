#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T11:21:36
#
#-------------------------------------------------

QT       += core gui webkitwidgets
QT += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = crawler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    proceso.cpp \
    parseador.cpp \
    defines.cpp \
    includes.cpp \
    archivo.cpp \
    crawler.cpp

HEADERS  += mainwindow.h \
    proceso.h \
    parseador.h \
    defines.h \
    includes.h \
    archivo.h \
    crawler.h

FORMS    += mainwindow.ui



#-------configurando c++11------XD!!
CONFIG += c++11
#------------------------------------
