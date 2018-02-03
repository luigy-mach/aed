#include "btree.h"
#include "pila.cpp"
#include "cola.cpp"
#include <iostream>
using namespace std;
template<class T>
btree<T>::btree()
{
    m_pRoot=0;
    //ctor
}
template<class T>

nodo<T>* btree<T>::getroot()
{
    return this->m_pRoot;
}
template<class T>
btree<T>::~btree()
{
    if(this->m_pRoot)
        this->m_pRoot->matate();
}
template<class T>
bool btree<T>::find(T d,nodo<T>**&p)
{
    p=&m_pRoot;
    while(*p)
    {
        if(d==((*p)->m_Dato))
            return true;
        p=&((*p)->m_pSon[(*p)->m_Dato<d]);
    }
    return false;
}
template<class T>
bool btree<T>::add(T d)
{
    nodo<T>**p;
    if(find(d,p)) return false;
    (*p)=new nodo<T>(d);
    return true;
}
template<class T>
bool btree<T>::remove(T d)
{
    return this->deletehoja(d);
    return this->deleteoneson(d);
    return this->deletetwoson(d);
}
template<class T>
bool btree<T>::deletehoja(T d)
{
	nodo<T>**p;
	if(find(d,p))
	{
        if(!(*p)->m_Son[0]&&!(*p)->m_Son[1])
        {
            delete (*p);
            (*p)=0;
            return true;
        }
        return false;
     }
     return false;
}
template<class T>
bool btree<T>::deleteoneson(T d)
{
     nodo<T> ** p;
     if(find(d,p))
     {
        if((*p)->m_Son[0]&&!(*p)->m_Son[1])
        {
            nodo<T> * tmp=(*p);
            (*p)=tmp->m_Son[0];
             delete tmp;
             return true;
        }
        if((*p)->m_Son[1]&&!(*p)->m_Son[0])
        {
            nodo<T> * tmp=(*p);
            (*p)=tmp->m_Son[1];
            delete tmp;
            return true;
        }
        return false;
    }
    return false;
}
template<class T>
bool btree<T>::deletetwoson(T d)
{
    nodo<T> ** p;
    if(find(d,p))
    {
        if((*p)->m_Son[0]&&(*p)->m_Son[1])
        {
            nodo<T> ** q=&((*p)->m_Son[0]);
            while((*q)->m_Son[1])
            {
                q=&((*q)->m_Son[1]);
            }
            (*p)->m_Dato=(*q)->m_Dato;
            nodo<T> * r = (*q);
            (*q)=(*q)->m_Son[0];
            delete r;
            return true;
        }
        return false;
    }
    return false;
}

template<class T>
void btree<T>::rp()
{
    Pila<nodo<T>*> p();
    p.Push(m_pRoot);
    while(!p.isEmpty())
    {
        nodo<T> * t;
        p.Pop(t);
        cout<<t.m_Dato<<endl;
        if(t->m_pSon[1]) p.Push(t->m_pSon[0]);
        if(t->m_pSon[0]) p.Push(t->m_pSon[1]);
    }
}
template<class T>
void btree<T>::ra()
{
    Cola<nodo<T>*> p();
    p.Push(m_pRoot);
    while(!p.isEmpty())
    {
        nodo<T> * t;
        p.Pop(t);
        cout<<t.m_Dato<<endl;
        if(t->m_pSon[1]) p.Push(t->m_pSon[0]);
        if(t->m_pSon[0]) p.Push(t->m_pSon[1]);
    }
}
template<class T>
void btree<T>::rii(nodo<T>*&p)
{
    nodo<T>*q=p->m_pSon[0];
    p->m_pSon[0]=q->m_pSon[1];
    q->m_pSon[1]=p;
    p->fe=q->fe=0;
    p=q;
}
template<class T>
void btree<T>::rdd(nodo<T>*&p)
{
    nodo<T>*q=p->m_pSon[1];
    p->m_pSon[1]=q->m_pSon[0];
    q->m_pSon[0]=p;
    p->fe=q->fe=0;
    p=q;
}
template<class T>
void btree<T>::rdi(nodo<T>*&p)
{
    nodo<T>*q=p->m_pSon[1];
    nodo<T>*z=q->m_pSon[0];
    p->m_pSon[1]=z->m_pSon[0];
    q->m_pSon[0]=z->m_pSon[1];
    z->m_pSon[0]=p;
    z->m_pSon[1]=q;
    if(z->fe==0)
    {
        p->fe=q->fe=z->fe=0;
        return;
    }
    if(z->fe==1)
    {
        p->fe=0;
        q->fe=-1;
        z->fe=1;
        return;
    }
    if(z->fe==-1)
    {
        p->fe=1;
        q->fe=-0;
        z->fe=-1;
        return;
    }
}
