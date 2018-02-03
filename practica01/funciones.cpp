#include "lista_simple.h"
#include "lista_circular_simple.h"
#include "lista_doble.h"

#include<stdlib.h>
#include<time.h> 
#include<cmath>
#include<iostream>
#include<stack>
using namespace std;





//EJERCICIO_01

template<class T>
int sumar_elementos(Lista<T>* a){
	Nodo<T>* temp=a->m_pHead;
	int n=0;
	while(temp){
		n+=temp->m_Dato;
		temp=temp->m_pSig;	
	}
	return n;
}


template<class T>
Lista<T>* encontrar_sumandos(Lista<T>& mylista,T num){
	//esta ordenanada?
		//sino ordenar!
	Nodo<T>*  temp1=mylista.m_pHead;
	Nodo<T>** temp2=NULL;
	Lista<T>* tt=new Lista<T>();
	
	int buffer=num;
	while(temp1){
		if((temp1->m_Dato)<=buffer){
			buffer-=temp1->m_Dato;
			tt->push_back(temp1->m_Dato);
			if(mylista.find(buffer,temp2)){
				tt->push_back((*temp2)->m_Dato);
				break;
			}
		}
		temp1=temp1->m_pSig;
	}
	int suma=sumar_elementos(tt);
	if(suma==num){
		return tt;
	}
	else{
		tt->destruyete();
		tt=NULL;
		return tt;
	}
}



//EJERCICIO_03


int my_foo(int a){
	return	a=a*2;
}

Lista<int>& funcion_map(int (*pf)(int),Lista<int>& a){
	Lista<int>* result=new Lista<int>();
	Nodo<int>* temp=a.m_pHead;
	while(temp){
		result->add(pf(temp->m_Dato));
		temp=temp->m_pSig;
	}
	return *result;
}




//EJERCICIO_07 

template<class T>
void dividir(Lista<T>& principal,Lista<T>& a,Lista<T>& b){
	if(!a.estaVacia() && !b.estaVacia()) return;
	Nodo<T>* temp=principal.m_pHead;
	int tamano=principal.tamano();
	int count=0;
	while(temp){
		if(count<=tamano/2)
			a.add(temp->m_Dato);
		else
			b.add(temp->m_Dato);
		count++;
		temp=temp->m_pSig;
	}
	return;
}

//EJERCICIOS_09	

Lista<int>& mezclar_listas(Lista<int>& a,Lista<int>& b){
	Lista<int>* mezcla=new Lista<int>();
	Nodo<int>* temp1=a.m_pHead;
	Nodo<int>* temp2=b.m_pHead;
	while(temp1||temp2){
		if(temp1){
			mezcla->push_back(temp1->m_Dato);
			temp1=temp1->m_pSig;
		}
		if(temp2){
			mezcla->push_back(temp2->m_Dato);
			temp2=temp2->m_pSig;
		}
	}
	return *mezcla;	
}


//EJERCICIO_13 ---- uso //04
template<class T>
T juego(Lista<T> a ,int m){
	Nodo<T>* temp=a.m_pHead;
	ListaCS< Nodo<T>* > lcs;

	while(temp){
		lcs.add(temp);
		temp=temp->m_pSig;	
	}
	Nodo< Nodo<T>* >* tt;
	int tamano=lcs.tamano();
	while(tamano>1){
		tt=lcs.n_esimo(m);			
		lcs.remove(tt->m_Dato);		
		tamano--;
	}	
		
	return lcs.m_pHead->m_Dato->m_Dato;
}










