#ifndef GRAFO_H
#define GRAFO_H

#include "lista.h"


template<class V,class E>
class Arista;

template<class V,class E>
class Vertex{
    public:
        V m_dato;
        Lista< Arista<V,E> > m_ady;
    public:
        Vertex(V d):m_dato(d){}
        bool operator==(const Vertex<V,E>& v){
            return m_dato==v.m_dato;
        }
        bool operator<(const Vertex<V,E>& v){
            return m_dato<v.m_dato?true:false;
        }
        bool operator>(const Vertex<V,E>& v){
            return m_dato>v.m_dato?true:false;
        }
};

template<class V,class E>
class Arista{
    public:
        E m_dato_peso;
        Vertex<V,E>* m_pVertex;
    public:
        Arista(E d,Vertex<V,E>* p=0){
            m_dato_peso=d;
            m_pVertex=p;
        }
        bool operator==(const Arista<V,E>& a){
            return m_dato_peso==a.m_dato_peso;
        }
        bool operator<(const Arista<V,E>& a){
            return m_dato_peso<a.m_dato_peso?true:false;
        }
        bool operator>(const Arista<V,E>& a){
            return m_dato_peso>a.m_dato_peso?true:false;
        }


};

template<class V, class E>
class Grafo
{
    public:
    Lista< Vertex<V,E> > m_grafo;

    public:
        Grafo(){}
        void insertar_vertex(E dato){
            m_grafo.push_back(Vertex<V,E>(dato));
        }
        void insertar_arista(V vi, V vf, E ar){
            Nodo< Vertex<V,E> > **p, **q;

            bool a1= m_grafo.find(Vertex<V,E>(vi),p);
            bool a2= m_grafo.find(Vertex<V,E>(vf),q);
            if(a1 && a2){
                (*p)->m_dato.m_ady.add(Arista<V,E>(ar,&((*q)->m_dato)));

            }
        }

};




#endif // GRAFO_H
