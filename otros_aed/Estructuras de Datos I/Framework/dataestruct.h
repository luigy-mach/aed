#ifndef DATAESTRUCT_H
#define DATAESTRUCT_H
#include "nodo.h"
#include "nodos.h"

template<class T>
class DataEstruct
{
protected:
    Nodo<T> * m_pRoot;
    int m_size;
public:
    DataEstruct();
    virtual void Add (T * D)=0;
    virtual void Remove (T * D)=0;
    virtual bool Find (T * D)=0;
};

#endif // DATAESTRUCT_H
