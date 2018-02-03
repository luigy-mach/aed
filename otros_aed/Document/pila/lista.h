#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
#include "objeto.h"

class lista:public objeto
{
    typedef nodo * pNodo;
    public:
        lista();
        virtual ~lista();
        void push_front(objeto * p);
        void push_back(objeto * p);
        void print();
    //protected:
    private:
       pNodo m_Head;
       pNodo m_Last;
};

#endif // LISTA_H
