#include <iostream>
#include <string>
using namespace std;

template<class T>
class Lista;

template<class T>
class Nodo
{
   friend class Lista<T>;
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
};


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


int main()
{
  cout<<"hello world"<<endl;
  return 1;
}
