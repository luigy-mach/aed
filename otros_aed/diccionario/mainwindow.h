#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QListWidgetItem>
////////////////////////////////////////////
#include "recursos/estructura.h"
#include "recursos/nodo.h"

#include "recursos/avl.h"
#include "recursos/lista_doble.h"
#include "recursos/defines.h"
#include "recursos/word.h"
#include "recursos/record.h"
////////////////////////////////////////////

#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string>
#include<iostream>
#include<time.h>
#include<vector>
#include <algorithm>

using namespace std;
///////////////////////////////////////////////////
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
    void on_pushButton_buscar_clicked();

    void on_pushButton_index_clicked();

    void on_pushButton_mostrar_index_clicked();

////////////////////////////////////////////////////

public slots:
    void mostrar_traduccion_de_similar(QListWidgetItem* item);

private:
    Ui::MainWindow *ui;
////////////////////////////////////////////////////

    std::fstream database;
    std::string buffer;
    Estructura< Record* >* f;
    vector< Record* > v_similares;

    clock_t t_ini, t_fin;
    double secs;

/////////////////////////////////////////////////////
//-------------UI---------------------
public:
    int levenshtein(const string &s1, const string &s2);
    void buscar_similares(Record& in,int num_similitud);
    void mostrar_traduccion(QString traduccion);
    void mostrar_traduccion_clear();
    void mostrar_error(QString mensaje);

////////////////////////////////////////////////////
//-------------LECTURA---------------------
    int length_buffer();
    bool open_file(string file);
    void read_file();
    void close_file();
    void read_buffer(string& palabra,string& traduccion);
    string read_palabra();
    void indexing(Estructura< Record* >*& f);
    //----------------------------------
    void seekg_word(Word& w);


};

#endif // MAINWINDOW_H
