#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template<class T>
class pila;

template<class T>
class nodo
{
   friend class pila<T>;
   typedef nodo<T> * pNodo;
   private:
       T       m_Dato;
       pNodo   m_Sig;
   public:
      nodo(T d):m_Dato(d),m_Sig(0){};
      void matate()
      {
         if(m_Sig) m_Sig->Matate();
         delete this;
      }
      void print(ostream &os)
      {
         if(m_Sig) m_Sig->print(os);
         cout<<m_Dato<<" ";
      }
};

template <class T>
class pila
{
   typedef nodo<T> * pNodo;
   public:
    pila();
    //~pila();
    void push_back(T d);
    void pop_back(T d);
    void matate();

   private:
   nodo<T>*m_phead;
   nodo<T>*m_plast;

};

  template <class T>
  pila<T>::pila()
  {
      m_phead=m_plast=0;
  }

  template <class T>
  void pila<T>::push_back(T d)
  {
      nodo<T> * tmp=m_phead;
      pNodo nuevo=new nodo<T>;
      nuevo=m_phead;
      nuevo->m_Dato=d;
      nuevo->m_Sig=m_plast;


  }

#endif // NODO_H
