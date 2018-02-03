#ifndef LISTA_H
#define LISTA_H
#include "dataestruct.h"
template<class T>
class Lista:public DataEstruct<T>
{
protected:
    Nodo<T> * m_pLast;
public:
    Lista():DataEstruct<T>(){this->m_pLast=0;}
    void Add(T *D);
    void Remove(T *D);
    bool Find(T *D);

};

#endif // LISTA_H
