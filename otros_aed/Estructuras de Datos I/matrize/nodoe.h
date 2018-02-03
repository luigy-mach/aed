#ifndef NODOE_H
#define NODOE_H

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

#endif // NODOE_H
