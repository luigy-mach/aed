#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


///***********************************************************
///***********************************************************
#include "recursos/estructura.h"
#include "recursos/nodo.h"

#include "recursos/avl.h"
#include "recursos/lista_doble.h"
#include "recursos/record.h"
#include "recursos/defines.h"
#include "dialog_button_insertar.h"
//////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<iostream>
#include <time.h>
using namespace std;

///***********************************************************
///***********************************************************

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

    void on_pushButton_insetar_clicked();

    void on_pushButton_index_clicked();

    void on_pushButton_buscar_clicked();

    void on_pushButton_final_clicked();

    void on_pushButton_siguiente_clicked();

    void on_pushButton_anterior_clicked();

    void on_pushButton_inicio_clicked();

    void on_pushButton_borrar_clicked();

    void on_pushButton_index_2_clicked();

private:
    Ui::MainWindow *ui;
////////////////////////////////////////
public:
    std::fstream database;
    std::string buffer;
    Estructura< Record* >* f;
    Record* pRactual;
    Record* pRfinal_archivo;
    clock_t t_ini, t_fin;
    double secs;
    Dialog_button_insertar* abrir_foto;
////////////////////////////////////////
//-------------UI---------------------
public:
    void mostrar_modelo(QString modelo);
    void mostrar_descripcion(QString descripcion);
    void mostrar_foto(QString dir_foto);
    void mostrar_error(QString mensaje);
    void agregar_record(string mo,string de,string dir_f);
////////////////////////////////////////
//-------------LECTURA---------------------
    int char_to_int(char a);
    int length_buffer();
    bool open_file(string file);
    void read_file();
    void close_file();
    void read_buffer(int& available,string& model,string& description, string& photo );
    int read_available();
    string read_model();
    void indexing(Estructura< Record* >*& f);
    //----------------------------------
    void seekg_record(Record& r);
    void seekp_off(Record& r);
    void seekp_on(Record& r);

};

#endif // MAINWINDOW_H
