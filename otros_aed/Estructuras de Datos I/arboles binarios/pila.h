#ifndef PILA_H
#define PILA_H
#include "nodopc.h"

template<class T>
class Pila
{
private:
    Nodopc<T> * m_tope;
public:
    Pila();
    void Push(T D);
    void Pop(T &D);
    bool isEmpty();
};

#endif // PILA_H
