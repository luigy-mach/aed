#ifndef LISTA_CIRCULAR_SIMPLE
#define LISTA_CIRCULAR_SIMPLE

#include<iostream>
#include"nodo_simple.h"
using namespace std;

	
//----------------lista circular simple---------------------
template<class T>
class ListaCS{
	public:
		Nodo<T>* m_pHead;
	public:
		ListaCS():m_pHead(NULL){}
		~ListaCS(){}
		bool find(T d,Nodo<T>**& pp);
		bool add(T d);
		ListaCS<T>& operator>>(T d);
		void print();
		void remove(T d);
		//04
		int tamano();
		Nodo<T>* n_esimo(int n);
};

//----------------------DEFINICIONES_BASICAS--------------

template<class T>
bool ListaCS<T>::find(T d,Nodo<T>**& pp){
	pp=&m_pHead;
	while(*pp){
		if((*pp)->m_Dato==d) return true;
		if((*pp)->m_Dato>d) return false;
		pp=&((*pp)->m_pSig);
		if((*pp)==m_pHead) return false;
	}
	return false;
}
template<class T>
bool ListaCS<T>::add(T d){
	Nodo<T>** pptemp=NULL;
	if(!find(d,pptemp)){
		*pptemp=new Nodo<T>(d);
		(*pptemp)->m_pSig=m_pHead;
		return true;
	}
	return false;
}

template<class T>
ListaCS<T>& ListaCS<T>::operator>>(T d){
	add(d);
	return *this;
}

template<class T>
void ListaCS<T>::print(){
	Nodo<T>* temp=m_pHead;
	if(!temp) return;
	while(temp){
		cout<<" "<<temp->m_Dato;
		temp=temp->m_pSig;
		if(temp==m_pHead) break;
	}
	cout<<endl;	
	return;
}

template<class T>
void ListaCS<T>::remove(T d){
	Nodo<T>**temp=NULL;
	Nodo<T>* temp2=NULL;
	if( find(d,temp) ){
		temp2=(*temp);
		(*temp)=(*temp)->m_pSig;
		delete temp2;
	}
	return;
}
//----------------------EJERCICIOS------------------------

//EJERCICIO_04

template<class T>
int ListaCS<T>::tamano(){
 	int count=0;
	Nodo<T>* temp=m_pHead;
	while(temp){
		count++;
		temp=temp->m_pSig;
		if(temp==m_pHead) break;
	}
	return count;
}

template<class T>
Nodo<T>* ListaCS<T>::n_esimo(int n){
	int n_esimo=n%(this->tamano());
	Nodo<T>* temp=m_pHead;
	for(int i=0;i<n_esimo-1;i++)
		temp=temp->m_pSig;
	return temp;
}



#endif
