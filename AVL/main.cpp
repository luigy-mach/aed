#include"avl.h"

#include<iostream>
using namespace std;

int main(){
	
	AVL<int> a;
	a.insertar(10);
	a.insertar(36);
	a.insertar(15);
	a.insertar(1);
	a.insertar(3);
	a.insertar(50);
	a.print();
	return 0;
}
