#ifndef QUADTREE_H
#define QUADTREE_H
#include "matrize.h"
#include <string>
#include <stdlib.h>
using namespace std;


class Comprensor;

template <class T>
class Quadtree;

template < class T >
class NodoQ
{
        friend class Comprensor;
        friend class Quadtree<T>;
        public:
                int * dom;
                NodoQ * hij[4];
                int key;
        public:
                NodoQ<T>()
                {
                        dom= new int[4];
                        key=-1;
                }
                NodoQ<T>(int k, int *d)
                {
                         key=k;
                        dom=d;
                }
                ~NodoQ<T>()
                {
                    delete dom;
                    delete hij;
                }

                void setKey(int k){ key=k;}
                void setDom(int * d){ dom=d;}
                void setHij(T *h) { hij = h;}
                int getKey(){ return key;}
                NodoQ getHij(){ return hij;}
                int * getDom(){ return dom;}
};

template <class T>
class Quadtree
{
        friend class Comprensor;
        private:
                NodoQ<T> * mRoot;
                MatrizE<T,256,256> matriz;
                MatrizE<T,256,256> mymat;
                int weight;
                int heigh;
        public:
                Quadtree(int w,int h)
                {
                        int * a= new int[4];
                        a[0]=0; a[1]=0; a[2]=w;a[3]=h;
                        mRoot = new NodoQ<T>(-1,a);
                }
                ~Quadtree()
                {
                    //delete matriz;
                    //delete mymat;
                }

                void setH(int h){heigh=h;}
                void setW(int w){weight=w;}
                int getW(){return weight;}
                int getH(){return heigh;}
                NodoQ<T> *&  getRoot(){return mRoot;}
                void setMat(MatrizE<T,256,256> m){ matriz=m;}
                MatrizE<T,256,256> getMat(){return matriz;}

                void etiquetar(NodoQ<T> * & w)
                {
                        int x,y,x1,y1;
                        x=w->dom[0];
                        y=w->dom[1];
                        x1=w->dom[2];
                        y1=w->dom[3];

                        if(x==x1 && y==y1)
                        {
                            NodoE<T> ** p;
                            w->setKey(matriz.find_col(x,y,p));return;
                        }
                                bool aux;
                                for(int i=x;i<=x1;i++)
                                {
                                     for(int j=y;j<=y1;j++)
                                      {
                                           NodoE<T> ** p;
                                           if(matriz.find_col(x,y,p)==true && matriz.find_col(i,j,p)==false ||(matriz.find_col(x,y,p)==false && matriz.find_col(i,j,p)==true))
                                           {
                                                 w->setKey(-1);
                                                 return;
                                           }
                                           else
                                                aux=matriz.find_col(x,y,p);

                                      }
                                }if(!aux)
                                {
                                        w->setKey(0);
                                        return;
                                }
                                if(aux)
                                {
                                        w->setKey(1);
                                        return;
                                }

                }
                void  subdividir(NodoQ<T> * & node)
                {
                                etiquetar(node);
                                if(node->getKey()==-1)
                                {

                                        int x1 =node->dom[0];
                                        int y1 =node->dom[1];
                                        int x2 =node->dom[2];
                                        int y2 =node->dom[3];

                                        if(x2-1==x1 && y2-1==y1)
                                        {
                                              int *a = new int[4];
                                              int *b = new int[4];
                                              int *c = new int[4];
                                              int *d = new int[4];

                                              a[0]=x1;a[1]=y1;a[2]=x1;a[3]=y1;
                                                   node->hij[0]= new NodoQ<T>(-1,a);
                                              b[0]=x1;b[1]=y2;b[2]=x1;b[3]=y2;
                                                   node->hij[1]= new NodoQ<T>(-1,b);

                                              c[0]=x2;c[1]=y1;c[2]=x2;c[3]=y1;
                                                   node->hij[2]= new NodoQ<T>(-1,c);

                                              d[0]=x2;d[1]=y2;d[2]=x2;d[3]=y2;
                                                   node->hij[3]= new NodoQ<T>(-1,d);

                                          }
                                          else
                                          {
                                              x2=(x1+x2)/2;
                                              y2=(y1+y2)/2;
                                              int *a = new int[4];
                                              int *b = new int[4];
                                              int *c = new int[4];
                                              int *d = new int[4];

                                           a[0]=x1;a[1]=y1;a[2]= x2 ;a[3]=y2;
                                                node->hij[0]= new NodoQ<T>(-1,a);
                                           b[0]=x1;b[1]=y2+1;b[2]=x2;b[3]=node->dom[3];
                                                node->hij[1]= new NodoQ<T>(-1,b);

                                           c[0]=x2+1;c[1]=y1;c[2]=node->dom[2];c[3]=y2;
                                                node->hij[2]= new NodoQ<T>(-1,c);

                                           d[0]=x2+1;d[1]=y2+1;d[2]=node->dom[2];d[3]=node->dom[3];
                                                node->hij[3]= new NodoQ<T>(-1,d);
                                          }
                                         for(int k=0;k<4;k++)
                                         {
                                               subdividir(node->hij[k]);
                                         }
                                }
                }

                void eliminar(NodoQ<T> * & node)
                {
                    NodoQ<T> * tmp= node;

                }


};


#endif // QUADTREE_H
