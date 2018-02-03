#ifndef BTREE
#define BTREE

#include<queue>
#include<stack>
#include<iostream>
using namespace std;	




template<class T>
class Nodo{
	public:
		T m_Dato;
		Nodo<T>* m_pSon[2];
	public:
		Nodo(const T d){
			m_Dato=d;
			m_pSon[0]=m_pSon[1]=NULL;
		}
};

//-----------------------------------------------------

template<class T>
class Btree{
	public:
		Nodo<T>* m_pRoot;	
	public:	
	Btree():m_pRoot(NULL){}
	Btree(Btree<T>& b):m_pRoot(NULL){ 
		Btree<T>* temp=&b;
		copiar(temp); }
	~Btree(){destruyete(); }

	bool find(T d,Nodo<T>**& p);
	bool add(const T d);
	bool remove(const T& d);
	bool min_or_max(Nodo<T>**& p,bool min_OR_max);//p = pSon_Root
	void print_BFS();
	void destruyete();
	void destruyete_recursivo(Nodo<T>*p);
	void copiar(Btree<T>* b);
	void copiar_recursivo(Nodo<T>*& p);

	Btree<T>& operator>>( T d);
	Btree<T>& operator+(Btree& b);
	Btree<T>& operator-(Btree& b);	
	Btree<T>& operator=(Btree& b);
	//----------------laboratorio---------------
	void print_infijo_re(Nodo<T>* p);
	void print_infijo_it();
};

//----------------------------------------------------------

template<class T>
bool Btree<T>::find(T d,Nodo<T>**& p){
	p=&m_pRoot;
	while(*p){
		if((*p)->m_Dato==d) return true;
		p=&(*p)->m_pSon[(*p)->m_Dato<d];
	}
	return false;
}

template<class T>
bool Btree<T>::add(const T d){
	Nodo<T>** temp=&m_pRoot;
	if( find(d,temp) ) return false;
	*temp=new Nodo<T>(d);
	return true;
}

 template<class T>
bool Btree<T>::remove(const T& d){
	Nodo<T>** temp1=&m_pRoot;
	Nodo<T>** temp2=NULL;
	Nodo<T>* nodo_remove=NULL;
		
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
bool Btree<T>::min_or_max(Nodo<T>**& p,bool min_OR_max){
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
	Nodo<T>* temp=m_pRoot;
	queue< Nodo<T>* > cola;
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
void Btree<T>::destruyete_recursivo(Nodo<T>* p){
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
	Nodo<T>* temp=b->m_pRoot;	
	copiar_recursivo(temp);
	return;
}	


template<class T>
void Btree<T>::copiar_recursivo(Nodo<T>*& p){
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
	Nodo<T>* temp1=pNew->m_pRoot;
	Nodo<T>** temp2=NULL;

	queue< Nodo<T>* > cola;
	stack< Nodo<T>* > pila_delete;
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

//-------------------------laborataorio---------------

template<class T>
void Btree<T>::print_infijo_re(Nodo<T>* p){
	if(!p) return;
	print_infijo_re(p->m_pSon[0]);
	cout<<" "<< p->m_Dato;
	print_infijo_re(p->m_pSon[1]);		
}

template<class T>	
void Btree<T>::print_infijo_it(){
	stack< Nodo<T>* > pila;
	Nodo<T>* temp=m_pRoot;
	
	
}






#endif

