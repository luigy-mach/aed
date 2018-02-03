#include "heaps.h"

template<class T>
Heaps<T>::Heaps()
{
}
template<class T>
int Heaps<T>::Hijo_Izq(int i)
{
    int r;
    r=((i+1)*2);
    return r;
}

template<class T>
int Heaps<T>::Hijo_Der(int i)
{
    int r;
    r=((i*2)+1);
    return r;
}
template<class T>
void Heaps<T>::swap(T *a,int i,int j)
{
    T d=a[i];
    a[i]=a[j];
    a[j]=d;
}

template<class T>
void Heaps<T>::Heap_fi(T *a,int i)
{
    int m;
    if(a[Hijo_Izq(i)]>a[Hijo_Der(i)])
        m=a[Hijo_Izq(i)];
    m=a[Hijo_Der(i)];
    if(a[i]>a[m])
        this->swap(a,i,m);
    if(a[i]<a[m])
        return;
    Heap_fi(a,m);
}

template<class T>
void Heaps<T>::Make_Heap(T *v,int t)
{
    for(int i=(t/2);i>0;i--)
    {
        Heap_fi(v,i);
    }

}

template<class T>
void Heaps<T>::Heap_Sort(T *v,int t)
{
    Make_Heap(v,t);
    int m=t;
    for(int i=0;i<m;i++)
    {
        swap(v,i,m);
        m--;
        Heap_fi(v,i);
    }
    for(int j=0;j<t;j++)
        cout<<v[j]<<endl;
}

template<class T>
void Heaps<T>::print(T *v,int t)
{

}
