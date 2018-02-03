#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
using namespace std;
template<class T>
class NodoE
{
    public:
      T   m_Dato;
      NodoE<T>   * m_pSigCol;
      NodoE<T>   * m_pSigFil;
      int          f;
      int          c;

NodoE()
{
    m_pSigCol = m_pSigFil = f = c =0;
}

NodoE(T d, int x, int y)
{
    m_Dato = d;
    m_pSigCol = m_pSigFil =0;
    this->f = x;
    this->c = y;
}
  
};

template<class T>
class Matriz
{
    private:
        NodoE<T>   ** m_pFilas;
        NodoE<T>   ** m_pColumnas;
        int           m_Filas;
        int           m_Columnas;
    public:
        Matriz(int f, int c)
        {
          m_Filas     = f;
          m_Columnas  = c;
          m_pFilas    = new NodoE<T>*[f];
          m_pColumnas = new NodoE<T>*[c];

          for(int i=0;i<f;i++)
            m_pFilas[i]=0;

          for(int i=0;i<c;i++)
            m_pColumnas[i]=0;

        } 

       bool find_fil(int f, int c, NodoE<T> ** & p)
       {
           p = &m_pColumnas[c];
           while(*p)
           {
                 if((*p)->f == f) return true;
                 if((*p)->f > f)  return false;
                 p = &((*p)->m_pSigFil);
           } 
            return false;           
       }

      bool find_col(int f, int c, NodoE<T> ** & p)
       {
           p = &m_pFilas[f];
           while(*p)
           {
                 if((*p)->c == c) return true;
                 if((*p)->c > c)  return false;
                 p = &((*p)->m_pSigCol);
           } 
           return false;
       }

      void Add(T d, int f, int c)
      {

           NodoE<T> ** p, **q;
           bool fil = find_fil(f,c,p);
           bool col = find_col(f,c,q);
           if(!fil)
           {
               NodoE<T> * pNuevo = new NodoE<T>(d,f,c);
               pNuevo->m_pSigFil = *p;
               pNuevo->m_pSigCol = *q;
               *q = *p = pNuevo;   
           }
      }

     void print(ostream &os)
     {
        NodoE<T> ** p;
        for(int i=0;i<m_Filas;i++)
         {
           os<<endl;
           for(int j=0;j<m_Columnas;j++)
           { 
                  if(find_col(i,j,p))
                      os<<(*p)->m_Dato<<" ";
                  else 
                      os<<"0 ";
           }     
        } 
     }

   




};


#endif // LISTASIMPLE_H
