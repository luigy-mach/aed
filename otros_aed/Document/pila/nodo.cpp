#include "nodo.h"
#include "objeto.h"
#include "lista.h"


    nodo::nodo(objeto * p)
    {
        m_Dato = p->clone();
        m_pSig=0;/
    }

    nodo::~nodo()
    {
        //dtor
    }


