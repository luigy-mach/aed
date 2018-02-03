#ifndef	ESTRUCTURA_H_
#define ESTRUCTURA_H_

#include<iostream>


//-----------------------ESTRUCTURA-------------------------
template<class T>
class Estructura{
	public:
		virtual void find(T& in,T& out)=0;
		virtual void insertar(const T& d)=0;
        virtual T* minimo()=0;
        virtual T* maximo()=0;
        virtual T* siguiente(T& d)=0;
        virtual T* anterior(T& d)=0;
		//virtual void remove(T d)=0;
		virtual void print_dot()=0;
		virtual ~Estructura()=0;
};

template<class T>
Estructura<T>::~Estructura(){
	std::cout<<"~Estructura()"<<std::endl;
}
//----------------------------------------------------------

#endif
