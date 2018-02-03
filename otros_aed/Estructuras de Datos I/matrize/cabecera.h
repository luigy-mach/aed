#ifndef CABECERA_H
#define CABECERA_H

#include "nodoe.h"

template<class T>
class MatrizE;

//template<class T>
//class Nodo;

template<class T>
class Lista;

template<class T>
class cabecera
{
    friend class MatrizE<T>;
    //friend class Nodo<T>;
    friend class Lista<T>;
    public:
       int Dato;
       NodoE<T> * pNodito;
     cabecera(){};
     cabecera(int d, NodoE<T> * p =0 )
     {
           Dato = d;
           pNodito = p;
     }
     int getDato()
     {
         return Dato;
     }

     NodoE<T>* getpnodo()
     {
         return this->pNodito;
     }
     bool operator == (cabecera a)
     {
         return Dato == a.getDato();
     }

     bool operator > (cabecera a)
     {
         return Dato > a.getDato();
     }


};

#endif // CABECERA_H
