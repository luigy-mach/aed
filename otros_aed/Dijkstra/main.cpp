#include <iostream>
#include "Grafo.h"
#include "windows.h"
#define no_visitado -1
#define infinito 9999
//---------------------------------------------------------------------//
using namespace std;
//---------------------------------------------------------------------//


//---------------------------------------------------------------------//
void cargar_grafo(Grafo<int> &grafo1)
{
    grafo1.agregarVertice(1);
    grafo1.agregarVertice(2);
    grafo1.agregarVertice(3);
    grafo1.agregarVertice(4);
    grafo1.agregarVertice(5);
    grafo1.agregarVertice(6);
    grafo1.agregarVertice(7);
    grafo1.agregarArco(1,2,3);
    grafo1.agregarArco(1,4,3);
    grafo1.agregarArco(2,5,2);
    grafo1.agregarArco(2,3,1);
    grafo1.agregarArco(3,5,3);
    grafo1.agregarArco(3,6,2);
    grafo1.agregarArco(4,3,2);
    grafo1.agregarArco(4,7,3);
    grafo1.agregarArco(5,6,3);
    grafo1.agregarArco(6,4,1);
    grafo1.agregarArco(6,7,2);
    cout << grafo1 << endl;
}
//---------------------------------------------------------------------//

struct estructura_etiqueta{
            int padre;
            int acumulada;
};

void inicializa_estructura(list<int> vertices, int marca_visitados[], estructura_etiqueta etiqueta[])
{
    list<int>::const_iterator iterador;
    for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
    {
        marca_visitados[*iterador] = no_visitado;
        etiqueta[*iterador].padre = no_visitado;
        etiqueta[*iterador].acumulada = infinito;
    }
}
//---------------------------------------------------------------------//
int extraer_minima_acumulada(list<int> &vertices, estructura_etiqueta etiqueta[])
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
//---------------------------------------------------------------------//
void dijkstra(Grafo<int> grafo1, int fuente, estructura_etiqueta etiqueta[], list<int> &vertices)
{
    etiqueta[fuente].acumulada = 0;
    etiqueta[fuente].padre = 0;
    while(!vertices.empty())
    {
        int nodo = extraer_minima_acumulada(vertices, etiqueta);
        list<Grafo<int>::Arco> adyacentes;
        grafo1.devolverAdyacentes(nodo, adyacentes);
        list<Grafo<int>::Arco>::const_iterator iterador_adyacente;
        for(iterador_adyacente = adyacentes.begin(); iterador_adyacente != adyacentes.end(); iterador_adyacente++)
        {
            if(etiqueta[iterador_adyacente->devolverAdyacente()].acumulada > (etiqueta[nodo].acumulada + grafo1.costoArco(nodo, iterador_adyacente->devolverAdyacente())))
            {
                etiqueta[iterador_adyacente->devolverAdyacente()].acumulada = (etiqueta[nodo].acumulada + grafo1.costoArco(nodo, iterador_adyacente->devolverAdyacente()));
                etiqueta[iterador_adyacente->devolverAdyacente()].padre = nodo;
            }
        }
        adyacentes.clear();
    }
}
//---------------------------------------------------------------------//
int main()
{
    Grafo<int> grafo1;
    cargar_grafo(grafo1);

    list<int> vertices;
    grafo1.devolverVertices(vertices);

    int marca_visitados[vertices.size()];
    estructura_etiqueta etiqueta[vertices.size()];

    inicializa_estructura(vertices, marca_visitados, etiqueta);

    list<int>::const_iterator iterador;
    iterador = vertices.begin();

    dijkstra(grafo1, *iterador, etiqueta, vertices);  //*iterador es el nodo fuente
    grafo1.devolverVertices(vertices);

    cout << "//------------------Dijkstra-------------------//" << endl << endl;

    for(iterador = vertices.begin(); iterador != vertices.end(); iterador++)
    {
        cout << "Verice: " << *iterador << endl;
        cout << "Padre: " << etiqueta[*iterador].padre << endl;
        cout << "Acumulada: " << etiqueta[*iterador].acumulada << endl;
        cout << "//-------------------------------------//" << endl << endl;
    }
}
//---------------------------------------------------------------------//
