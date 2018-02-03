#ifndef NODOPC_H
#define NODOPC_H
template<class T>
class Nodopc
{
typedef Nodopc<T> * pNodo;
private:
    T m_Dato;
    pNodo m_pAnt;
public:
    Nodopc(T D);
    void setmDato(T D);
    T getmDato();
    pNodo getmpAnt();
    void setmpAnt(pNodo sig);
};

#endif // NODO_H
