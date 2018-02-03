#include "mainwindow.h"
#include "ui_mainwindow.h"
/////////////////////////////////////////

#include <iostream>
#include "grafo_01.h"
#define no_visitado -1
#define infinito 9999

/////////////////////////////////////////
using namespace std;


#define TAM_NODO 20



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//---------------------------------------------------------
    scene= new QGraphicsScene(this);
    ui->pushButton_reset->setDisabled(true);
    //grafo=new Grafo<int>;

//---------------------------------------------------------
}


MainWindow::~MainWindow()
{
    delete ui;
}

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
    list<int> vertices;
    grafo.devolverVertices(vertices);
    list<int>::iterator v;
    v = vertices.begin();
    cout << endl << "//------------------------------- GRAFO ------------------------------------//" << endl << endl;
    while ( v!=vertices.end() )
    {
        salida<<"Vertice: "<< *v << endl;
            list<typename Grafo<C>::Arco> adyacentes;
            grafo.devolverAdyacentes(*v, adyacentes);
            typename list<typename Grafo<C>::Arco>::iterator ady;
            ady = adyacentes.begin();
        while (ady != adyacentes.end())
        {
            salida << "            " << "-> " << ady->devolverAdyacente() << " con costo: (" << ady->costo_arco << ")" << endl;
            ady++;
        }
        v++;
        cout << endl;
    }
    cout << "//-------------------------------------------------------------------------//" << endl << endl;
    return salida;
}



void MainWindow::dibujar_nodo(double x,double y, string text, QBrush paleta, QPen pen){

    scene->addEllipse(x-TAM_NODO/2,y-TAM_NODO/2,TAM_NODO,TAM_NODO,pen,paleta.color());
    QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(x,y);
        io->setPlainText(QString::fromStdString(text));
    scene->addItem(io);

//  ui->graphicsView_pantalla->setScene(scene);
}

void MainWindow::dibujar_linea(double xi,double yi,double xf,double yf, string text, QPen pen){
    scene->addLine(xi,yi,xf,yf,pen);
    QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos((xi+xf)/2,(yi+yf)/2);
        io->setPlainText(QString::fromStdString(text));
    scene->addItem(io);

//  ui->graphicsView_pantalla->setScene(scene);

}

void MainWindow::generar_grafo_random(int num_vertices){

    matriz= new int*[num_vertices];
    for(int i=0;i<num_vertices;i++)
        matriz[i]=new int[num_vertices];


    for(int i=0;i<num_vertices;i++)
        for(int j=0;j<num_vertices;j++)
            matriz[i][j]=0;

    for(int i=0;i<num_vertices;i++)
        for(int j=0;j<num_vertices;j++)
            if(qrand()%101==0 && i!=j)
                matriz[i][j]=1;

    /*for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++)
            cout<<" "<<matriz[i][j];
        cout<<endl;
    }
    cout<<"------------------------"<<endl;
    */
    for(int i=0;i<num_vertices;i++){
        Nodo temp;
            temp.vertice=i;
            temp.x=qrand()%2000;
            temp.y=qrand()%2000;
        nodos_random.push_back(temp);
        grafo->agregarVertice(temp.vertice,temp.x,temp.y);
    }

    for(int i=0;i<num_vertices;i++){
        for(int j=0;j<num_vertices;j++)
            if(matriz[i][j]==1)
                grafo->agregarArco(nodos_random[i].vertice,nodos_random[j].vertice,qrand()%num_vertices);
    }
}


void MainWindow::dibuja_grafo(){

    QBrush paleta;
    paleta.setColor(Qt::black);
    QPen pen;
    pen.setColor(Qt::black);

    list<int> vertices;
    grafo->devolverVertices(vertices);
    list<int>::iterator v;
    v = vertices.begin();
    while ( v!=vertices.end() )
    {
        dibujar_nodo(nodos_random[*v].x,nodos_random[*v].y,(QString::number(*v)).toStdString(),paleta,pen);
        //cout<<"Vertice: "<< *v << endl;
            list<typename Grafo<int>::Arco> adyacentes;
            grafo->devolverAdyacentes(*v, adyacentes);
            typename list<typename Grafo<int>::Arco>::iterator ady;
            ady = adyacentes.begin();
        while (ady != adyacentes.end())
        {
            dibujar_linea(nodos_random[*v].x,nodos_random[*v].y,
                          nodos_random[ady->devolverAdyacente()].x,nodos_random[ady->devolverAdyacente()].y,
                          QString::number(ady->devolverAdyacente()).toStdString(),pen);
                          //cout << "            " << "-> " << ady->devolverAdyacente() << " con costo: (" << ady->costo_arco << ")" << endl;
            ady++;
        }
        v++;
       //cout << endl;
    }

}




