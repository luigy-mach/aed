

//#include "estructura.h"
//#include "nodo.h"
#include "avl.h"
#include "record.h"

#include <stdlib.h>
#include <stdio.h>

#include<fstream>
#include<iostream>
using namespace std;
#define DATABASE "database.txt"

fstream database;
std::string buffer;

//--------------------LECTURA-------------------------
int char_to_int(char a){return a-48;}

int length_buffer() {return buffer.length();}

bool open_file(string file){
	database.open(file.c_str(), ios::in | ios::out );
	return	!database.fail()?true:false;
}

void read_file(){std::getline(database,buffer,'@');}

void close_file(){database.close();}

void read_buffer(int& available,string& model,string& description, string& photo ){
	std::string::iterator it=buffer.begin();
	available=char_to_int(*it);
	it++;
	while(*it!='#') {model+=*it;it++;}
	it++;
	while(*it!='#') {description+=*it;it++;}
	it++;
	while(it!=buffer.end()) {photo+=*it;it++;}
}

int read_available(){
	std::string::iterator it=buffer.begin();	
	return char_to_int(*it);
}

string read_model(){
	std::string::iterator it=buffer.begin()+1;
	std::string temp;
	for(;*it!='#';it++)temp+=*it;
	return temp;
}

void indexing(Estructura< Record* >*& f){ //solo indexa available=1;
	int pos=0;//<<<<<<<<<<<------------
	for(int i=0;!database.eof();i++){
		read_file();
		Record* t=new Record();
		t->available=read_available();
		t->model=read_model();
		t->begin=pos+i;
		t->sizeoff=length_buffer();
		t->pos=i;
		pos+=t->sizeoff;
		if(t->available==0) {delete t; continue;}
		f->insertar(t);
		cout<<t->available<<"--"<<t->model<<"--"<<t->begin<<"--"<<t->sizeoff<<endl;
	}
}

//-------------------------------------------------------
void seekg_record(Record& r){
	database.seekg(r.begin, ios::beg);
	cout<<">>>>"<<database.get()<<endl;
}

void seekp_off(Record& r){
	fstream database2("database.txt",ios::out | ios::in );
	database2.seekp(r.begin, ios::beg);
	database2.put('0');
	database2.close();
}


void seekp_on(Record& r){
	fstream database2("database.txt",ios::out | ios::in );
	database2.seekp(r.begin, ios::beg);
	database2.put('1');
	database2.close();
}


//***************************************************************
//***************************************************************
//***************************************************************
//***************************************************************
//***************************************************************

int main(){
	//cualquier estructura;
	Estructura< Record* >* f=new AVL< Record* >();
	//--------------------------------------------
	open_file("database.txt");
		indexing(f);
	f->print_dot();

	close_file();

	return 0;

	
}

