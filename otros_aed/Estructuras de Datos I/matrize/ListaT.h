#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

template<class T>
class Lista
{
     private:
       Nodo<T> *  m_pHead;
     public:  
       Lista()
       {
          m_pHead =0;
       }
       
       bool find(T d, Nodo<T> ** & p)
       {
            p = &m_pHead;
            while(*p)
            {
               if ((*p)->m_Dato == d) return true;
               if ((*p)->m_Dato > d)  return false;
               p = &((*p)->m_Sig);
            }
            return false;
       } 
       bool  Add(T d)
       {
          Nodo<T> ** q;
          if (find(d,q)) return  false;
          Nodo<T> * nuevo = new Nodo<T>(d);
          nuevo->m_Sig = *q;
          *q = nuevo;
          return true; 
          
       }
       
       Lista<T> & operator<<(T d)
       {
          Add(d);
          return *this;
        
       }
       
   friend ostream & operator<<(ostream & os, Lista<T> & l)
   {
         l.m_pHead->print(os);
         os<<endl;
         return os;
   
   }
};

#endif