//-------------------------------------------/------------------------------
//--------------------------------------DISKJTRA----------------------------
//-------------------------------------------------------------------------

//---------------------------------------------------------------------//
using namespace std;


struct MainWindow::estruc_etiqueta_diskjtra{
            int padre;
            int acumulada;
};

void MainWindow::inicializa_estructura(list<int> vertices, int marca_visitados[], estruc_etiqueta_diskjtra etiqueta[])
{
    list<int>::const_iterator iterador;
    for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
    {
        marca_visitados[*iterador] = no_visitado;
        etiqueta[*iterador].padre = no_visitado;
        etiqueta[*iterador].acumulada = infinito;
    }
}

int MainWindow::extraer_minima_acumulada(list<int> &vertices, estruc_etiqueta_diskjtra etiqueta[])
{
    list<int>::const_iterator iterador;
    int minimo;
    minimo = infinito;
    int nodo;
    for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
        if(minimo > etiqueta[*iterador].acumulada)
        {
            minimo = etiqueta[*iterador].acumulada;
            nodo = *iterador;
        }
    vertices.remove(nodo);
    return nodo;
}


void MainWindow::dijkstra(Grafo<int>* grafo1, int fuente, estruc_etiqueta_diskjtra etiqueta[], list<int> &vertices)
{
    etiqueta[fuente].acumulada = 0;
    etiqueta[fuente].padre = 0;
    while(!vertices.empty())
    {
        int nodo = extraer_minima_acumulada(vertices, etiqueta);
        list<Grafo<int>::Arco> adyacentes;
        grafo1->devolverAdyacentes(nodo, adyacentes);
        list<Grafo<int>::Arco>::const_iterator iterador_adyacente;
        for(iterador_adyacente = adyacentes.begin(); iterador_adyacente != adyacentes.end(); iterador_adyacente++)
        {
            if(etiqueta[iterador_adyacente->devolverAdyacente()].acumulada > (etiqueta[nodo].acumulada + grafo1->costoArco(nodo, iterador_adyacente->devolverAdyacente())))
            {
                etiqueta[iterador_adyacente->devolverAdyacente()].acumulada = (etiqueta[nodo].acumulada + grafo1->costoArco(nodo, iterador_adyacente->devolverAdyacente()));
                etiqueta[iterador_adyacente->devolverAdyacente()].padre = nodo;
            }
        }
        adyacentes.clear();
    }
}

//-------------------------------------------------------------------------
//--------------------------------------PRIM----------------------------
//-------------------------------------------------------------------------

//---------------------------------------------------------------------//
struct MainWindow::estruc_etique_prim{
            int padre;
            int costo;
       };
//---------------------------------------------------------------------//

bool MainWindow::existe_en_lista(int nodo, list<int> vertices_visitados)
{
    list<int>::const_iterator iterador;
    bool existe = false;
    for(iterador = vertices_visitados.begin(); iterador != vertices_visitados.end(); iterador++)
        if(*iterador == nodo)
            existe = true;
    return existe;
}
//---------------------------------------------------------------------//

int MainWindow::extraer_minimo(Grafo<int> grafo1, list<int> &vertices, list<int> &vertices_visitados, estruc_etique_prim etiqueta[])
{
    list<int>::const_iterator iterador;
    int costo, origen, destino;
    costo = infinito;
    for(iterador = vertices_visitados.begin(); iterador != vertices_visitados.end(); iterador++)
    {
        list<Grafo<int>::Arco> adyacentes;
        grafo1.devolverAdyacentes(*iterador, adyacentes);
        list<Grafo<int>::Arco>::const_iterator iterador_adyacente;
        for(iterador_adyacente = adyacentes.begin(); iterador_adyacente != adyacentes.end(); iterador_adyacente++)
            if(existe_en_lista(iterador_adyacente->devolverAdyacente(), vertices_visitados) == false)
                if(costo > grafo1.costoArco(*iterador, iterador_adyacente->devolverAdyacente()))
                {
                    costo = grafo1.costoArco(*iterador, iterador_adyacente->devolverAdyacente());
                    origen = *iterador;
                    destino = iterador_adyacente->devolverAdyacente();
                }
    }
    etiqueta[destino].padre = origen;
    etiqueta[destino].costo = costo;
    return destino;
}
//---------------------------------------------------------------------//

