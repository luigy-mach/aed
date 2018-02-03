#ifndef LISTAS_H
#define LISTAS_H
#include "lista.h"
template<class T>
class Listas:public Lista<T>
{
public:
    Listas():Lista<T>(){};
    T* getMax();
    T* getMin();
    void Sort();
    void Reverse();
    void Clear();
};

#endif // LISTAS_H
