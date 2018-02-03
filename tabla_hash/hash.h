#ifndef TABLA_HASH
#define TABLA_HASH

#include <list>
#include <string>
using namespace std;


template<typename O,typename K, int(*fd)(void*,int),int tam=99>
class Hash{
	private:
		list<O>* m_pTabla;
	public:
		Hash(){
			m_pTabla=new list<O>[tam];
		}
		void insertar(O obj,K key);
		bool remove(O obj,K key);
		bool find(O obj,K key);
		int fun_dis(void* _k,int _tam);
};


template<typename O,typename K, int(*fd)(void*,int),int tam>
void Hash<O,K,fd,tam>::insertar(O obj, K key){

	m_pTabla[fd(&key,tam)].push_back(obj);
}

template<typename O,typename K, int(*fd)(void*,int),int tam>
bool Hash<O,K,fd,tam>::remove(O obj, K key)
{
	m_pTabla[fd(&key,tam)].remove(obj);
}

template<typename O,typename K, int(*fd)(void*,int),int tam>
bool Hash<O,K,fd,tam>::find(O obj,K key)
{
        list<O>& L = m_pTabla[fd(&key,tam)];
	return L.find(L.begin(),L.end(),obj)!=L.end();
        
	
}


template<typename O,typename K, int(*fd)(void*,int),int tam>
int Hash<O,K,fd,tam>::fun_dis(void* _k,int _tam)
{
	int s=0;int i=0;
	string p=(*(string*)_k);
	while(i<_tam){
		s+=p[i];
		i++;
	}
	return s%tam;
}







#endif
