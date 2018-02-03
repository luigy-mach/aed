
#ifndef LISTA_DOBLE
#define LISTA_DOBLE

#include<iostream>
#include"nodo_doble.h"
using namespace std;


//----------------------Clase NodoD ListaD----------------

	//...nodo_doble.h

//------------------------Clase ListaD----------------------

template<class T>
class ListaD{
	public:
		NodoD<T>* m_pHead;
		
		ListaD():m_pHead(NULL){}		
		bool find(T d,NodoD<T>**& p);
		//bool add(T d);
		//ListaD<T>& operator>>(T d);
		//bool es_ordenada();
		void print();
		//void tamano();

		//14<---
		void insertar_rec(T d);
		void ins_recusivo(T d,NodoD<T>** p,NodoD<T>**& tt);
		//15
		ListaD<T>* encontrar_suma(T d);
};

//---------------------definiciones basicas-------------------
template<class T>
bool ListaD<T>::find(T d,NodoD<T>**& pp){
	pp=&m_pHead;
	while(*pp){
		if((*pp)->m_Dato==d) return true;
		if((*pp)->m_Dato<d) return false;
		pp=&(*pp)->m_pSig;
	}
	return false;
}

template<class T>
void ListaD<T>::print(){
	NodoD<T>* temp=m_pHead;
	while(temp){
		cout<<" "<<temp->m_Dato;	
		temp=temp->m_pSig;
	}	
	cout<<"-"<<endl;
}


//------------------------ejercicios--------------------------


//EJERCICIO_14
template<class T>
void ListaD<T>::insertar_rec(T d){
	NodoD<T>** temp1=&m_pHead;	
	NodoD<T>** temp2=NULL;
	ins_recusivo(d,temp1,temp2);
	return;
}

template<class T>
void ListaD<T>::ins_recusivo(T d,NodoD<T>** p,NodoD<T>**& tt){
	if(!(*p)){
		(*p)=new NodoD<T>(d);
		tt=p;
		return;
	}
	ins_recusivo(d,&(*p)->m_pSig,tt);
	if(!(*tt)->m_pAnt){
		(*tt)->m_pAnt=(*p);
		tt=p;
	}
}


//EJERCICIO_15

template<class T>
ListaD<T>* ListaD<T>::encontrar_suma(T d){
	ListaD<T>* xx=new ListaD<T>();
	NodoD<T>*  temp=m_pHead;
	NodoD<T>** pp=NULL;
	//if(this->estaOrdenada()) this->ordenar;
	while(temp){
		if(find(abs(d-(temp->m_Dato)),pp)){
			xx->insertar_rec(temp->m_Dato);
			xx->insertar_rec((*pp)->m_Dato);
			break;
		}			
		temp=temp->m_pSig;
	}
	return xx;
}


#endif
