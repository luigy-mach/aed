


#include<iostream>
#include<fstream>
using namespace std;
///////////////////////////
#include "lista_doble.h"
#include "record.h"
/////////////////

int main(){

	Estructura< Record* >* f=new ListaD< Record* >();
	Record* t1=new Record();
	Record* t2=new Record();
	Record* t3=new Record();
	Record* t4=new Record();
	
	t1->model="hola1";
	t2->model="hola2";
	t3->model="hola3";
	t4->model="hola4";
	
	f->insertar(t1);	
	f->insertar(t2);	
	f->insertar(t3);	
	f->insertar(t4);	
	f->print_dot();
	/////////////////
	Record* a=new Record();
		a->model="hola4";
	cout<<">>>>"<<a->model<<endl;
	//--------------
	Record* temp=NULL;
	cout<<">>>"<<temp<<endl;
	f->find(a,temp);
	cout<<">>>"<<temp->model<<endl;

	return 0;
}


	/*
	std::string a="b";
	std::string::iterator it=a.begin();
	int value=0;
	while(it!=a.end()){
		value+=*it;
		it++;
	}
	cout<<"->>>"<<value<<endl;
	*/
