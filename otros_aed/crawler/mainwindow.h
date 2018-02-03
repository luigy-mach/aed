#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

#include "proceso.h"
#include "parseador.h"
#include "includes.h"
#include "archivo.h"
#include "crawler.h"



// ----------------------------c++11-------------------------------
#include<QtWebKitWidgets/QWebView>
#include <unordered_map>

//-----------------------------------------------------------------


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_buscar_clicked();

    void on_pushButton_index_offline_clicked();

private:
    Ui::MainWindow *ui;

    Parseador* my_parser;
    Crawler* my_crawler;

    QString link;
    int profundidad;
    int limite_link_por_pagina;
    Archivo * archivos_principal;

    void imprimir();
    //----------------------------------------
    typedef pair<int,int> PESO;
    typedef typename unordered_multimap<string,PESO>::iterator IT;
    IT it;
    unordered_multimap<string,PESO> a_la_mela;
    //----------------------------------------



};

#endif // MAINWINDOW_H
