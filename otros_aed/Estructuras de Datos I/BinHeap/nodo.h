#ifndef NODO_H
#define NODO_H

template<class T>
class binomial;

template<class T>
class Nodo
{
    typedef Nodo<T> * pNodo;
    friend class binomial<T>;
    protected:
        T key;
        pNodo sibling;
        pNodo child;
    public:
        Nodo(T d);
        void setKey(T d);
        T getKey();
        void setSibling(pNodo);
        void setChild(pNodo a);
        pNodo getSibling();
        pNodo getChild();
};

template<class T>
Nodo<T>::Nodo(T D)
{
    key=D;
    sibling=0;
}

template<class T>
void Nodo<T>::setKey(T d){ key = d;}

template<class T>
T Nodo<T>::getKey(){return key;}

template<class T>
Nodo<T>* Nodo<T>::getSibling(){return sibling;}

template<class T>
void Nodo<T>::setSibling(pNodo sig){ sibling=sig;}

template<class T>
Nodo<T>* Nodo<T>::getChild(){return child;}

template<class T>
void Nodo<T>::setChild(pNodo a){ child=a;}

#endif // NODO_H
