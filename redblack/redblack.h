#ifndef REDBLACK_H_
#define REDBLACK_H_



template<class T>
class NodoRB{
	public:
		T m_Dato;
		NodoRB<T>* m_pSon[2];
	public:
		NodoRB(T d):m_Dato(d){
			m_pSon[0]=m_pSon[1];
		}
};


template<class T>
class REDBLACK{
	public:
		NodoRB<T>* m_pRoot;
	public:
		REDBLACK(){}
		


};
#endif
