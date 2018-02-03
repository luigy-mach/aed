#include "nodos.h"

template<class T>
void Nodos<T>::setDato(T *Dato)
{
    if(Dato)
    {
        this->m_Dato[0]=Dato[0];
    }
}

template<class T>
void Nodos<T>::setSon(Nodo<T> *pSon)
{
    if(pSon)
    {
        this->m_pSon[0]=pSon[0];
    }
}
template<class T>
Nodos<T>::~Nodos()
{
    delete this->m_Dato;
    delete this->m_pSon;
}
template<class T>
T* Nodos<T>::getDato()
{
    return this->m_Dato;
}
template<class T>
Nodo<T>* Nodos<T>::getSon()
{
    return this->m_pSon[0];
}
