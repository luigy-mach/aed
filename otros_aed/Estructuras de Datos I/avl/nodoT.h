#include <iostream>


template<class T>
class BTree;

template <class T>
class Nodo
{
    friend class BTree<T>;
private:
	T m_Dato;
	Nodo<T> * m_Son[2];
        Nodo<T> * m_Parent;
        int fe;
        bool visit;
public:
    Nodo(){}
    Nodo(T d)
    {
        visit=true;
        m_Dato=d;
        m_Son[0]=m_Son[1]=0;
        fe=0;
        m_Parent=0;
    }
    T getdato()
    {
        return m_Dato;
    }
    Nodo<T>* getson0()
    {
        return m_Son[0];
    }
    Nodo<T>* getson1()
    {
        return m_Son[1];
    }
    Nodo<T>* getParent()
    {
        return m_Parent;
    }
    int getfe(){return fe;}

};