void MainWindow::Prim(Grafo<int> grafo1, estruc_etique_prim etiqueta[], list<int> &vertices, list<int> &vertices_visitados)
{
    list<int>::const_iterator iterador;
    iterador = vertices.begin();
    etiqueta[*iterador].costo = 0;
    etiqueta[*iterador].padre = 0;
    vertices_visitados.push_front(*iterador);
    vertices.remove(*iterador);
    while(!vertices.empty())
    {
        int nodo = extraer_minimo(grafo1, vertices, vertices_visitados, etiqueta);
        vertices_visitados.push_back(nodo);
        vertices.remove(nodo);
    }
}


//-------------------------------------------------------------------------
//--------------------------------------KRUSKAL----------------------------
//-------------------------------------------------------------------------





//-------------------------------------------------------------------------
//--------------------------------------BOTONES----------------------------
//-------------------------------------------------------------------------


void MainWindow::on_pushButton_random_clicked()
{

    int cantidad=ui->spinBox->text().toInt();
    generar_grafo_random(cantidad);
    dibuja_grafo();
    ui->graphicsView_pantalla->setScene(scene);

    //---------------------------------------

    ui->pushButton_random->setDisabled(true);
    ui->pushButton_reset->setDisabled(false);
}



void MainWindow::on_pushButton_reset_clicked()
{
    //***************************
        grafo->vaciar();
    //****************************
    ui->pushButton_random->setDisabled(false);
    scene->clear();
    scene->setBackgroundBrush(QBrush(Qt::white));

    ui->graphicsView_pantalla->setScene(scene);
    ui->pushButton_reset->setDisabled(true);
    ui->pushButton_random->setDisabled(false);
}

void MainWindow::on_pushButton_dijkstra_clicked()
{
      list<int> vertices;
      grafo->devolverVertices(vertices);

      int marca_visitados[vertices.size()];
      estruc_etiqueta_diskjtra etiqueta[vertices.size()];

      inicializa_estructura(vertices, marca_visitados, etiqueta);

      list<int>::const_iterator iterador;
      iterador = vertices.begin();

      dijkstra(grafo, *iterador, etiqueta, vertices);
      grafo->devolverVertices(vertices);

      for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
      {
          cout << "Vertice: " << *iterador << endl;
          cout << "Padre: " << etiqueta[*iterador].padre << endl;
          cout << "Acumulada: " << etiqueta[*iterador].acumulada << endl;
          cout << "//-------------------------------------//" << endl << endl;
      }

}






void MainWindow::on_pushButton_prim_clicked()
{
       //Grafo<int> grafo;
       //cargar_grafo(grafo);
       list<int> vertices;
       grafo.devolverVertices(vertices);
       list<int>::const_iterator iterador;
       estruc_etique_prim etiqueta[vertices.size()];
       for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
       {
           etiqueta[*iterador].padre = no_visitado;
           etiqueta[*iterador].costo = infinito;
       }
       list<int> vertices_visitados;
       Prim(grafo, etiqueta, vertices, vertices_visitados);
       cout << "//-----------------PRIM-------------//" << endl << endl;
       list<int>::const_iterator iterador_visitados;
       for(iterador_visitados = vertices_visitados.begin(); iterador_visitados != vertices_visitados.end(); iterador_visitados++)
       {
           cout << "//------------------------------//" << endl;
           cout << "Nodo: " << *iterador_visitados << endl;
           cout << "Padre: " << etiqueta[*iterador_visitados].padre << endl;
           cout << "Costo: " << etiqueta[*iterador_visitados].costo << endl;
       }


}

void MainWindow::on_pushButton_kruskal_clicked()
{


}
