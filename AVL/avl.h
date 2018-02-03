#ifndef AVL_H_
#define AVL_H_


//#define der 1
//#define izq 0
//#define NULL 0
const static int der=1;
const static int izq=0;

#include<iostream>
#include<stack>

using namespace std;


//-----------------------------NODO---------------------------	
template<class T>
class Node{
	public:
		T m_Dato;	
		int m_FE;
		Node<T>* m_pSon[2];
	public:
		Node(T d):m_Dato(d),m_FE(0){
			m_pSon[0]=m_pSon[1]=NULL;
		}
};
//-------------------------------AVL-----------------------	
template<class T>
class AVL{
	public:
		Node<T>* m_pRoot;
	public:
		AVL():m_pRoot(NULL){}
		void insertar(T d);
		void insertar_rec(T d, Node<T>*&p, bool*& stop);
		void RS(bool doi, Node<T>*& p);
		void RD(bool doi, Node<T>*& p);

		void print();
};
//---------------------------------------------------------	
//---------------------------------------------------------	
template<class T>
void AVL<T>::insertar(T d){
	bool* stop=new bool(false);
	insertar_rec(d,m_pRoot,stop);
}

template<class T>
void AVL<T>::insertar_rec(T d, Node<T>*&p, bool*& stop){
	if(!p){p=new Node<T>(d);return;}
	if(p->m_Dato==d) return;
	insertar_rec(d,p->m_pSon[p->m_Dato<d],stop);
	if(*stop) return;
	p->m_FE+=(p->m_Dato<d)?1:-1;
	switch(p->m_FE){
		case  0: return;
		case  2:(p->m_pSon[1]->m_FE>0)?RS(der,p):RD(der,p);
			*stop=true;
			return;
		case -2:(p->m_pSon[0]->m_FE<0)?RS(izq,p):RD(izq,p);			      *stop=true;
			return;
	}
}

template<class T>
void AVL<T>::RS(bool doi, Node<T>*&p){
	Node<T>*q=p->m_pSon[doi];
	p->m_pSon[doi]=q->m_pSon[!doi];
	q->m_pSon[!doi]=p;
	p->m_FE=q->m_FE=0;
	p=q;
	return;
}

template<class T>
void AVL<T>::RD(bool doi, Node<T>*& p){
	Node<T>* q=p->m_pSon[doi];
	Node<T>* r=q->m_pSon[!doi];
	p->m_pSon[doi]=r->m_pSon[!doi];
	q->m_pSon[!doi]=r->m_pSon[doi];
	r->m_pSon[doi]=q;
	r->m_pSon[!doi]=p;

	if(r->m_FE==0){
		 p->m_FE=q->m_FE=r->m_FE;
		return;
	}
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
		return;
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
		return;
	}
}

template<class T>
void AVL<T>::print(){
	stack< Node<T>* > pila;
	Node<T>* temp=m_pRoot;
	pila.push(temp);
	while( !pila.empty() ){
		temp=pila.top();
		pila.pop();
		if(temp->m_pSon[0]) pila.push(temp->m_pSon[0]);
		if(temp->m_pSon[1]) pila.push(temp->m_pSon[1]);
		cout<<" "<<temp->m_Dato;
			
	}
	cout<<endl;
}

//---------------------------------------------------------	
#endif 
