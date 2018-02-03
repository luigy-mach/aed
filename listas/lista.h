#ifndef LISTA
#define LISTA

#include <stack>
#include "nodo.h"

template<class T>
class Lista{	
	public:
		Nodo<T>* m_pHead;
	Lista():m_pHead(NULL){}
	Lista(Lista<T>& a):m_pHead(NULL){ copiar(&a); }
	void push_front(const T d);
	void push_back(const T d);
	void print();
	bool find(T d,Nodo<T>**& p);
	bool add(T& d);
	Lista<T>& operator+(Lista<T> b);
	void operator=(Lista<T>& b);
	Lista<T>& operator>>(const T d);
	bool esta_vacia();
	void copiar(Lista<T>* b);
	void destruyete();
	void invertir();
};

template<class T>
void Lista<T>::push_front(const T d){
	if(!m_pHead){
		 m_pHead=new Nodo<T>(d);
		return;
	}
	Nodo<T>* temp=new Nodo<T>(d);
	temp->m_pSig=m_pHead;
	m_pHead=temp;
	
	return;
		
}

template<class T>
void Lista<T>::push_back(const T d){
	Nodo<T>** p=&m_pHead;
	while(*p)
		p=&(*p)->m_pSig;
	*p=new Nodo<T>(d);
	return;	
}


template<class T>
void Lista<T>::print(){
	Nodo<T>*temp=m_pHead;
	if(!temp) {
		cout<<"no hay elementos"<<endl;
	}
	while(temp){
		cout<<" "<<temp->m_Dato;
		temp=temp->m_pSig;
	}	
	cout<<endl;
	return;
}




template<class T>
bool Lista<T>::find(T d,Nodo<T>**& p){
	p=&m_pHead;
	while(*P){
		if((*p)->m_Dato==d) return true;
		if((*p)->m_Dato>d) return false;		
		p=&(*p)->m_pSig;
	}	
	return false;
}

template<class T>
bool Lista<T>::add(T& d){
	Nodo<T>** temp;
	if(find(d,temp)) return false;
	Nodo<T>* pNew=new Nodo<T>(d);
	pNew->m_pSig=*temp;	
	(*temp)=pNew;
	return true;
}

template<class T>
Lista<T>& Lista<T>::operator+(Lista<T> b){
	Lista<T>* pNuevo=new Lista<T>(*this);
	pNuevo->copiar(&b);
	return *pNuevo;
}


template<class T>
void Lista<T>::operator=(Lista<T>& b){
	if(this->esta_vacia()){
		this->copiar(& b);		
	}
	else{
		this->destruyete();
		this->copiar(& b);		
	}
	return;
}

template<class T>
Lista<T>& Lista<T>::operator>>(T d){
	push_back(d);
	return *this;
}



template<class T>
bool Lista<T>::esta_vacia(){
	if(!m_pHead) return true;
	return false;
}

template<class T>
void Lista<T>::copiar(Lista<T>* b){
	Nodo<T>* temp=b->m_pHead;
	while(temp){
		this->push_back(temp->m_Dato);
		temp=temp->m_pSig;
	}
	return;
}

template<class T>
void Lista<T>::destruyete(){
	Nodo<T>* temp=m_pHead;
	stack< Nodo<T>* > pila;
	while(temp){
		pila.push(temp);
		temp=temp->m_pSig;	
	}
	while(!pila.empty()){
		delete pila.top();
		pila.pop();
	}
	m_pHead=NULL;
	return;
}

template<class T>
void Lista<T>::invertir(){
	Nodo<T>* temp=m_pHead;
	stack< Nodo<T>* > pila;
	while(temp){
		pila.push(temp);
		temp=temp->m_pSig;
	}
	m_pHead=pila.top();
	while(!pila.empty()){
		temp=pila.top();
		pila.pop();
		if(pila.empty())break;
		temp->m_pSig=pila.top();
	}
	temp->m_pSig=NULL;
	return;
}



#endif

