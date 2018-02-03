#ifndef NODOB_H
#define NODOB_H
#include "nodo.h"

template<class T>
class binomial;

template<class T>
class nodoB:public Nodo<T>
{
    typedef Nodo<T> * pNodo;
    friend class binomial<T>;
    protected:
        int degree;
        pNodo parent;
    public:
        nodoB(T n):Nodo<T>(n)
        {
            parent=NULL;
            this->child=NULL;
            this->sibling=NULL;
            degree=0;
        }

        void setDegree(int);
        int getDegree();
        pNodo getParent();
        void setParent(pNodo);
};

template<class T>
Nodo<T> * nodoB<T>::getParent(){return parent;}

template<class T>
void nodoB<T>::setParent(pNodo p){ parent = p;}

template<class T>
int nodoB<T>::getDegree(){ return degree;}

template<class T>
void nodoB<T>::setDegree(int t){ degree=t;}

#endif // NODOB_H
