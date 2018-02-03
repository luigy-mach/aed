#ifndef BINOMIAL_H
#define BINOMIAL_H
#include "nodoB.h"
#include <iostream>

using namespace std;
template<class T>

class binomial
{
    private:
        static binomial * Instance;

        nodoB<T>* H;
        nodoB<T>* Hr;
        binomial(){}
    public:
        static binomial<T>* Init();
        //binomial();
        nodoB<T>* getHead();
        void setHead(nodoB<T>* a);
        binomial<T>* MAKE_BINOMIAL_HEAP();
        void BINOMIAL_LINK(nodoB<T>*,nodoB<T>*);
        void BINOMIAL_HEAP_UNION(binomial<T>*);
        void BINOMIAL_HEAP_INSERT(nodoB<T>*);
        void BINOMIAL_HEAP_MERGE(binomial<T>*);
        nodoB<T>* BINOMIAL_HEAP_EXTRACT_MIN(binomial<T>*);
        void REVERT_LIST(nodoB<T>*);
        nodoB<T>* FIND_NODE(binomial<T>*,nodoB<T>*);
        void BINOMIAL_HEAP_DECREASE_KEY(binomial<T>*,nodoB<T>*,T);
        void BINOMIAL_HEAP_DELETE(binomial<T>*,nodoB<T>*);

};

template<class T>
binomial<T>* binomial<T>::Instance=0;

template<class T>
binomial<T>* binomial<T>::Init()
{
    if(!Instance)
        return Instance=new binomial();
    return Instance;
}

template<class T>
nodoB<T>* binomial<T>:: getHead() {return H;}
template<class T>
void binomial<T>::setHead(nodoB<T> * a){ H=a;}

template<class T>

binomial<T>* binomial<T>::MAKE_BINOMIAL_HEAP()
  {
    binomial<T>* H1= new binomial<T>();
    H1->setHead(NULL);
    return H1;
  }
template<class T>
void binomial<T>::BINOMIAL_LINK(nodoB<T>* y,nodoB<T>* z)
  {
    y->parent=z;
    y->sibling=z->child;
    z->child=y;
    z->degree=z->degree+1;
  }
template<class T>
void binomial<T>::BINOMIAL_HEAP_INSERT(nodoB<T>* x)
  {
    binomial<T>* H1=MAKE_BINOMIAL_HEAP();
    x->parent=NULL;
    x->child=NULL;
    x->sibling=NULL;
    x->degree=0;
    H1->setHead(x);
    this->BINOMIAL_HEAP_UNION(H1);
    return ;
  }
template<class T>
void binomial<T>::BINOMIAL_HEAP_UNION(binomial<T>* H2)
{
    binomial<T>* H=MAKE_BINOMIAL_HEAP();
    this->BINOMIAL_HEAP_MERGE(H2);
    H=this;
    if(H->getHead()==NULL)
    {
      this->setHead(H->getHead());
      return ;
    }
    nodoB<T>* prev_x;
    nodoB<T>* next_x;
    nodoB<T>* x;
    prev_x=NULL;
    x=H->getHead();
    next_x=(nodoB<T>*)x->sibling;
    while(next_x!=NULL)
      {
        if((x->degree!=next_x->degree)||((next_x->sibling!=NULL)&&((nodoB<T>*)(next_x->sibling))->degree==x->degree))
            {
              prev_x=x;
              x=next_x;
            }
        else
            {
             if(x->key<=next_x->key)
              {
                x->sibling=next_x->sibling;
                BINOMIAL_LINK(next_x,x);
              }
             else
              {
                if(prev_x==NULL)
                  H->setHead(next_x);
                else
                  prev_x->sibling=next_x;
                BINOMIAL_LINK(x,next_x);
                x=next_x;
              }
            }
        next_x=(nodoB<T>*)x->sibling;
      }
    this->setHead(H->getHead());
   return ;
  }
template<class T>
void binomial<T>::BINOMIAL_HEAP_MERGE(binomial<T>* H2)
 {

   binomial<T>* H=MAKE_BINOMIAL_HEAP();
   nodoB<T>* y;
   nodoB<T>* z;
   nodoB<T>* a;
   nodoB<T>* b;
   y=this->getHead();
   z=H2->getHead();
   if(y!=NULL)
     {
       if(z!=NULL&&y->degree<=z->degree)
         H->setHead(y);
       else if(z!=NULL&&y->degree>z->degree)
         H->setHead(z);
       else
         H->setHead(y);
     }
   else
     H->setHead(z);
   while(y!=NULL&&z!=NULL)
     {
       if(y->degree<z->degree)
         {
           y=(nodoB<T>*)y->sibling;
         }
       else if(y->degree==z->degree)
         {
           a=(nodoB<T>*)y->sibling;
           y->sibling=z;
           y=a;
         }
       else
         {
           b=(nodoB<T>*)z->sibling;
           z->sibling=y;
           z=b;
         }
     }

   //delete H2;

   return;

 }

