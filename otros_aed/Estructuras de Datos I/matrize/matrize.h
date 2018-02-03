#ifndef MATRIZE_H
#define MATRIZE_H

//#include "nodo.h"
#include "ListaT.h"
#include "cabecera.h"

template<class T>//, int fil=10, int col=10>
class MatrizE
{
    private:
      Lista< cabecera<T> > m_Filas;
      Lista< cabecera<T> > m_Columnas;
      int fil,col;
    public:
      MatrizE(int filas, int columnas)
      {
          fil=filas;
          col=columnas;
      }
      bool find_fil(int f, int c, NodoE<T> ** & p )
      {
          Nodo< cabecera<T> > ** r;
          if (!(m_Columnas.find( cabecera<T>(c) , r )))
            return false;
          p = &((*r)->m_Dato.pNodito);
          //p = &((*r)->get_Dato().getpnodo());
          //p = &((*r)->get_Dato().pNodito);
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
          //p = &((*r)->m_Dato.pNodito);
          p = &(((*r)->get_Dato()).getpnodo());
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
#endif // MATRIZE_H
