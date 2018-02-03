#ifndef BTREE_H
#define BTREE_H

#include "nodo.h"
template<class T>
class btree
{
    private:
    nodo<T> * m_pRoot;
    public:
    btree();
    ~btree();
    bool find(T d,nodo<T>**&p);
    bool add(T d);
    bool remove(T d);
    void rp();
    void ra();
    bool deletetwoson(T d);
    bool deleteoneson(T d);
    bool deletehoja(T d);
    void rii(nodo<T>*&p);
    void rdd(nodo<T>*&p);
    void rdi(nodo<T>*&p);
    nodo<T> * getroot();
};

#endif // BTREE_H
