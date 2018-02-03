#include "listas.h"

template<class T>
T* Listas<T>::getMax()
{
    Nodo<T> * tmp = this->m_pRoot;
    Nodo<T> * mayor = this->m_pRoot;
    tmp=tmp->getSon(0);
    while(tmp)
    {
        if(tmp->getDato()<=mayor->getDato())
        {
            tmp=tmp->getSon(0);
        }
        if(tmp->getDato()>mayor->getDato())
        {
            mayor=tmp;
            tmp=tmp->getSon(0);
        }
    }
    return mayor->getDato();
}

template<class T>
T* Listas<T>::getMin()
{
    Nodo<T> * tmp = this->m_pRoot;
    Nodo<T> * menor = this->m_pRoot;
    tmp=tmp->getSon(0);
    while(tmp)
    {
        if(tmp->getDato()>=menor->getDato())
        {
            tmp=tmp->getSon(0);
        }
        if(tmp->getDato()<menor->getDato())
        {
            menor=tmp;
            tmp=tmp->getSon(0);
        }
    }
    return menor->getDato();
}

template<class T>
void Listas<T>::Sort()
{
void insert_sort::insertionSort()
{
int numbers[], int array_size
   for (int i=1; i < array_size; i++)
   {
      index = numbers[i];
      a = i-1;

      while (a >= 0 && numbers[a] > index)
      {
         numbers[a + 1] = numbers[a];
         a--;
      }
      numbers[a+1] = index;
   }
   for(int i=0;i<array_size;i++)
        cout<<numbers[i];
}
}

template<class T>
void Listas<T>::Reverse();
template<class T>
void Listas<T>::Clear();
