#ifndef AVL_H_
#define AVL_H_

#include<iostream>
#include<stack>
#include <fstream>
using namespace std;
//////////////////////////////////////////
#include "recursos/estructura.h"
#include "recursos/nodo.h"
#include "recursos/defines.h"
//////////////////////////////////////////

const static int der=1;
const static int izq=0;

//-----------------------------NODOAVL---------------------------
template<class T>
class NodoAvl : public Nodo<T>{
	public:
		T m_Dato;	
		int m_FE;
		NodoAvl<T>* m_pSon[2];
	public:
		NodoAvl(T d):m_FE(0){
			m_Dato=d;
			m_pSon[0]=m_pSon[1]=NULL;
		}
		~NodoAvl(){cout<<"~NodoAvl()"<<endl;}
};
//-------------------------------AVL-----------------------	
template<class T>
class AVL : public Estructura<T> {
	public:
		NodoAvl<T>* m_pRoot;
	public:
		AVL():m_pRoot(NULL){}
		~AVL(){cout<<"~AVL()"<<endl;}

        /////////////////////////////////////////
		void find(T& in, T& out);
        void insertar(const T& d);
        T* minimo ();
        T* maximo();
        T* siguiente(T& d);
        T* anterior(T& d);
        void print_dot();
        /////////////////////////////////////////

		bool find(const T& d,NodoAvl<T>**& pp);
        void insertar_rec(const T& d, NodoAvl<T>*&p,bool *stop);
		void RS(bool doi, NodoAvl<T>*& p);
		void RD(bool doi, NodoAvl<T>*& p);
		void print(ofstream & a);

		
};
//---------------------------------------------------------	
//---------------------------------------------------------	
template<class T>
void AVL<T>::find(T& in, T& out){
	NodoAvl<T>**tt=NULL;
	find(in,tt)? out=(*tt)->m_Dato : out=NULL;
	
}

//-----------------------------------------------------

template<class T>
bool AVL<T>::find(const T& d,NodoAvl<T>**& pp){
	pp=&m_pRoot;
	while(*pp){
		if((*pp)->m_Dato->operator==(d)) return true;
		pp=&(*pp)->m_pSon[(*pp)->m_Dato->operator<(d)];
	}
	return false;
	
}

template<class T>
void AVL<T>::insertar(const T& d){
	bool *stop=new bool(false);
	insertar_rec(d,m_pRoot,stop);
	delete stop;
}
template<class T>
void AVL<T>::insertar_rec(const T& d, NodoAvl<T>*&p,bool *stop){
	if(!p){p=new NodoAvl<T>(d);return;}
	if(p->m_Dato->operator==(d)) return;
	insertar_rec(d,p->m_pSon[p->m_Dato->operator<(d)],stop);
	if(*stop) return;
	p->m_FE+=((p->m_Dato)->operator<(d))?1:-1;
	switch(p->m_FE){
		case  0: return;
		case  2:(p->m_pSon[1]->m_FE>0)?RS(der,p):RD(der,p);
			*stop=true;
			return;
		case -2:(p->m_pSon[0]->m_FE<0)?RS(izq,p):RD(izq,p);			      
			*stop=true;
			return;
	} 
}

template<class T>
void AVL<T>::RS(bool doi, NodoAvl<T>*&p){
	NodoAvl<T>*q=p->m_pSon[doi];
	p->m_pSon[doi]=q->m_pSon[!doi];
	q->m_pSon[!doi]=p;
	p->m_FE=q->m_FE=0;
	p=q;
	return;
}

template<class T>
void AVL<T>::RD(bool doi, NodoAvl<T>*& p){
	NodoAvl<T>* q=p->m_pSon[doi];
	NodoAvl<T>* r=q->m_pSon[!doi];
	p->m_pSon[doi]=r->m_pSon[!doi];
	q->m_pSon[!doi]=r->m_pSon[doi];
	r->m_pSon[doi]=q;
	r->m_pSon[!doi]=p;

	if(r->m_FE==0){
		 p->m_FE=q->m_FE=r->m_FE;
	}
	else{
        if(doi==true){	
	        if(r->m_FE==1){
		        p->m_FE=-1;
		        q->m_FE=0;
		        r->m_FE=1;
	        }
	        else {//-1
		        p->m_FE=0;
		        q->m_FE=1;
		        r->m_FE=-1;
	        }
        }
        else{//doi=false
	        if(r->m_FE==1){
		        p->m_FE=0;
		        q->m_FE=-1;
		        r->m_FE=1;
	        }
	        else {//-1
		        p->m_FE=1;
		        q->m_FE=0;
		        r->m_FE=-1;
	       }
        }
	}
	p=r;
}

