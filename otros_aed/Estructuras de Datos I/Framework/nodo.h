#ifndef NODO_H
#define NODO_H
template <class T>
class Nodo
{
protected:
    T * m_Dato;
    int m_Size;
    int m_Grado;
    Nodo<T> * m_pSon;
public:
    //Nodo();
    ~Nodo();
    Nodo(int size,int grado);
    void setDato(T * Dato);
    void setSon(Nodo<T>*pSon,int pos);
    Nodo<T>* getSon(int pos);
    T* getDato();
};

#endif // NODO_H
