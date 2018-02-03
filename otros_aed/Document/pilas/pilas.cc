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
    //void matate();
    void print();

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
	pNodo nuevo=new nodo<T>(d);       
	if(!m_phead)
        { 	
	   	
 	   m_phead=m_plast=nuevo; 	
	   cout<<"primer elemento"<<endl;
        }
        else
        {
		m_plast->m_Sig=nuevo;
		m_plast=nuevo;
		
		cout<<"segundo elemento"<<endl;
	}  
   }

  template<class T>
  void pila<T>::print()
 {
	nodo<T> * tmp=m_phead;
	while(tmp)
	{
		cout<<tmp->m_Dato<<endl;
		tmp=tmp->m_Sig;		
	}
 }

int main()
{
   pila<int> p;
   p.push_back(7);
   p.push_back(8);
   p.push_back(9);	
   p.push_back(44);
   p.print();

}




