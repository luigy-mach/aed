#ifndef LISTA_SIMPLE
#define LISTA_SIMPLE

#include<cmath>
#include<stack>
#include<iostream>
#include"nodo_simple.h"
using namespace std;

//#define NULL 0

//----------------------Clase Nodo Lista----------------

	//...nodo_simple.h

//------------------------Clase Lista----------------------

template<class T>
class Lista{
	public:
		Nodo<T>* m_pHead;
		
		Lista():m_pHead(NULL){}	
		void destruyete();	
		bool find(T d,Nodo<T>**& p);
		bool add(T d);
		Lista<T>& operator>>(T d);
		bool es_ordenada();
		void print();
		void push_front(T d);
		void push_back(T d);
		int tamano();
		bool estaVacia();
		//02
		void agregarUniverso(Lista<T>* u);
		Lista<T>* m_pUniverso;
		Lista<T>& complemento();
		Lista<T>& interseccion(Lista<T>& b);
		//05
		bool inserta_ordenado(T d);
		//06
		void ordenar();
		//08
		void anadir_cab_de(Lista<T>& b);
		//10
			//falta
		//11
		void reverse_ite();	
		//12
		void reverse_recur();
		void reverse_recursivo(Nodo<T>*& p, Nodo<T>**& t);
			
};

//------------------------Definiciones Basicas------------
template<class T>
void Lista<T>::destruyete(){
	m_pHead->matate();
	delete this;
}

template<class T>
bool Lista<T>::find(T d,Nodo<T>**& p){
	p=&m_pHead;
	while(*p){
		if((*p)->m_Dato==d) return true;
		if((*p)->m_Dato>d) return false;
		p=&(*p)->m_pSig;
	}
	return false;
}


template<class T>
bool Lista<T>::add(T d){
	Nodo<T>**temp=NULL;
	if(find(d,temp))
		return false;
	*temp=new Nodo<T>(d);
	return true;	
}

template<class T>
Lista<T>& Lista<T>::operator>>(T d){
	this->add(d);
	return 	*this;
}

template<class T>
bool Lista<T>::es_ordenada(){



	Nodo<T>* temp=m_pHead;
	while(temp){
		if(!temp->m_pSig) return true;
		if(temp->m_Dato > temp->m_pSig->m_Dato) return false;
	}
	return true;
}

template<class T>
void Lista<T>::print(){
	Nodo<T>* temp=m_pHead;
	while(temp){
		cout<<" "<<temp->m_Dato;
		temp=temp->m_pSig;
	}
	cout<<"-"<<endl;
}

template<class T>
void Lista<T>::push_front(T d){
	Nodo<T>* temp=m_pHead;
	m_pHead=new Nodo<T>(d);
	m_pHead->m_pSig=temp;
	return;
}

template<class T>
void Lista<T>::push_back(T d){
	Nodo<T>** temp=&m_pHead;
	while(*temp)
		temp=&( (*temp)->m_pSig );
	(*temp)=new Nodo<T>(d);
	return;
}

template<class T>
int Lista<T>::tamano(){
	Nodo<T>*temp=m_pHead;
	int count=0;
	while(temp){
		temp=temp->m_pSig;
		count++;
	}
	return count;
}

template<class T>
bool Lista<T>::estaVacia(){
	return !m_pHead?true:false;
}


//----------------------EJERCICIOS---------------------------

//EJERCICIO_02
template<class T>
void Lista<T>::agregarUniverso(Lista<T>* u){
	m_pUniverso=u;
	return;
}

template<class T>
Lista<T>& Lista<T>::complemento(){
	Nodo<T>** pp=NULL;
	Nodo<T>* temp1=m_pUniverso->m_pHead;
	Lista<T> *comp=new Lista<T>();	
	while(temp1){
		if( !this->find(temp1->m_Dato,pp) )
			comp->add(temp1->m_Dato);	
		temp1=temp1->m_pSig;
	}
	return *comp;
}

template<class T>
Lista<T>& Lista<T>::interseccion(Lista<T>& b){
	Lista<T>* intersecc=new Lista<T>();
	Nodo<T>* temp1=this->m_pHead;
	Nodo<T>** temp2=NULL;
	while(temp1){
		if(b.find(temp1->m_Dato,temp2))
			intersecc->add(temp1->m_Dato);
		temp1=temp1->m_pSig;
	}	
	return *intersecc;
}


//EJERCICIO_05
template<class T>
bool Lista<T>::inserta_ordenado(T d){
	Nodo<T>**temp2=NULL;
	Nodo<T>*temp3=NULL;
	if(!m_pHead) m_pHead=new Nodo<T>(d);
	if(!find(d,temp2)){
		temp3=(*temp2);
		*temp2=new Nodo<T>(d);
		(*temp2)->m_pSig=temp3;
		return true;
	}
	return false;	
}


//EJERCICIO_06 ----- condicion: usando insertar_ordenado
template<class T>
void Lista<T>::ordenar(){
	
	Nodo<T>* temp1=m_pHead;
	stack< Nodo<T>* > pila;
	while(temp1){
		pila.push(temp1);
		temp1=temp1->m_pSig;
	}
	m_pHead=temp1=NULL;
	while( !pila.empty() ){
		temp1=pila.top();
		pila.pop();
		this->inserta_ordenado(temp1->m_Dato);
		delete temp1;		
	}
	return;
}


//EJERCICIO_08	
template<class T>
void Lista<T>::anadir_cab_de(Lista<T>& b){
	Nodo<T>* temp=b.m_pHead;
	b.m_pHead=b.m_pHead->m_pSig;
	temp->m_pSig=this->m_pHead;
	this->m_pHead=temp;
	return;	
}

//EJERCICIO_10
	//implementar luego


//EJERCICIO_11
template<class T>
void Lista<T>::reverse_ite(){
	Nodo<T>* temp=m_pHead;
	stack< Nodo<T>* > pila;
	while(temp){
		pila.push(temp);
		temp=temp->m_pSig;
	}
	m_pHead=temp=pila.top();
	pila.pop();
	while( !pila.empty() ){	
		temp->m_pSig=pila.top();	
		temp=temp->m_pSig;
		pila.pop();

	}
	temp->m_pSig=NULL;	
	return;
}

//EJERCICIO_12
template<class T>
void Lista<T>::reverse_recur(){
	Nodo<T>*  temp1=m_pHead;
	Nodo<T>** temp2=NULL;
	reverse_recursivo(temp1,temp2);
	(*temp2)->m_pSig=NULL;
	return;
}

template<class T>
void Lista<T>::reverse_recursivo(Nodo<T>*&p, Nodo<T>**& t){
	if(!p){
		t=&p;
		return;
	}
	reverse_recursivo(p->m_pSig,t);
	if(!(*t)){
		t=&p;
		m_pHead=(*t);
		return;
	}
	else{
		(*t)->m_pSig=p;
		t=&p;
		return;
	}
}




#endif
