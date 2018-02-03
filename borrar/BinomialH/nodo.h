#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED


#include <vector>

using namespace std;

template<class T>
class nodo
{
    public:

    T m_dato;
    vector<nodo<T> > sons;
    nodo<T>* parent;
    int m_grado;// T m_grado; no es necesario un T .. simeplemente un entero

public:
    nodo(T d,nodo<T>*p=NULL){
    m_dato=d;
    //sons[0];
    m_grado=0;
    parent=p;
    }



};

#endif // NODO_H_INCLUDED
