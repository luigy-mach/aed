#ifndef NODO_SIMPLE
#define NODO_SIMPLE


template<class T>
class Nodo{
	public:
		T m_Dato;
		Nodo<T>* m_pSig;
	public:
		Nodo(T d):m_pSig(NULL),m_Dato(d){}
		~Nodo(){}
		void matate(){	
			if(m_pSig)
				matate_r(m_pSig);
			muere();
		}
		void muere(){
			delete this;
		}
		void matate_r(Nodo<T>*& p){
			if(!p) return;			
			matate_r(p->m_pSig);
			p->muere();
			
		}		
};


#endif
