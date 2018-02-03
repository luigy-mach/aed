#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

template<class T>
class Lista;

template<class T>
class NodoE;

template<class T>
class MatrizE;

template<class T>
class cabecera;

template<class T>
class Nodo
{
   friend class Lista<T>;
   friend class NodoE<T>;
   friend class MatrizE<T>;
   friend class cabecera<T>;
   typedef Nodo<T> * pNodo;
   private:
       T       m_Dato;
       pNodo   m_Sig;
   public:
      Nodo(T d):m_Dato(d),m_Sig(0){};
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
      T get_Dato()
      {
          return m_Dato;
      }
};


#endif // NODO_H
