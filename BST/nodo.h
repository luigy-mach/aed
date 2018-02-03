#ifndef NODO
#define LISTA


template<class T>
class Nodo{
 	public:
		T m_Dato;
		Nodo<T>* m_pSig;
	Nodo(T dato):m_Dato(dato),m_pSig(NULL){}
	~Nodo(){}

};

#endif
