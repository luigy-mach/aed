#include<iostream>
#include "lista_simple.h"
#include "lista_circular_simple.h"
#include "funciones.cpp"
#include "lista_doble.h"

using namespace std;




int main(){
		
//ejercicio_01 ---- funciones.cpp
	/*Lista<int> mylist;
	mylist>>1>>2>>3>>4>>5>>6>>7;
	mylist.print();	
	Lista<int>* resultado=encontrar_sumandos(mylist,10);
	if(resultado)
		resultado->print();
	else
		cout<<"resultado = NULL"<<endl;*/
	

//ejercicio_02------ lista_simple.h
	/*Lista<int> lista_1, lista_2, uni;
	uni>>1>>2>>3>>4>>5>>6>>7>>8>>9>>11>>13>>16;
	lista_1.agregarUniverso(&uni);
	lista_2.agregarUniverso(&uni);
	lista_1>>3>>5>>6>>8>>13;
	lista_2>>3>>5;
	Lista<int>* temp=&(lista_1.interseccion(lista_2));
	temp->print();
	temp->agregarUniverso(&uni);
	Lista<int>* temp2=&((*temp).complemento());
	temp2->print();*/
	
//ejercicio_03 ---------- funciones.cpp
	/*Lista<int> my_lista;
	my_lista>>1>>2>>3>>4>>5>>6;
	Lista<int>* temp=&(funcion_map(my_foo,my_lista));
	temp->print();*/

//ejercicio_04 ------- lista_circular_simple.h
	/*ListaCS<int> my_listacs;
	my_listacs>>1>>2>>3>>4>>5>>6>>7>>8>>9;
	my_listacs.print();
	my_listacs.remove(5);
	my_listacs.print();
	cout<<"--"<<my_listacs.nesimo(5)->m_Dato<<endl;*/

	
//ejercicio_05 ------- lista_simple.h
	/*Lista<int> a;
	a.add(5);
	a.inserta_ordenado(2);
	a.inserta_ordenado(8);
	a.inserta_ordenado(0);
	a.print();*/


//ejercicio_06 ---------- lista_simple.h
	/*Lista<int> c;
	c.push_front(10);
	c.push_front(1);
	c.push_front(8);
	c.push_front(20);
	c.push_front(15);
	c.print();
	c.ordenar();
	c.print();*/

//ejercicio_07 --------- funciones.cpp

	/*Lista<int> principal;
	principal>>1>>2>>3>>4>>5>>6>>7>>8>>9>>10;
	principal.print();
	Lista<int>*a=new Lista<int>();
	Lista<int>*b=new Lista<int>();
	dividir(principal,*a,*b);
	a->print();
	b->print();*/

//ejercicio_08 ------------ lista_simple_h
	/*Lista<int> m,n;
	m>>1>>2>>3>>4>>5>>6;
	n>>7>>8>>9;
	m.print();
	n.print();
	m.anadir_cab_de(n);
	m.print();
	n.print();*/

//ejercicio_09 ----- funciones.cpp
	/*Lista<int> a,b;
	a>>1>>2>>3>>4>>5>>6>>7>>8;
	b>>9>>10>>11>>12>>13>>14>>15;
	Lista<int>* mezcla=&( mezclar_listas(a,b) );
	mezcla->print();*/


//ejercicio_11 --------- lista_simple.h
	/*Lista<int>x;
	x>>1>>2>>3>>4>>5>>6>>7>>8;
	x.reverse_ite();
	x.print();*/

//ejercicio_12 --------lista_simple.h
	/*Lista<int>a;
	a>>1>>2>>3>>4>>5>>6>>7>>8>>9;
	a.print();
	a.reverse_recur();	
	a.print();*/

//ejercicio_13 ------- funciones.cpp
	/*Lista<int> my_lista;
	my_lista>>1>>2>>3>>4>>5>>6;
	my_lista.print();
	cout<<juego(my_lista,3)<<endl;*/

//ejercicio_14 ------ lista_doble.h
	/*ListaD<int> dd;
	dd.insertar_rec(1);
	dd.insertar_rec(12);
	dd.insertar_rec(13);
	dd.insertar_rec(14);
	dd.insertar_rec(165);
	dd.insertar_rec(645);
	dd.print();*/

//ejercicio_15 -------- lista_doble.h
	/*ListaD<int> dd;
	dd.insertar_rec(1);
	dd.insertar_rec(2);
	dd.insertar_rec(3);
	dd.insertar_rec(4);
	dd.insertar_rec(5);
	dd.insertar_rec(6);
	dd.print();
	ListaD<int>* suma=dd.encontrar_suma(4);	
	suma->print();*/


	return 0;
}
