#include <QtCore/QCoreApplication>
#include <iostream>
using namespace std;
#include "pila.cpp"
#include "nodo.cpp"
#include "cola.cpp"
#include "heaps.cpp"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"corre"<<endl;
    Pila<int> p;
    p.Push(5);
    p.Push(8);
    p.Push(10);
    int c;
    p.Pop(c);
    cout<<c<<endl;
    p.Pop(c);
    cout<<c<<endl;
    p.Pop(c);
    cout<<c<<endl;

    Cola<int> co;
    co.Push(5);
    co.Push(8);
    co.Push(10);
    int d;
    co.Pop(d);
    cout<<d<<endl;
    co.Pop(d);
    cout<<d<<endl;
    co.Pop(d);
    cout<<d<<endl;
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
    //return a.exec();
}
