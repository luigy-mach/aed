#ifndef COLA_H
#define COLA_H
#include "nodopc.h"
template<class T>
class Cola
{
private:
    Nodopc<T> * m_pHead;
    Nodopc<T> * m_pLast;
public:
    Cola();
    void Push(T D);
    void Pop(T &D);
    bool isEmpty();
};

#endif // COLA_H
