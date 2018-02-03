#include "nodo.h"
template<class T>
nodo<T>::nodo(T d)
{
    m_Dato=d;
    m_pSon[0]=m_pSon[1]=0;
    //ctor
}
template<class T>
nodo<T>::~nodo()
{
    this.matate();
}
template<class T>
void nodo<T>::matate()
{
    if(m_pSon[0]) m_pSon[0]->matate();
    if(m_pSon[1]) m_pSon[1]->matate();
    delete this;
}
