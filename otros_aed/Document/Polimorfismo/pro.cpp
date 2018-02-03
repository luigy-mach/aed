#include <iostream>

using namespace std;


class objeto //Clase Abstarcta 
{
     public:
       virtual objeto* clone()=0; //Constructor
       virtual void read()=0; //Funcion Virtual Pura pero modificable en
			      //los hijos gracias a la palabra virtual
       virtual void print()   //Funcion modificable en los hijos
                              //gracias a la palabra virtual
	       {
		   cout<<"soy abstracto sonso "<<endl;
	       };
       virtual ~objeto() //Destructor : la palabra virtual le indica que al
		         //destruirse el objeto llame al destructor de la
                         //clase que este dentro del objeto
	       {
		  cout<<"objeto muerto "<<endl;
	       }
}; 


class Entero : public objeto //Hereda todo el contenido public de la clase objeto
{
     private:
        int m_dato; // miembro dato privado de la clase
     public:
       Entero(Entero & ent) // recibe el contenido de una clase entero
       {
          m_dato = ent.m_dato; //guarda el contenido de la clase
			       //en m_dato que guarda enteros
       }
       Entero(int a) // recibe un entero
       {
          m_dato = a; //guarda el entero en m_dato
       };

       void read()
       {
	  cout <<"ingrese entero :"; // imprime en pantalla ingrese dato
          cin>>m_dato; // espera a  que ingreses por consola el dato
       }
       void print()
       {
	  cout <<"imprime entero :"<<m_dato<<endl;//imprime el contenido de m_dato
       }
       objeto*  clone()
       {
               return new Entero(*this); // saca una copia de el entero que se
					 //este trabajando gracias a la
					 //palabra this
       }
       ~Entero()
       {
          cout<<"muero el entero..."<<endl; //destruye a la clase entero 
       }
   
};



class Float : public objeto //clase identica a clase entero pero
			    //solo que esta guarda floats
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

       void read()
       {
	    cout <<"ingrese float :";
            cin>>m_dato;
       }
       void print()
       {
	    cout <<"imprime float :"<<m_dato<<endl;
       }
       objeto*  clone()
       {
            return new Float(*this);
       }
       ~Float()
       {
            cout<<"muero el flotante..."<<endl;
       }
        
};


class Lista;

class Nodo
{
    friend class Lista; // la palabra friend le indica a clase nodo
			// que la clase lista tiene acceso a la parte
			// private de la clase nodo
    private:
      objeto * m_Dato;//guarda direccion de una clase objeto
      Nodo   * m_pSig;//guarda la direccion de un nodo
    public: 
      Nodo(objeto * p)//constructor que recibeun objeto por referencia
      {
            m_Dato = p->clone();//saca una copia y la gurada en m_Dato
            m_pSig=0;//asigna vacio al valor de m_Psig
      }
};


class Lista
{
    typedef Nodo * pNodo; // define un alias a pNodo en vez de Nodo*
    private:
       pNodo m_Head;//guarda la direccion d ela cabeza de la lista
       pNodo m_Last;//gurada la direccion del ultimo de la lista
    public:
      Lista()//constructor de lista
      {
          m_Head = m_Last =0;//asiga cero a la cabeza y cola poruqe esta vacia
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
                nuevo->m_pSig = m_Head; // el siguiente del nuevo
					//tiene que ser la cabeza
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








