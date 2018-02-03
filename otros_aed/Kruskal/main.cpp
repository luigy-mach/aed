#include <iostream>
#include "Grafo.h"
#include "windows.h"
#define nulo -1
#define infinito 9999
//------------------------------------------------------//
using namespace std;
//------------------------------------------------------//
struct Tarista{
    int origen;
    int destino;
    int costo;
};
//------------------------------------------------------//
void inicializar (Grafo<int> grafo,list<Tarista> & cola,int  arbol[])
{
//inicializa los arreglos distancia y padre y la lista de aristas (cola)
    list<int> vertices;
    list<Grafo<int>::Arco> adyacentes;
    grafo.devolverVertices(vertices);
    list<int>::const_iterator it_vert;
    for(it_vert = vertices.begin(); it_vert != vertices.end(); it_vert++)
    {
        grafo.devolverAdyacentes(*it_vert,adyacentes);
        arbol[*it_vert] = *it_vert;
        list<Grafo<int>::Arco>::const_iterator it_ady;
        for( it_ady = adyacentes.begin(); it_ady != adyacentes.end(); it_ady++)
            if (grafo.existeArco(*it_vert,it_ady->devolverAdyacente()))
            {
                Tarista arista;
                arista.origen = *it_vert;
                arista.destino = it_ady -> devolverAdyacente();
                arista.costo = it_ady -> devolverCosto();
                cola.push_front(arista);
            }
        adyacentes.clear();
    }
}
//------------------------------------------------------//
void extraerMinimo(list<Tarista> & aristas,Tarista & minima)
{
    list<Tarista>::iterator it;
    list<Tarista>::iterator borrar;
    int min_costo = infinito;
    for(it = aristas.begin(); it != aristas.end(); it++)
        if (it->costo < min_costo)
        {
            borrar = it;
            min_costo = it->costo;
        }
     minima.origen = borrar->origen;
     minima.destino = borrar->destino;
     minima.costo = borrar->costo;
     aristas.erase(borrar);
}
//------------------------------------------------------//
void mostrar(list<Tarista> solucion)
{
    list<Tarista>::const_iterator it;
    cout << "Arbol de minimo costo " << endl << endl;
    int suma = 0;
    for(it = solucion.begin(); it != solucion.end(); it++)
    {
        cout << "(" << it->origen << "," << it->destino << ") = " << it->costo << endl;
        suma = suma + it->costo;
    }
    cout << endl << "Costo = " << suma << endl;
}
//------------------------------------------------------//
bool mismo_arbol(int arbol[],int origen, int destino)
{
    if (arbol[origen] == arbol[destino])
        return true;
    return false;
}
//------------------------------------------------------//
void actualizar(int arbol[],int longitud,int origen,int destino)
{
    int n_arb = arbol[destino];
    for(int indice = 0; indice<longitud;indice++)
        if (arbol[indice] == n_arb)
            arbol[indice] = arbol[origen];

}
//------------------------------------------------------//
void kruskal(const Grafo<int> & grafo)
{
    list<Tarista> aristas;
    list<Tarista> solucion;
    int arbol[grafo.devolverLongitud()]; //cada vertice inicialmente tiene definido un arbol ( arbol = # de vertice)
    inicializar(grafo,aristas,arbol);
    Tarista minima;
    while (!aristas.empty())
    {
        extraerMinimo(aristas,minima);
        if (!mismo_arbol(arbol,minima.origen,minima.destino))
        {
            solucion.push_back(minima);
            actualizar(arbol,grafo.devolverLongitud(),minima.origen,minima.destino);
        }
    }
    mostrar(solucion);
}
//------------------------------------------------------//
void cargar_grafo(Grafo<int> &grafo)
{
    grafo.agregarVertice(0);
    grafo.agregarVertice(1);
    grafo.agregarVertice(2);
    grafo.agregarVertice(3);
    grafo.agregarVertice(4);
    grafo.agregarVertice(5);
    grafo.agregarVertice(6);
    grafo.agregarArco(3,0,5);
    grafo.agregarArco(0,3,5);
    grafo.agregarArco(2,4,5);
    grafo.agregarArco(4,2,5);
    grafo.agregarArco(3,5,6);
    grafo.agregarArco(5,3,6);
    grafo.agregarArco(0,1,7);
    grafo.agregarArco(1,0,7);
    grafo.agregarArco(1,2,8);
    grafo.agregarArco(2,1,8);
    grafo.agregarArco(5,4,8);
    grafo.agregarArco(4,5,8);
    grafo.agregarArco(1,3,9);
    grafo.agregarArco(3,1,9);
    grafo.agregarArco(4,6,9);
    grafo.agregarArco(6,4,9);
    grafo.agregarArco(5,6,11);
    grafo.agregarArco(6,5,11);
    grafo.agregarArco(3,4,15);
    grafo.agregarArco(4,3,15);
    grafo.agregarArco(1,4,7);
    grafo.agregarArco(4,1,7);
    cout << grafo;
}
//------------------------------------------------------//
int main(){
    Grafo<int> grafo1;
    cargar_grafo(grafo1);
    kruskal(grafo1);
}
//------------------------------------------------------//
