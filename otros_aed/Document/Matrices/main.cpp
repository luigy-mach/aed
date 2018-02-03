#include <iostream>
#include "Matriz.h"
using namespace std;

Matriz :: Matriz (int a,int b)
{
    i=a;
    j=b;
    for(int m=0;m<i;m++)
    {
        vprinc[m]=new int[j];
    }
}

void Matriz :: llenar()
{
    for(int a=0 ;a<i;a++)
    {
       for(int z=0;z<j;z++)
       {
           cin>>d;
           vprinc[a][z]=d;
       }
    }

}

void Matriz :: print()
{
    for(int a=0 ;a<i;a++)
    {
       for(int z=0;z<j;z++)
       {
           cout<<vprinc[a][z];
       }
    }

}

void Matriz :: smatriz(int **m)
{
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<j;b++)
        {
            temp[a][b]=vprinc[a][b]+m[a][b];
        }
    }
}

void Matriz :: rmatriz(int **m)
{
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<j;b++)
        {
            temp[a][b]=vprinc[a][b]-m[a][b];
        }
    }
}

void Matriz :: mmatriz(int **m)
{
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<j;b++)
        {
             for(int c=0;c<j;c++)
             {
                temp[a][b]=temp[a][b]+vprinc[a][b]*m[a][c];
             }
        }
    }
}

bool Matriz :: simetrica ()
{
    int s=0;
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<j;b++)
        {
            if ((vprinc[a][b])==(vprinc[b][a]))
               s=s+1;
        }
    }
    if (s==((i*j)-i)) return true;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
