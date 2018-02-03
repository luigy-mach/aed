#ifndef NODO_H
#define NODO_H
#include "objeto.h"
#include "lista.h"

class nodo:public objeto
{
    friend class Lista;
    public:
        nodo(objeto * p);
        virtual ~nodo();
    protected:
    private:
        objeto * m_Dato;
        nodo   * m_pSig;
};

#endif // NODO_H
