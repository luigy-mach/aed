#include "Matriz.h"

Matriz::Matriz()
{
    fila=10;
    columna=10;
    p_fil=new int [fila];
    for(int i=0;i<fila;i++)
    p_fil[i]=new int [columna];
    //ctor
}

Matriz::Matriz(int m[int & f][int & c])
{
    fila=f;
    columna=c;
    p_fil=new int [fila];
    p_col=new int [columna];
    m[p_fil][p_col];
    //ctor
}

Matriz::~Matriz()
{
    delete p_fil;
    delete p_col;
    //dtor
}

void Matriz::print
{
    for(int i=0;i<columna:i++)
    {
        for(int j=0;j<fila;j++)
        {
            cout<<m[][]
        }
    }
}
