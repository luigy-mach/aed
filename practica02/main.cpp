#include<stdlib.h>
#include<iostream>
using namespace std;


#include"bst.h"
#include "avl.h"

int main(){
    
    //EJERCICIO_01  <<<-------bst.h
	/*Btree<int> a;
	a>>30>>10>>19>>35>>40>>33;
	a.print_creciente();*/

    //EJERCICIO_02  <<<--------bst.h
	/*Btree<int> a;
	a>>10>>7>>8>>9>>15>>12>>20;
	a.print_BFS_inv();*/

	/*AVL<int> my;
	for(int i=0;i<=30;i++)
		my.insertar(i);
	// (a)		
		my.maximo();
	// (b)
		cout<<my.get_nivel(10)<<endl;
	// (c)
		my.insertar(120); //<<...es recursivo
	// (d)
		my.buscar(5)?cout<<"si existe"<<endl:cout<<"no existe"<<endl;    */

    //EJERCICIO_10
	/*AVL<int> a,b;
	for(int i=0;i<=8;i++)	a.insertar(i);
	for(int i=40;i<=45;i++)	b.insertar(i);
	AVL<int>* c=a.unir_con(b);
	c->print_dot();
	system("dot -Tpdf luigy.dot -o a.pdf");
	system("evince a.pdf");*/
	

    //EJERCICIO_11 print_dot
	/*AVL<int> zz;
	for(int i=0;i<=30;i++)
		zz.insertar(i);
	zz.print_dot();
	system("dot -Tpdf luigy.dot -o a.pdf");
	system("evince a.pdf");   */

    return 0;
}
