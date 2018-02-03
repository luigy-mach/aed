#ifndef LISTA_DOBLE
#define LISTA_DOBLE



////////////////////////////////////////
#include"estructura.h"
#include"nodo.h"
#include<stack>
////////////////////////////////////////
#include<iostream>
using namespace std;


//----------------------Clase NodoD ListaD----------------


template<class T>
class NodoD : public Nodo<T>{
	public:
		T m_Dato;
		NodoD<T>* m_pSig;
		NodoD<T>* m_pAnt;
	public:
		NodoD(T d):m_pSig(NULL),m_pAnt(NULL),m_Dato(d){}
		~NodoD(){}
};

//------------------------Clase ListaD----------------------

template<class T>
class ListaD : public Estructura<T>{
	public:
		NodoD<T>* m_pHead;
		
		ListaD():m_pHead(NULL){}		
		bool find(T& d,NodoD<T>**& p);
		void ins_recusivo(T d,NodoD<T>** p,NodoD<T>**& tt);

		void print(ofstream & a);
	/////////////////////////////////////////
		void find(T& in,T& out);
		void insertar(const T& d);
		void print_dot();
	/////////////////////////////////////////

		
};

///////////////////////////////////////////////////////
template<class T>
void ListaD<T>::find(T& in,T& out){
	NodoD<T>**tt=NULL;
	find(in,tt)? out=(*tt)->m_Dato : out=NULL;
}
template<class T>
void ListaD<T>::insertar(const T& d){
	NodoD<T>** p=&m_pHead;	
	stack< NodoD<T>* > pila;

	while(*p){
		if((*p)->m_Dato->operator==(d)) return;
		if((*p)->m_Dato->operator>(d)) break;
		pila.push(*p);
		p=&(*p)->m_pSig;
	}
	if(!(*p)){(*p)=new NodoD<T>(d); return;}
	NodoD<T>* temp=new NodoD<T>(d);
	temp->m_pSig=(*p)->m_pSig;
	if(!pila.empty()) pila.pop();
	temp->m_pAnt=pila.top();
	(*p)->m_pSig=temp;
	if(!temp->m_pSig) return;
	temp->m_pSig->m_pAnt=temp;
	return;	
}


///////////////////////////////////////////////////////
//---------------------definiciones basicas-------------------
template<class T>
bool ListaD<T>::find(T& d,NodoD<T>**& pp){
	pp=&m_pHead;
	while(*pp){
		if((*pp)->m_Dato->operator==(d)) return true;
		if((*pp)->m_Dato->operator>(d)) return false;
		pp=&(*pp)->m_pSig;
	}
	return false;
}

template<class T>
void ListaD<T>::print(ofstream & a){
	NodoD<T>* temp=m_pHead;
	while(temp){
		if(temp->m_pSig) a<<" "<<temp->m_Dato->model<<" -> "<<temp->m_pSig->m_Dato->model<<";"<<endl;
		temp=temp->m_pSig;	
	}

	cout<<endl;
}

template<class T>
void ListaD<T>::print_dot(){
	ofstream flujo_entrada("luigy.dot");
	if(!flujo_entrada)
		cout<<"falla en la apertura"<<endl;
	else{
		flujo_entrada<<"digraph G{"<<endl;		
		flujo_entrada<<"rankdir=LR"<<endl;
		flujo_entrada<<"edge [dir=\"both\"]"<<endl;
		this->print(flujo_entrada);
		flujo_entrada<<"}"<<endl;
	}

}



#endif
