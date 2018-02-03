#include  <iostream>
#include"ListaT.h"
using namespace std;

template<class T>
class NodoE
{
   public:
     int m_fil;
     int m_col;
     T   m_Dato;
     NodoE<T>  * pSigFil;
     NodoE<T>  * pSigCol;  
   public:
     NodoE(){};
     NodoE(int f, int c)
     {
           m_fil = f;
           m_col = c;
//           m_Dato = d;
           pSigFil = pSigCol =0;       
     }
};

template<class T>
class cabecera
{
     public:
       int Dato;
       NodoE<T> * pNodito; 
     cabecera(){};
     cabecera(int d, NodoE<T> * p =0 )
     {
           Dato = d;
           pNodito = p; 
	 }

};
template<class T, int fil=10, int col=10>
class Matrix
{
    private:
      Lista< cabecera<T> > m_Filas;
      Lista< cabecera<T> > m_Columnas;
    public:
      Matrix(){}

      bool find_fil(int f, int c, NodoE<T> ** & p )
      {
          Nodo< cabecera<T> > ** r;
          if (!(m_Columnas.find( cabecera<T>(c) , r )))
            return false;
          //p = &((*r)->Dato.pNodito);
          p = &((*r)->get_Dato().pNodito);
          while(*p)
          {
             if((*p)->m_fil == f) return true;
             if ((*p)->m_fil > f) return false; 
             p = &((*p)->pSigFil); 
          }
        return 0;
      }

      bool find_col(int f, int c, NodoE<T> ** & p )
      {
          Nodo< cabecera<T> > ** r;
          if (!(m_Filas.find( cabecera<T>(f) , r )))
            return false;
          //p = &((*r)->Dato.pNodito);
          p = &((*r)->get_Dato().pNodito);
          while(*p)
          {
             if((*p)->m_col == c) return true;
             if ((*p)->m_col > c) return false; 
             p = &((*p)->pSigCol); 
          }
        return 0;


      }

   
     T &  operator()(int f, int c)
     {
         NodoE<T> **p,**q; 
         if (!find_col(f,c,p) && !find_fil(f,c,q))
         {
           NodoE<T> * pnuevo = new NodoE<T>(f,c);
           pnuevo->pSigCol = *p;
           pnuevo->pSigFil = *q; 
           *p = *q = pnuevo;
            return (*p)->m_Dato;
         } 
          return (*p)->m_Dato; 
     }

   void  Print()
   {
      NodoE<T> ** p;
      for(int i=0;i<fil;i++)
      {
       for(int j=0;j<col;j++)          
       {
           if (find_fil(i,j,p)) cout<<(*p)->m_Dato<<" ";
           else cout<<"0 ";
       } 
      cout<<endl;
      }


   }



       
};

