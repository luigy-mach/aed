#ifndef NODO_DOBLE
#define NODO_DOBLE


template<class T>
class NodoD{
	public:
		T m_Dato;
		NodoD<T>* m_pSig;
		NodoD<T>* m_pAnt;
	public:
		NodoD(T d):m_pSig(NULL),m_pAnt(NULL),m_Dato(d){}
		~NodoD(){}
};


#endif
