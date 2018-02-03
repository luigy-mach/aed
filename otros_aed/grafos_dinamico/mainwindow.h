#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



/////////////////////////////////////////
#include "iostream"
#include "QGraphicsScene"
#include "QPen"
#include "QGraphicsItem"
#include "string"

//--------------------------
    #include "grafo_01.h"
//--------------------------
using namespace std;
/////////////////////////////////////////


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
    void on_pushButton_random_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_dijkstra_clicked();

    void on_pushButton_prim_clicked();


    void on_pushButton_kruskal_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    Grafo<int> grafo->;
    vector<Nodo> nodos_random;
    int** matriz;


    void dibujar_nodo(double x,double y, string text, QBrush paleta, QPen pen);
    void dibujar_linea(double xi,double yi,double xf,double yf, string text, QPen pen);
    void generar_grafo_random(int num_vertices);
    void dibuja_grafo();

    struct estruc_etiqueta_diskjtra;

    //-------diskjtra------
        void inicializa_estructura(list<int> vertices, int marca_visitados[], estruc_etiqueta_diskjtra etiqueta[]);
        int extraer_minima_acumulada(list<int> &vertices, estruc_etiqueta_diskjtra etiqueta[]);
        void dijkstra(Grafo<int>* grafo1, int fuente, estruc_etiqueta_diskjtra etiqueta[], list<int> &vertices);
    //-------prim------
        struct estruc_etique_prim;
        bool existe_en_lista(int nodo, list<int> vertices_visitados);
        int extraer_minimo(Grafo<int> grafo1, list<int> &vertices, list<int> &vertices_visitados, estruc_etique_prim etiqueta[]);
        void Prim(Grafo<int> grafo1, estruc_etique_prim etiqueta[], list<int> &vertices, list<int> &vertices_visitados);


    //-------kruskal------
};

#endif // MAINWINDOW_H
