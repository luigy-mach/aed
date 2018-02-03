#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz
{
    public:
    Matriz();
    Matriz( int f,int c);
    ~Matriz();
    void print ();
    //protected:
    private:
    int fila;
    int columna;
    int ** p_fil;
    int * p_col;
};

#endif // MATRIZ_H
