#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H
#include "binomial.h"
#include "garbage.h"
#include <map>
#include "persona.h"
#include "nodoB.h"
template<class T>
class garbagecollector
{
    public:
        binomial<garbage*>* bin;
        map<long int,nodoB<garbage*>*> myMapa;
    public:
        garbagecollector();
        T* New(int tam);
        void desasignar(T* & a);
        void asignar(T* & a,T* & b);

};

template<class T>
garbagecollector<T>::garbagecollector()
{
    bin=binomial<garbage*>::Init();
}
template<class T>
T* garbagecollector<T>::New(int tam)
{
    void * a = (void *)new char[tam];
    garbage * nuevo =new  garbage();
    nuevo->setMenDir((long int)a);
    nuevo->setCount(1);
    nodoB<garbage*>* b=new nodoB<garbage*>(nuevo);
    myMapa.insert(pair<long int,nodoB<garbage*>*>((long int)a,b));
    bin=bin->BINOMIAL_HEAP_INSERT(bin,b);
    bin->BINOMIAL_HEAP_DECREASE_KEY(bin,b,nuevo);
    return (T*)a;
}
template<class T>
void garbagecollector<T>::desasignar(T* & a)
{
    nodoB<garbage*>* b=myMapa[(long int)(a)];
    (b->getKey())->decrementar();
}
template<class T>
void garbagecollector<T>::asignar(T* & a,T* & b)
{
    b=a;
    nodoB<garbage*> * rs =myMapa[(long int)(a)];
    (rs->getKey())->incrementar();
    //bin->BINOMIAL_HEAP_DECREASE_KEY(bin,b,nuevo);
}


#endif // GARBAGECOLLECTOR_H
