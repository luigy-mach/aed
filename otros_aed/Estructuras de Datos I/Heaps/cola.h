#ifndef COLA_H
#define COLA_H
#include "nodo.h"
template<class T>
class Cola
{
private:
    Nodo<T> * m_pHead;
    Nodo<T> * m_pLast;
public:
    Cola();
    void Push(T D);
    void Pop(T &D);
    bool isEmpty();
};

#endif // COLA_H
