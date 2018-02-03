#include <iostream>
using namespace std;

template<class T>
class pila;

template<class T>
class cola;

template<class T>
class nodo
{
   friend class pila<T>;
   friend class cola<T>;
   typedef nodo<T> * pNodo;
   private:
       T       m_Dato;
       pNodo   m_Sig;
   public:
      nodo(T d):m_Dato(d),m_Sig(0){};
      void matate()
      {
         if(m_Sig) m_Sig->matate();
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
    ~pila();
    void push_back(T d);
    void pop_back();
    void print();
    void isempty();

   private:
   nodo<T>*m_phead;
   nodo<T>*m_plast;

};

  template <class T>
  pila<T>::pila()
  {
      m_phead=m_plast=0;
  }
  template<class T>
  pila<T>::~pila()
  {
   pNodo tmp=m_phead;
   tmp->matate();
   cout<<"muerto"<<endl;
  }

  template <class T>
  void pila<T>::push_back(T d)
  {
       nodo<T> * tmp=m_phead;
       pNodo nuevo=new nodo<T>(d);       
       if(!m_phead)
       { 		
          m_phead=m_plast=nuevo; 	
          //cout<<"primer elemento"<<endl;
       }
       else
       {
          m_plast->m_Sig=nuevo;
	m_plast=nuevo;		
          //cout<<"segundo elemento"<<endl;
       }  
   }
  template <class T>
  void pila<T>::pop_back()
  {
      nodo<T> * tmp =m_phead;
      while(tmp!=m_plast)
      {
        tmp=tmp->m_Sig;
        //cout<<tmp->m_Dato<<endl;
        //cout<<tmp->m_Sig<<endl;
      }
      
      delete m_plast;
      //cout<<m_plast->m_Dato;
      m_plast=tmp;
      //cout<<m_plast->m_Dato<<"    "<<m_plast->m_   
      
  }
   

  template<class T>
  void pila<T>::print()
 {
    nodo<T> * tmp=m_phead;
    cout<<"[";
    while(tmp)
    {
       cout<<tmp->m_Dato<<" , ";
       tmp=tmp->m_Sig;		
    }
       cout<<"]"<<endl;
 }

  template<class T>
  void pila<T>::isempty()
 {
    pNodo c =m_phead; 
    if(m_phead)
    {
       cout<<"Tiene por lo menos un elemento"<<endl;
    }
    else 
    {
       cout<<"Lista Vacia"<<endl;
    }
 }

template<class T>
class cola
{
   typedef nodo<T> * pNodo;
   public:
    cola();
    ~cola();
    void push_back(T d);
    void pop_head();
    void print();
    void isempty();

   private:
   nodo<T>*m_phead;
   nodo<T>*m_plast;

};

template<class T>
cola<T>::cola()
  {
      m_phead=m_plast=0;
  }
template <class T>
  void cola<T>::push_back(T d)
  {
       nodo<T> * tmp=m_phead;
       pNodo nuevo=new nodo<T>(d);       
       if(!m_phead)
       { 		
          m_phead=m_plast=nuevo; 	
          //cout<<"primer elemento"<<endl;
       }
       else
       {
          m_plast->m_Sig=nuevo;
	m_plast=nuevo;		
          //cout<<"segundo elemento"<<endl;
       }  
   }
template<class T>
  void cola<T>::pop_head()
{
   pNodo tmp=m_phead;
   delete m_phead;
   m_phead=tmp->m_Sig;

}
template<class T>
  void cola<T>::print()
 {
    nodo<T> * tmp=m_phead;
    cout<<"[";
    while(tmp)
    {
       cout<<tmp->m_Dato<<" , ";
       tmp=tmp->m_Sig;		
    }
       cout<<"]"<<endl;
 }

template<class T>
  void cola<T>::isempty()
 {
    pNodo c =m_phead; 
    if(m_phead)
    {
       cout<<"Tiene por lo menos un elemento"<<endl;
    }
    else 
    {
       cout<<"Lista Vacia"<<endl;
    }
 }

template<class T>
cola<T>::~cola()
{
if(m_phead)
{
while(m_phead)
{
  pNodo tmp=m_phead;
  m_phead=m_phead->m_Sig;
  delete tmp;
}
}
cout<<"Lista Vacia"<<endl;
}

int main()
{
   cola<int> p;
   p.isempty();
   p.push_back(7);
   p.push_back(8);
   p.push_back(9);	
   p.push_back(44);
   p.print();
   p.pop_head();
   p.~cola();
   p.push_back(5);
   p.print();
}




