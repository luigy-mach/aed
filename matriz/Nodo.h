#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <ostream>

using namespace std;

template<class T>
class Nodo
{
	public:
		T m_dato;
		Nodo<T> *mp_next[2];
		Nodo(const T &d):m_dato(d)
		{
		  mp_next[0]=mp_next[1]=0;
		}

		void matate()
		{
			//if(mp_next[0]) mp_next[0]->matate();
			if(mp_next[1]) mp_next[1]->matate();
		}
		
};
#endif // NODO_H