/* template<class T>
 binomial<T>* binomial<T>::BINOMIAL_HEAP_MERGE(binomial<T>* H1,binomial<T>* H2)
  {
    binomial<T>* H=MAKE_BINOMIAL_HEAP();
    nodoB<T>* y;
    nodoB<T>* z;
    nodoB<T>* a;
    nodoB<T>* b;
    y=H1->getHead();
    z=H2->getHead();
    if(y!=NULL)
      {
        if(z!=NULL&&y->degree<=z->degree)
          H->setHead(y);
        else if(z!=NULL&&y->degree>z->degree)
          H->setHead(z);
        else
          H->setHead(y);
      }
    else
      H->setHead(z);
    while(y!=NULL&&z!=NULL)
      {
        if(y->degree<z->degree)
          {
            y=(nodoB<T>*)y->sibling;
          }
        else if(y->degree==z->degree)
          {
            a=(nodoB<T>*)y->sibling;
            y->sibling=z;
            y=a;
          }
        else
          {
            b=(nodoB<T>*)z->sibling;
            z->sibling=y;
            z=b;
          }
      }
    return H;

  }
*/

template<class T>
nodoB<T>* binomial<T>::BINOMIAL_HEAP_EXTRACT_MIN(binomial<T>* H1)
  {
    Hr=NULL;
    nodoB<T>* t=NULL;
    nodoB<T>* x=H1->getHead();
    if(x==NULL)
      {
      //cout<<"\No se extrajo nada"<<endl;
      return x;
      }
    T min=x->key;
    nodoB<T>* p=x;
    while(p->sibling!=NULL)
      {
        if((p->sibling)->key<min)
          {
            min=(p->sibling)->key;
            t=p;
            x=(nodoB<T>*)p->sibling;
          }
        p=(nodoB<T>*)p->sibling;
      }
    if(t==NULL&&x->sibling==NULL)
      H1->setHead(NULL);
    else if(t==NULL)
      H1->setHead((nodoB<T>*)x->sibling);
    else if(t->sibling==NULL)
      t=NULL;
    else
      t->sibling=x->sibling;
    if(x->child!=NULL)
      {
        REVERT_LIST((nodoB<T>*)x->child);
        (x->child)->sibling=NULL;
      }
    binomial<T> * R1= MAKE_BINOMIAL_HEAP();
    R1->setHead(Hr);
    H1->BINOMIAL_HEAP_UNION(R1);
    H1->getHead();
    return x;
  }

template<class T>
void binomial<T>::REVERT_LIST(nodoB<T>* y)
  {
    if(y->sibling!=NULL)
      {
        REVERT_LIST((nodoB<T>*)y->sibling);
        (y->sibling)->sibling=y;
      }
    else
      {
        Hr=y;
      }
  }

template<class T>
nodoB<T>* binomial<T>::FIND_NODE(binomial<T>* H,nodoB<T>* k)
  {
    nodoB<T>* x=H->getHead();
    nodoB<T>* p=NULL;
    binomial<T> *a= new binomial<T>();
    if(x->key==k->key)
      {
        p=x;
        return p;
      }
    if(x->child!=NULL&&p==NULL)
      {   
          a->setHead((nodoB<T>*)x->child);
          p=FIND_NODE(a,k);
      }
    if(x->sibling!=NULL&&p==NULL)
      {
          a->setHead((nodoB<T>*)x->sibling);
       p=FIND_NODE(a,k);
      }
    return p;
    a=0;
    delete a;
  }
template<class T>
void binomial<T>::BINOMIAL_HEAP_DECREASE_KEY(binomial<T>* H, nodoB<T>* i,T k)
  {
    T temp;
    nodoB<T>* p;
    nodoB<T>* y;
    nodoB<T>* z;
    p=FIND_NODE(H,i);
    if(p==NULL)
      {
        cout<<"\n No existe el nodo !!!";
        return ;
      }
    /*if(k>p->key)
      {
      cout<<"\nLa clave es mayor a la anterior";
      return ;
      }*/
    p->key=k;
    y=p;
    z=(nodoB<T>*)p->parent;

    while(z!=NULL&&y->key<z->key)
      {
        temp=y->key;
        y->key=z->key;
        z->key=temp;
        y=z;
        z=(nodoB<T>*)z->parent;
      }
    cout<<"\nSe redujo!!!";
  }
template<class T>
void binomial<T>::BINOMIAL_HEAP_DELETE( binomial<T> * H,nodoB<T>* k)
  {
    nodoB<T>* np;
    if(H->getHead()==NULL)
      {
      cout<<"\nEl heap esta vacio!!!!!";
      return ;
      }
    BINOMIAL_HEAP_DECREASE_KEY(H,k,-1000);
    np=BINOMIAL_HEAP_EXTRACT_MIN(H);
    if(np!=NULL)
    cout<<"\nSe ha eliminado el nodo!!!";
  }

#endif // BINOMIAL_H