template<class T>
void AVL<T>::print(ofstream & a){
	stack< NodoAvl<T>* > pila;
	NodoAvl<T>* temp=m_pRoot;
	pila.push(temp);
	while( !pila.empty() ){
		temp=pila.top();
		pila.pop();
		if(temp->m_pSon[0])
            a<<" "<<temp->m_Dato->word<<" -> "<<temp->m_pSon[0]->m_Dato->word<<";"<<endl;
		if(temp->m_pSon[1])
        a<<" "<<temp->m_Dato->word<<" -> "<<temp->m_pSon[1]->m_Dato->word<<";"<<endl;
		if(temp->m_pSon[1]) pila.push(temp->m_pSon[1]);
		if(temp->m_pSon[0]) pila.push(temp->m_pSon[0]);
		
		
	}
	cout<<endl;
}

template<class T>
void AVL<T>::print_dot(){
    ofstream flujo_entrada(FILE_DOT);
    cout<<"*************************************"<<endl;
	if(!flujo_entrada)
		cout<<"falla en la apertura"<<endl;
	else{
		flujo_entrada<<"digraph{"<<endl;		
		this->print(flujo_entrada);
		flujo_entrada<<"}"<<endl;
    }
}

template<class T>
T* AVL<T>::minimo(){
    NodoAvl<T>** p=&m_pRoot;
    while(*p){
        if(!(*p)->m_pSon[0]) break;
        p=&((*p)->m_pSon[0]);
    }
    return &(*p)->m_Dato;
}

template<class T>
T* AVL<T>::maximo(){
    NodoAvl<T>** p=&m_pRoot;
    while(*p){
        if(!(*p)->m_pSon[1]) break;
        p=&((*p)->m_pSon[1]);
    }
    return &(*p)->m_Dato;
}
template<class T>
T* AVL<T>::siguiente(T& d){
    stack< NodoAvl<T>* > pila;

    NodoAvl<T>**p=&m_pRoot;
    if(!*p) return NULL;
    find(d,p);
    if((*p)->m_pSon[1])
        return &(*p)->m_pSon[1]->m_Dato;

    p=&m_pRoot;
    while(*p){
        if((*p)->m_Dato->operator==(d)){
            pila.push(*p);
            break;
        }
        pila.push(*p);
        p=&(*p)->m_pSon[(*p)->m_Dato->operator<(d)];

    }
    NodoAvl<T>* temp=pila.top();
    pila.pop();
    while(!pila.empty()){
        p=&pila.top();
        pila.pop();
        if(temp->m_Dato->operator<((*p)->m_Dato))
            return &(*p)->m_Dato;
    }
   return &d;
}
template<class T>
T* AVL<T>::anterior(T& d){

    stack< NodoAvl<T>* > pila;

    NodoAvl<T>**p=&m_pRoot;
    if(!*p) return NULL;
    find(d,p);
    if((*p)->m_pSon[0])
        return &(*p)->m_pSon[0]->m_Dato;

    p=&m_pRoot;
    while(*p){
        if((*p)->m_Dato->operator==(d)){
            pila.push(*p);
            break;
        }
        pila.push(*p);
        p=&(*p)->m_pSon[(*p)->m_Dato->operator<(d)];

    }
    NodoAvl<T>* temp=pila.top();
    pila.pop();
    while(!pila.empty()){
        p=&pila.top();
        pila.pop();
        if(temp->m_Dato->operator>((*p)->m_Dato))
            return &(*p)->m_Dato;
    }
   return &d;
}



//---------------------------------------------------------	
#endif 


