#include "lista.h"

template<class T>
void Lista<T>::Add(T *D)
{
    Nodo<T> * nuevo = new Nodos<T>();
    nuevo->setDato(D);
    if(this->m_pRoot)
    {
        this->m_pRoot=m_pLast=nuevo;
    }
    else
    {
        m_pLast->setSon(nuevo,0);
        m_pLast=m_pLast->getSon(0);
    }
}

template<class T>
void Lista<T>::Remove(T *D)
{
    Nodo<T> * ant,*tmp;
    tmp=this->m_pRoot;
    for(;tmp;tmp=tmp->getSon(0))
    {
        if(D[0]==tmp->m_Dato[0])
        {
            ant->setSon(tmp->getSon(0),0);
            delete tmp;
            break;
        }
        ant=tmp;
    }
}

template<class T>
bool Lista<T>::Find(T *D)
{
    Nodo<T> * tmp=this->m_pRoot;
    for(;tmp;tmp=tmp->getSon(0))
    {
        if(D[0]==tmp->m_Dato[0])
            return true;
    }
    return false;
}
