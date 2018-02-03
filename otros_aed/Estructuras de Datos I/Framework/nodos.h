#ifndef NODOS_H
#define NODOS_H
#include "nodo.h"
template<class T>
class Nodos:public Nodo<T>
{
public:
    //template<class T>
    Nodos(int size=1,int grado=1):Nodo<T>(size,grado){};
    void setDato(T *Dato);
    void setSon(Nodo<T> *pSon);
    T* getDato();
    Nodo<T>* getSon();
    ~Nodos();
};

#endif // NODOS_H
