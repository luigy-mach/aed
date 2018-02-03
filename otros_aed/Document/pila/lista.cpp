#include "lista.h"
#include "nodo.h"
#include "objeto.h"

    typedef nodo* pNodo;
    lista::lista()
    {
        m_Head = m_Last =0;
    }
    void lista::push_front(objeto * p)
    {
        pNodo nuevo = new nodo(p);
        if(!m_Head)
        {
              m_Head = m_Last = nuevo;
        }
        else
        {
                nuevo->m_pSig = m_Head;
                m_Head = nuevo;
        }

    }

    void lista::push_back(objeto * p)
    {

           pNodo nuevo = new Nodo(p);
           if(!m_Head)
           {
              m_Head = m_Last = nuevo;
           else
           {
                m_Last->m_pSig = nuevo;
                m_Last = nuevo;
    }

    void lista::print()
    {
        pNodo p = m_Head;
        while(p!=0)
        {
             p->m_Dato->print();
             p=p->m_pSig;
        }

    }

