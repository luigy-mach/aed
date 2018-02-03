#ifndef BINOMIAL_H
#define BINOMIAL_H

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

template <typename T>
class Binomial;

template <typename T>
class Nodo{
	
	friend class Binomial<T>;
	T dato;
	vector< Nodo<T>* > hijos;
	Nodo<T>* hermano;
	Nodo<T>* padre;
	int grado;
	Nodo(T _dato):dato(_dato),hermano(NULL),padre(NULL),grado(0){}

};


template <typename T>
class Binomial{
private:
	Nodo<T> *root;
	Nodo<T> *min;
public:
	Binomial():root(NULL),min(NULL){}
	void insert(const T dato);
	void unir(Nodo<T>** p);
	void print();
	void print_dot();
	void print(ofstream & a);
	void print_hijos(Nodo<T>* p, ofstream& );
};

template <typename T>
void Binomial<T>::insert(const T dato)
{
	if(!root) 
	{
		root=new Nodo<T>(dato);
		min=root;
		return;
	}

	Nodo<T> *temp=new Nodo<T>(dato);
	if(temp->dato < root->dato) min=temp;
	temp->hermano=root;
	root=temp;
	Nodo<T>**p=&root;
	unir(p);
}

template <typename T>
void Binomial<T>::unir(Nodo<T>** p)
{
	if(!(*p)->hermano) return;
	if((*p)->grado != (*p)->hermano->grado) return;
	if((*p)->dato > (*p)->hermano->dato)
	{
		Nodo<T>* temp=(*p);
		(*p)=(*p)->hermano;
		temp->padre=(*p);
		temp->hermano=NULL;
		(*p)->hijos.push_back(temp);
		(*p)->grado+=1;
		unir(p);
		return;
	}
	if((*p)->dato < (*p)->hermano->dato)
	{
		Nodo<T>* her=(*p)->hermano->hermano;
		Nodo<T>* temp=(*p)->hermano;
		temp->hermano=NULL;			
		(*p)->hijos.push_back(temp);
		(*p)->grado+=1;
		(*p)->hermano=her;
		unir(p);
		return;		
	}
	unir(&(*p)->hermano);
}

template<class T>
void Binomial<T>::print_hijos(Nodo<T>* p, ofstream& a){
       typedef typename   vector < Nodo<T> * >::iterator   TIterator;  
	TIterator it=p->hijos.begin();
	while(it!=p->hijos.end()){
		a<<" "<<p->dato<<"--"<<(*it)->dato<<";"<<endl;
		it++;
	}
	if(p->hijos.empty()) return;
	
	it=p->hijos.begin();
	while(it!=p->hijos.end()){
		print_hijos(*it,a);
		it++;
	}
		
}


template<class T>
void Binomial<T>::print(ofstream & a){
	stack< Nodo<T>* > pila1;
	Nodo<T>* temp1=root;
	pila1.push(temp1);
	while( !pila1.empty() ){
		temp1=pila1.top();
		pila1.pop();
		print_hijos(temp1,a);
		if(temp1->hermano){
			a<<" "<<temp1->dato<<"--"<<temp1->hermano->dato<<";"<<endl;
			a<<"{rank=same;"<< temp1->dato<<" "<<temp1->hermano->dato<<";}"<<endl;
		}
		temp1=temp1->hermano;
		if(temp1) pila1.push(temp1);
	}	
	cout<<endl;
	

}

template<class T>
void Binomial<T>::print_dot(){
    ofstream flujo_entrada("luigy.dot");
    cout<<"*************************************"<<endl;
	if(!flujo_entrada)
		cout<<"falla en la apertura"<<endl;
	else{
		flujo_entrada<<"graph{"<<endl;		

		this->print(flujo_entrada);
		flujo_entrada<<"}"<<endl;
    }
}


#endif
