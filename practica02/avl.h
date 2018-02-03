
#ifndef AVL_H_
#define AVL_H_

//#define der 1
//#define izq 0
//#define NULL 0
const static int der=1;
const static int izq=0;

#include<iostream>
#include<stack>
#include <fstream>

using namespace std;


//-----------------------------NODO---------------------------	
template<class T>
class NodoAvl {
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
class AVL {
	public:
		NodoAvl<T>* m_pRoot;
	public:
		AVL():m_pRoot(NULL){}
		~AVL(){cout<<"~AVL()"<<endl;}
		//-------------------
		void find(T& in, T& out);
		//-------------------
		bool find(const T& d,NodoAvl<T>**& pp);
		void RS(bool doi, NodoAvl<T>*& p);
		void RD(bool doi, NodoAvl<T>*& p);
	//------------------EJERCICIOS
		//07
			// (a)
		void maximo();
		void maximo_rec(NodoAvl<T>*& p,NodoAvl<T>*& out);
			// (b)
		int get_nivel(const T& d);
		void get_nivel_rec(T d,NodoAvl<T>*& p,int& a);
			// (c)
		void insertar(const T& d);
		void insertar_rec(const T& d, NodoAvl<T>*&p,bool *stop);		
			// (d)
		bool buscar(const T& d);
		void buscar_rec(NodoAvl<T>** p,T d,NodoAvl<T>**& out);
		
		//10
	
		void recorrer_arbol(NodoAvl<T>* p,stack< NodoAvl<T>* >& pila);
		AVL<T>* unir_con(AVL<T>& b);
		//11
		void print(ofstream & a);
		void print_dot();
		
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
		if((*pp)->m_Dato==d) return true;
		pp=&(*pp)->m_pSon[(*pp)->m_Dato<d];
	}
	return false;
	
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


//********************EJERCICIOS***********************
//_____________________________________________________


// 07	
	// (a)
template<class T>
void AVL<T>::maximo(){
	NodoAvl<T>* temp1=m_pRoot;
	NodoAvl<T>* temp2=NULL;
	maximo_rec(temp1,temp2);
	cout<<" "<<temp2->m_Dato<<endl;
}

template<class T>
void AVL<T>::maximo_rec(NodoAvl<T>*& p,NodoAvl<T>*& out){
	if(!p)	return;
	maximo_rec(p->m_pSon[1],out);
	if(!p->m_pSon[1])
		out=p;
}

	// (b)
template<class T>
int AVL<T>::get_nivel(const T& d){
	int nivel=-1;
	NodoAvl<T>* temp=m_pRoot;
	get_nivel_rec(d,temp,nivel);
	return nivel;
}

template<class T>
void AVL<T>::get_nivel_rec(T d,NodoAvl<T>*& p,int& a){
	if(!p) return;
	if(p->m_Dato==d) return;
	a++;
	get_nivel_rec(d,p->m_pSon[p->m_Dato<d],a);
}
	// (c) 
template<class T>
void AVL<T>::insertar(const T& d){
	bool *stop=new bool(false);
	insertar_rec(d,m_pRoot,stop);
	delete stop;
}

template<class T>
void AVL<T>::insertar_rec(const T& d, NodoAvl<T>*&p,bool *stop){
	if(!p){p=new NodoAvl<T>(d);return;}
	if(p->m_Dato==d) return;
	insertar_rec(d,p->m_pSon[p->m_Dato<d],stop);
	if(*stop) return;
	p->m_FE+=((p->m_Dato)<d)?1:-1;
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
	// (d)
template<class T>
bool AVL<T>::buscar(const T& d){
	NodoAvl<T>** temp=&m_pRoot;
	NodoAvl<T>** out=NULL;
	buscar_rec(temp,d,out);
	return (*out)->m_Dato==d?true:false;
}

template<class T>
void AVL<T>::buscar_rec(NodoAvl<T>** p,T d,NodoAvl<T>**& out){
	if(!(*p)) return;
	if((*p)->m_Dato==d){
		out=p;
		return;
	}
	buscar_rec(&(*p)->m_pSon[(*p)->m_Dato<d],d,out);
}


//10
template<class T>
void AVL<T>::recorrer_arbol(NodoAvl<T>* p,stack< NodoAvl<T>* >& pila){
	if(!p) return;
	recorrer_arbol(p->m_pSon[0],pila);
	recorrer_arbol(p->m_pSon[1],pila);
	pila.push(p);
	
	
}

template<class T>
AVL<T>* AVL<T>::unir_con(AVL<T>& b){
	NodoAvl<T>* temp1=this->m_pRoot;
	NodoAvl<T>* temp2=b.m_pRoot;

	AVL<T>* n=new AVL<T>();
	stack< NodoAvl<T>* > pila;

	recorrer_arbol(temp1,pila);
	recorrer_arbol(temp2,pila);
	while(!pila.empty()){
		n->insertar(pila.top()->m_Dato);
		pila.pop();
	}
	return n;
}


// 11
template<class T>
void AVL<T>::print(ofstream & a){
	stack< NodoAvl<T>* > pila;
	NodoAvl<T>* temp=m_pRoot;
	pila.push(temp);
	while( !pila.empty() ){
		temp=pila.top();
		pila.pop();
		if(temp->m_pSon[0])
			a<<" "<<temp->m_Dato<<" -> "<<temp->m_pSon[0]->m_Dato<<";"<<endl;
		if(temp->m_pSon[1])
		a<<" "<<temp->m_Dato<<" -> "<<temp->m_pSon[1]->m_Dato<<";"<<endl;
		if(temp->m_pSon[1]) pila.push(temp->m_pSon[1]);
		if(temp->m_pSon[0]) pila.push(temp->m_pSon[0]);
		
		
	}
	cout<<endl;
}

template<class T>
void AVL<T>::print_dot(){
	ofstream flujo_entrada("luigy.dot");
	if(!flujo_entrada)
		cout<<"falla en la apertura"<<endl;
	else{
		flujo_entrada<<"digraph{"<<endl;		
		this->print(flujo_entrada);
		flujo_entrada<<"}"<<endl;

	}

}




#endif 


