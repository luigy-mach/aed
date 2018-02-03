#include <iostream>
using namespace std;

template<class T>
class Nodo
{
typedef Nodo<T> * pNodo;
private:
    T m_Dato;
    pNodo m_pAnt;
public:
    Nodo(T D);
    void setmDato(T D);
    T getmDato();
    pNodo getmpAnt();
    void setmpAnt(pNodo sig);
};

template<class T>
Nodo<T>::Nodo(T D)
{
    m_Dato=D;
    m_pAnt=0;
}

template<class T>
void Nodo<T>::setmDato(T D)
{
    m_Dato =D;
}

template<class T>
T Nodo<T>::getmDato()
{
    return m_Dato;
}

template<class T>
Nodo<T>* Nodo<T>::getmpAnt()
{
    return m_pAnt;
}

template<class T>
void Nodo<T>::setmpAnt(pNodo sig)
{
    m_pAnt=sig;
}

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
    int m=0;
    if(a[Hijo_Izq(i)]>a[Hijo_Der(i)])
        m=a[Hijo_Izq(i)];
    else
    {
        m=a[Hijo_Der(i)];
    }
    if(a[i]>a[m])
	{
        this->swap(a,i,m);
    	Heap_fi(a,m);
	}
	else
    {
        return;
    }
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
int main()
{
	cout<<"heaps"<<endl;
    Heaps<int> h;
    int * v=new int[6];
    v[0]=7;
    v[1]=5;
    v[2]=8;
    v[3]=10;
    v[4]=1;
    v[5]=4;

    for(int i=0;i<6;i++)
        cout<<v[i]<<endl;
    cout<<"vector lleno"<<endl;
    h.Heap_Sort(v,6);
    return 1;
}
