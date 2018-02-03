#include "pila.h"
#include "nodo.h"

template<class T>
Pila<T>::Pila()
{
}
template<class T>
void Pila<T>::Push(T D)
{
    Nodo<T> * nuevo=new Nodo<T>(D);
    if(!m_tope)
    {
        m_tope=nuevo;
    }
    else
    {
        nuevo->setmpAnt(m_tope);
        m_tope=nuevo;
    }
}

template<class T>
void Pila<T>::Pop(T &D)
{
    D=m_tope->getmDato();
    Nodo<T> * tmp= m_tope;
    m_tope=m_tope->getmpAnt();
    delete tmp;
}

template<class T>
bool Pila<T>::isEmpty()
{
    if(!m_tope)
        return 0;
    return 1;
}
