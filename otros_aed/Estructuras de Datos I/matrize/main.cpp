/*#include<iostream>
using namespace std;
/*#include"matriz.cpp"
#include"ListaT.h"r
int main()
{
    Matrix<int,10,10> A;
    for(int i=0;i<10;i++)
        A(i,i)=1;
     A.Print();
     return 0;, int fil=10, int col=10
}

#include "matrize.h"

int main()
{
    MatrizE<int> A(100,100);//,100,100> A;
    for(int i=0;i<100;i++)
        A(i,i)=1;
     A.Print();
     return 0;
}


#include  <iostream>
//#include "ListaT.cpp"
using namespace std;

template<class T>
class Lista;

template<class T>
class NodoE;

template<class T,int fil,int col>
class Matrix;

template<class T>
class cabecera;


template<class T>
class Nodo
{
   friend class Lista<T>;
   friend class NodoE<T>;
   friend class Matrix<T,10,10>;
   friend class cabecera<T>;
   typedef Nodo<T> * pNodo;
   public:
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
            }
            return false;
       }
       bool  Add(T d,Nodo<T> ** &q)
       {
          //Nodo<T> ** q;
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
     NodoE(T d,int f, int c)
     {
           m_fil = f;
           m_col = c;
           m_Dato = d;
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
        bool operator == (cabecera a)
        {
                return Dato==a.Dato;
        }

        bool operator > (cabecera a)
        {
                return Dato>a.Dato;
        }
};
template<class T, int fil=10, int col=10>
class Matrix
{
    private:
      Lista< cabecera<T> >  m_Filas;
      Lista< cabecera<T> >  m_Columnas;
    public:
      Matrix(){ }

      bool find_fil(int f, int c, NodoE<T> ** & p )
      {
          Nodo< cabecera<T> > ** r;
          if (!(m_Columnas.Add( cabecera<T>(c) , r )))
          {
            p = &((*r)->m_Dato.pNodito);
            return false;
          }
          p = &((*r)->m_Dato.pNodito);
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
          if (!(m_Filas.Add( cabecera<T>(f) , r )))
          {
              p = &((*r)->m_Dato.pNodito);

              return false;
          }
          p = &((*r)->m_Dato.pNodito);
          while(*p)
          {
             if((*p)->m_col == c) return true;
             if ((*p)->m_col > c) return false;
             p = &((*p)->pSigCol);
          }
        return 0;


      }


     T & operator()(T d,int f, int c)
     {
         NodoE<T> **p,**q;
         if (!find_col(f,c,p) && !find_fil(f,c,q))
         {
           NodoE<T> * pnuevo = new NodoE<T>(d,f,c);
           pnuevo->pSigCol = *p;
           pnuevo->pSigFil = *q;
           *p = *q = pnuevo;
           cout<<pnuevo->m_Dato<<endl;
           return (*p)->m_Dato;
         }
         cout<<(*p)->m_Dato<<endl;
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
               cout<<"0 ";
       }
      cout<<endl;
      }


   }




};
*/

#include  <iostream>
using namespace std;

template<class T>
class Lista;

template<class T>
class NodoE;

template<class T,int fil,int col>
class Matrix;

template<class T>
class cabecera;

template<class T>
class Nodo
{
   friend class Lista<T>;
   friend class NodoE<T>;
   friend class Matrix<T,10,10>;
   friend class cabecera<T>;
   typedef Nodo<T> * pNodo;
   public:
       T       m_Dato;
       pNodo   m_Sig;
   public:
      Nodo(T d):m_Dato(d),m_Sig(0){}
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
            }
            return false;
       }
       void  Add(T d,Nodo<T> ** &q)
       {
          //Nodo<T> ** q;
          if (find(d,q)) return;
          Nodo<T> * nuevo = new Nodo<T>(d);
          nuevo->m_Sig = *q;
          *q = nuevo;
          return;

       }
       /*bool  Add(T d)
       {
          Nodo<T> ** q;
          if (find(d,q)) return  false;
          Nodo<T> * nuevo = new Nodo<T>(d);
          nuevo->m_Sig = *q;
          *q = nuevo;
          return true;

       }*/

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
     bool operator==(cabecera<T> a)
     {
         return a.Dato==Dato;
     }
     bool operator>(cabecera<T> a)
     {
         return a.Dato>Dato;
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
          p = &((*r)->m_Dato.pNodito);
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
          p = &((*r)->m_Dato.pNodito);
          //p = &((*r)->get_Dato().pNodito);
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
         Nodo< cabecera<T> > ** pf;
         Nodo< cabecera<T> > ** qf;
         cabecera<T> cf(f);
         cabecera<T> cc(c);
         NodoE<T> **p,**q;
         m_Filas.Add(cf,pf);m_Columnas.Add(cc,qf);
         //{
         if (!find_col(f,c,p) && !find_fil(f,c,q))
         {
           NodoE<T> * pnuevo = new NodoE<T>(f,c);
           pnuevo->pSigCol = *p;
           pnuevo->pSigFil = *q;
           *p = *q = pnuevo;
            return (*p)->m_Dato;
         }//}
         /*if(m_Filas.Add(cf,pf)||m_Columnas.Add(cc,qf))
         {
             if(*pf)
             {
                 if (!find_fil(f,c,q))
                 {
                   NodoE<T> * pnuevo = new NodoE<T>(f,c);
                   pnuevo->pSigCol = *p;
                   pnuevo->pSigFil = *q;
                   *p = *q = pnuevo;
                    return (*p)->m_Dato;
                 }
             }
             if(*qf)
             {
                 if (!find_col(f,c,q))
                 {
                   NodoE<T> * pnuevo = new NodoE<T>(f,c);
                   pnuevo->pSigCol = *p;
                   pnuevo->pSigFil = *q;
                   *p = *q = pnuevo;
                    return (*p)->m_Dato;
                 }
             }
         }*/
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


int main()
{
    Matrix<int,10,10> A;
    for(int i=0;i<10;i++)
       // for(int j=0;j<10;j++)
            A(i,i)=1;
     A.Print();
}
