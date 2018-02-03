#ifndef NODO_H
#define NODO_H

template<class T>
class btree;
template<class T>
class nodo
{
    friend class btree<T>;
    private:
    T m_Dato;
    nodo<T>* m_pSon[2];
    int fe;
    public:
    nodo(T d);
    void matate();
    virtual ~nodo();
};

#endif // NODO_H
