#include "nodo.h"
template<class T>
Nodo<T>::Nodo(T D)
{
    m_Dato=D;
    m_pAnt=0;
}

template<class T>
void Nodo<T>::setmDato(T D)
{
    m_Dato =D;
}

template<class T>
T Nodo<T>::getmDato()
{
    return m_Dato;
}

template<class T>
Nodo<T>* Nodo<T>::getmpAnt()
{
    return m_pAnt;
}

template<class T>
void Nodo<T>::setmpAnt(pNodo sig)
{
    m_pAnt=sig;
}
