#include "cola.h"
template<class T>
Cola<T>::Cola()
{
    this->m_pHead=0;
    this->m_pLast=0;
}
template<class T>
void Cola<T>::Push(T D)
{
    Nodo<T> * nuevo =new Nodo<T>(D);
    if(m_pLast==0)
    {
        m_pHead=nuevo;
        m_pLast=nuevo;
    }
    else
    {
        m_pLast->setmpAnt(nuevo);
        m_pLast=nuevo;
    }
}

template<class T>
void Cola<T>::Pop(T &D)
{
    if(m_pHead)
    {
        D=m_pHead->getmDato();
        Nodo<T>* tmp=m_pHead;
        m_pHead=m_pHead->getmpAnt();
        delete tmp;
    }
    return;
}

template<class T>
bool Cola<T>::isEmpty()
{
    return m_pHead;
}
