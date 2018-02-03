#ifndef BTREE
#define BTREE

#include<queue>
#include<stack>
#include<iostream>
using namespace std;	

//////////////////////////////////////////
#include"recursos/estructura.h"
#include"recursos/nodo.h"
//////////////////////////////////////////


//-----------------------NODOBTREE------------------------------
template<class T>
class NodoBtree : public Nodo<T> {
	public:
		T m_Dato;
		NodoBtree<T>* m_pSon[2];
	public:
		NodoBtree(const T d){
			m_Dato=d;
			m_pSon[0]=m_pSon[1]=NULL;
		}
};

//-----------------------BTREE------------------------------

template<class T>
class Btree : public Estructura<T> {
	public:
		NodoBtree<T>* m_pRoot;	
	public:	
	Btree():m_pRoot(NULL){}
	Btree(Btree<T>& b):m_pRoot(NULL){ 
		Btree<T>* temp=&b;
		copiar(temp); }
	~Btree(){destruyete(); }

	bool find(T d,NodoBtree<T>**& p);
	bool add(const T d);
	void insertar(T d){ this->add(d); }
	bool remove(const T& d);
	bool min_or_max(NodoBtree<T>**& p,bool min_OR_max);//p = pSon_Root
	void print_BFS();
	void destruyete();
	void destruyete_recursivo(NodoBtree<T>*p);
	void copiar(Btree<T>* b);
	void copiar_recursivo(NodoBtree<T>*& p);

	Btree<T>& operator>>( T d);
	Btree<T>& operator+(Btree& b);
	Btree<T>& operator-(Btree& b);	
	Btree<T>& operator=(Btree& b);
};

//----------------------------------------------------------

template<class T>
bool Btree<T>::find(T d,NodoBtree<T>**& p){
	p=&m_pRoot;
	while(*p){
		if((*p)->m_Dato==d) return true;
		p=&(*p)->m_pSon[(*p)->m_Dato<d];
	}
	return false;
}

template<class T>
bool Btree<T>::remove(const T& d){
	NodoBtree<T>** temp1=&m_pRoot;
	NodoBtree<T>** temp2=NULL;
	NodoBtree<T>* nodo_remove=NULL;
		
	if( !find(d,temp1) ) return false;
	nodo_remove=*temp1;
	
	temp2=&(*temp1)->m_pSon[0];
	if ( *temp2 ){
		min_or_max(temp2,1);
		(*temp2)->m_pSon[0]=(*temp1)->m_pSon[0];
		(*temp2)->m_pSon[1]=(*temp1)->m_pSon[1];
		(*temp1)=(*temp2);
		(*temp2)=NULL;
		delete nodo_remove;
		return true;
	}
			

	temp2=&(*temp1)->m_pSon[1];
	if ( *temp2 ){
		min_or_max(temp2,0);
		(*temp2)->m_pSon[0]=(*temp1)->m_pSon[0];
		(*temp2)->m_pSon[1]=(*temp1)->m_pSon[1];
		(*temp1)=(*temp2);
		(*temp2)=NULL;
		delete nodo_remove;
		return true;
	}
	
	(*temp1)=NULL;
	delete	nodo_remove;
	return true;
		
}

template<class T>
bool Btree<T>::min_or_max(NodoBtree<T>**& p,bool min_OR_max){
	if(!p)	return false;
	while( (*p)->m_pSon[ min_OR_max] ){
		p=&(*p)->m_pSon[min_OR_max];
	}
	return true;
}



template<class T>
void Btree<T>::print_BFS(){
	if(!m_pRoot){
		cout<<"arbol vacio"<<endl;
		return;
	}
	NodoBtree<T>* temp=m_pRoot;
	queue< NodoBtree<T>* > cola;
	cola.push(temp);
	while( !cola.empty() ){
		temp=cola.front();
		cout<<" "<<temp->m_Dato;
		cola.pop();
		if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);	
		if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);	
	}	
	cout<<endl;
	return;	
}


template<class T>
void Btree<T>::destruyete_recursivo(NodoBtree<T>* p){
	if( p->m_pSon[0] ) destruyete_recursivo(p->m_pSon[0]);
	if( p->m_pSon[1] ) destruyete_recursivo(p->m_pSon[1]); 
	delete p;
	return;
}

template<class T>
void Btree<T>::destruyete(){
	destruyete_recursivo(m_pRoot);
	m_pRoot=NULL;
	return;
}



template<class T>
void Btree<T>::copiar(Btree<T>* b){
	NodoBtree<T>* temp=b->m_pRoot;	
	copiar_recursivo(temp);
	return;
}	


template<class T>
void Btree<T>::copiar_recursivo(NodoBtree<T>*& p){
	this->add(p->m_Dato);
	if(p->m_pSon[0]) copiar_recursivo(p->m_pSon[0]);
	if(p->m_pSon[1]) copiar_recursivo(p->m_pSon[1]);
	return;
}


template<class T>
Btree<T>& Btree<T>::operator>>(T d){
	this->add(d);
	return *this;
}

template<class T>
Btree<T>& Btree<T>::operator+(Btree& b){
	Btree<T>* pNew=new Btree<T>(*this);
	pNew->copiar(&b);
	return *pNew;
}

template<class T>
Btree<T>& Btree<T>::operator-(Btree& b){
	Btree<T>* pNew=new Btree<T>(*this);
	NodoBtree<T>* temp1=pNew->m_pRoot;
	NodoBtree<T>** temp2=NULL;

	queue< NodoBtree<T>* > cola;
	stack< NodoBtree<T>* > pila_delete;
	cola.push(temp1);
	while( !cola.empty() ){
		temp1=cola.front();
		cola.pop();
		if( b.find(temp1->m_Dato,temp2) ) pila_delete.push(temp1);
		if(temp1->m_pSon[0]) cola.push(temp1->m_pSon[0]);
		if(temp1->m_pSon[1]) cola.push(temp1->m_pSon[1]);
	}
	
	while( !pila_delete.empty() ){
		temp1=pila_delete.top();
		pila_delete.pop();
		pNew->remove(temp1->m_Dato);
	}
	return *pNew;
}

template<class T>
Btree<T>& Btree<T>::operator=(Btree& b){
	this->copiar(&b);
	return *this;
}







#endif

