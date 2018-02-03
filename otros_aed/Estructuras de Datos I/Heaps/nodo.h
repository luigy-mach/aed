#ifndef NODO_H
#define NODO_H
template<class T>
class Nodo
{
typedef Nodo<T> * pNodo;
private:
    T m_Dato;
    pNodo m_pAnt;
public:
    Nodo(T D);
    void setmDato(T D);
    T getmDato();
    pNodo getmpAnt();
    void setmpAnt(pNodo sig);
};

#endif // NODO_H
