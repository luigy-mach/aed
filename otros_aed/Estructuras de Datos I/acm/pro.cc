#include <iostream>

using namespace std;


class objeto
{
     public:
       virtual objeto* clone()=0;
       virtual void read()=0;
        virtual void print(){cout<<"soy abstracto sonso "<<endl;};
        ~objeto() {  cout<<"objeto muerto "<<endl;}
}; 

class Entero : public objeto
{
     private:
        int m_dato;
     public:
       Entero(Entero & ent)
       {
          m_dato = ent.m_dato;
       }
       Entero(int a)
       {
              m_dato = a;
       };

       void read(){  cout <<"ingrese entero :"; cin>>m_dato;}
       void print(){  cout <<"imprime entero :"<<m_dato<<endl;}
       objeto*  clone()
       {
               return new Entero(*this);
       }
       ~Entero(){cout<<"muero el entero..."<<endl;}
       

   
};



class Float : public objeto
{
     private:
        float m_dato;
     public:
       Float(Float & ent)
       {
          m_dato = ent.m_dato;
       }
       Float(float a)
       {
              m_dato = a;
       };

       void read(){  cout <<"ingrese float :"; cin>>m_dato;}
       void print(){  cout <<"imprime float :"<<m_dato<<endl;}
       objeto*  clone()
       {
               return new Float(*this);
       }
       ~Float(){cout<<"muero el flotante..."<<endl;}
       

   
};

class Lista;

class Nodo
{
    friend class Lista;
    private:
      objeto * m_Dato;
      Nodo   * m_pSig;
    public: 
      Nodo(objeto * p)
      {
            m_Dato = p->clone();
            m_pSig=0;
      }
};


class Lista
{
    typedef Nodo * pNodo; 
    private:
       pNodo m_Head;
       pNodo m_Last;
    public:
      Lista()
      {
          m_Head = m_Last =0;
      }
      void push_front(objeto * p)
      {
           pNodo nuevo = new Nodo(p); // crea un nuevo nodo
           if(!m_Head) // si no hay nadie (si la lista esta vacia)
           {
              m_Head = m_Last = nuevo; // el nuevo es la cabeza y la cola ahora 
           } 
           else
           {
                nuevo->m_pSig = m_Head; // el siguiente del nuevo tiene que ser la cabeza
                m_Head = nuevo;   //  y ahora la cabeza es el nuevo
           }
            
      }

    void push_back(objeto * p)
    {

           pNodo nuevo = new Nodo(p); // crea un nuevo nodo
           if(!m_Head) // si no hay nadie (si la lista esta vacia)
           {
              m_Head = m_Last = nuevo; // el nuevo es la cabeza y la cola ahora 
           } 
           else
           {
                m_Last->m_pSig = nuevo; // el siguiente del ultimo es  el nuevo
                m_Last = nuevo;   //  el ultimo es el nuevo
           }
    }

    void print()
    {
        pNodo p = m_Head;
        while(p!=0)  // miestras p no es nulo 
        {
             p->m_Dato->print(); // imprime el dato
             p=p->m_pSig;  // que pase el siguiente
        }
        
    }


};



int main()
{
      objeto *  v[ ] = {new Entero(3), new Float(5.6), new Entero(5)};
      Lista a;
      for(int i=0;i<3;i++)
      { 
          a.push_back(v[i]);
          delete v[i];  
       } 
      a.print();
 
      return 1;
}








