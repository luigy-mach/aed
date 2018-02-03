#ifndef HEAPS_H
#define HEAPS_H
#include "nodo.h"
#include <iostream>
using namespace std;
template<class T>
class Heaps
{
public:
    Heaps();
    int Hijo_Izq(int i);
    int Hijo_Der(int i);
    void swap(T *a,int i,int j);
    void Make_Heap(T *v,int t);
    void Heap_fi(T *v,int t);
    void print(T *v,int t);
    void Heap_Sort(T *v,int t);
};

#endif // HEAPS_H
