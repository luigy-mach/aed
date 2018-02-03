#include <iostream>
#include <string>
using namespace std;

//Traductor Bilingue
class Palabra//Diccionario
{
  public:
	 string castellano;//almacena palabras en castellano
	 string ingles;//almacena palabras en ingles
  public:
	  Palabra(){};
	  Palabra(string c, string i)
	  {
		  castellano = c;//guarda string c en castellano
		  ingles = i;//guarda string i en castellano
	  }

	  string traducir(bool t =0)//solo retorna 0 cuando la 
                                      //palabra esta en ingles
	  {
		  if (t ==0) return ingles;
		  return castellano;
		   
	  }

	  bool operator==(Palabra & p) //compara contenido catellano de
				 //de la palabra
	  {
		  return castellano == p.castellano;

	  }

	  bool operator>(Palabra & p) 
	  {
		  return castellano > p.castellano;

	  }

	  friend ostream & operator<<(ostream &os, Palabra & p)
			//sobrecarga de operador binario << para
			//retornar castellano ingles
	  {
		  os<<p.castellano<<"--"<<p.ingles<<endl;
		  return os;
	  }
};

template<class T>//Clase lista template de tipo T
class Lista;//clase vacia poque se llama en clase Nodo

template<class T>
class Nodo//Clase Nodo T
{
   friend class Lista<T>;
   typedef Nodo<T> * pNodo;//definimos a un Nodo<T>* como pNodo
   private:
       T       m_Dato;//miembro dato de tipo T
       pNodo   m_Sig;// Puntero a el siguiente nodo    
   public:
      Nodo(T d):m_Dato(d),m_Sig(0){};//inicializamos al nodo en 0
			 // miembro dato como puntero al siguiente nodo
      void matate()  //funcion que se llama a si recursivamente
      {
         if(m_Sig) m_Sig->Matate();//si hay un pustero a nodo matalo primero
         delete this; //muere el ultimo
      } 
      void print(ostream &os)//fumcion para imprimir de atras hacia adelante
      {
         if(m_Sig) m_Sig->print(os);//se llama recursivamente
         cout<<m_Dato<<" "; //impreme el ultimo
      } 
};


template<class T>//clase template tipo T
class Lista
{
     private:
       Nodo<T> *  m_pHead;// puntero a la cabeza 
     public:  
       Lista()
       {
          m_pHead =0;//asigna 0 a la cabeaza lista vacia
       };
       
       bool find(T d, Nodo<T> ** & p)//busqueda que guarda la ultima ubicacion
                                     //donde se quedo buscando
       {
            p = &m_pHead;//el doble puntero p apunta a la cabeza
            while(*p)//mientras exista contenido en p
            {
               if ((*p)->m_Dato == d) return true;//revise si el m_Dato es d
               if ((*p)->m_Dato > d)  return false;//revise si el 
                             			 //m_Dato es > que d
               p = &((*p)->m_Sig);//p es un puntero doble que guarda direccion 
                                //de m_Sig que guarda direccion de un nodo
            }
            return false;// si no lo encuentra retorna false
       } 
       bool  Add(T d)//funcion agregar con base en funcion find
       {
          Nodo<T> ** q;//se crea un doble puntero a nodo q
          if (find(d,q)) return  false;//hace una busqueda que si
			         // lo encuentra retorna false
                      //y no lo agrega pero si no lo encuentra loa gregara
          Nodo<T> * nuevo = new Nodo<T>(d);//crea un nodo nuevo con dato d			
          nuevo->m_Sig = *q;//lo agrega en la posicion que se quedo q                       
          *q = nuevo; //y lo agrega a la lista
          return true; 
          
       }
       
       Lista<T> & operator<<(T d)//agrega datos a  la lista
       {
          Add(d);//llama la funcion Add
          return *this;//retorna true o false depende de Add
        
       }
       
   friend ostream & operator<<(ostream & os, Lista<T> & l)//sobrecarga 
			//el operador << para imprimir la lista 
   {
         l.m_pHead->print(os);//la lista ingresa a la cabeza y llama 
			//recursivamente a la impresion de nodos
         os<<endl;//imprime el valor del nodo
         return os;//retorna os
   
   }
};


int main()
{
  
return 1;
}
