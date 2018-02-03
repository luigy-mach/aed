#include "nodo.h"
/*template<class T>
Nodo<T>::Nodo()
{
}*/
template<class T>
Nodo<T>::Nodo(int size,int grado)
{
    this->m_Size=size;
    this->m_Grado=grado;
    this->m_Dato=new T[m_Size];
    this->m_pSon=new Nodo<T>[m_Grado];
}
template<class T>
void Nodo<T>::setDato(T * Dato)
{
    if(Dato)
    {
        for(int i=0;i<m_Size;i++)
        {
            this->m_Dato[i]=Dato[i];
        }
    }
}
template<class T>
T* Nodo<T>::getDato()
{
    return this->m_Dato;
}

template<class T>
void Nodo<T>::setSon(Nodo<T>*pSon,int pos)
{
    m_pSon[pos]=pSon;
}
template<class T>
Nodo<T>* Nodo<T>::getSon(int pos)
{
    return m_pSon[pos];
}
template<class T>
Nodo<T>::~Nodo()
{
    delete this->m_pSon;
    delete this->m_Dato;
}
