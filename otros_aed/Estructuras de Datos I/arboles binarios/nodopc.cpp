#include "nodopc.h"
template<class T>
Nodopc<T>::Nodopc(T D)
{
    m_Dato=D;
    m_pAnt=0;
}

template<class T>
void Nodopc<T>::setmDato(T D)
{
    m_Dato =D;
}

template<class T>
T Nodopc<T>::getmDato()
{
    return m_Dato;
}

template<class T>
Nodopc<T>* Nodopc<T>::getmpAnt()
{
    return m_pAnt;
}

template<class T>
void Nodopc<T>::setmpAnt(pNodo sig)
{
    m_pAnt=sig;
}
