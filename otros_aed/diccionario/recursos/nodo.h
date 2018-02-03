#ifndef NODO_H_
#define NODO_H_

#include<iostream>

//-----------------------NODO-------------------
template<class T>
class Nodo{
	public:
		virtual ~Nodo()=0;
};

template<class T>
Nodo<T>::~Nodo(){
	std::cout<<"~Nodo()"<<std::endl;
}
//-----------------------------------------------

#endif
