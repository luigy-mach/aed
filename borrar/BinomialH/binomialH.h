#ifndef BINOMIALH_H_INCLUDED
#define BINOMIALH_H_INCLUDED

#include <vector>
#include <iostream>
#include "nodo.h"

#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

template <typename T>
class binomialH
{
private:
    //timmy me explico q... como vector es Template.. y tb Nodo es Template...
    //entonces es necesario colocar typedef y typename
    typedef typename vector< nodo<T> >::iterator ITERATOR;
    ITERATOR it;

public:
    vector<nodo<T> > binomial;
    nodo<T>* mini;
    binomialH();

    //void combinar (nodo<T> * & it);
    void combinar();
    void insertt(T dato);
    void decreaseKey(T valorBH,T d);

    void print();
    void print_dot_pos(nodo<T> *p,const T &d,ostream &os);
    void imprimir_dot();
};

template <class T>
binomialH<T>::binomialH()
{
    mini=0;
 //   binomial[0];
}

template <class T>
//void binomialH<T>::combinar(nodo<T> * & it)
void binomialH<T>::combinar()
{
    if(it==binomial.end()) return;

    if((*it).m_grado==(*(it+1)).m_grado)
    {
        if((*it).m_dato<(*(it+1)).m_dato)
        {
            //jeje no se usar bien el vector<nodo<T>>
            //pero te olvidaste de eliminar el nodo de binomial
            //por ya lo agregaste a sons
            //te recomiendo q en ves q vector uses tu lista simple jeje
            //porq ya tiene implementado el delete q te ayudara mucho aqui
            (*(it+1)).parent=&(*it);
            ((*it).sons).push_back(*(it+1));
            (*it).m_grado++;

        }
        else
        {
            //aqui lo mismo
            (*(it+1)).sons.push_back(*it);
            (*it).parent=&(*(it+1));
            (*(it+1)).m_grado++;
        }

        it++;//nodo<T>* o=&(*(it+1));
        combinar();
        return;
    }

}

template <class T>
void binomialH<T>::insertt(T d)
{
    nodo<T>* nuevo=new nodo<T>(d,NULL);
    if (binomial.empty() ){
        mini=nuevo;}
    else if(mini->m_dato>nuevo->m_dato){
        mini=nuevo;}
    binomial.push_back(*nuevo);
    //if(binomial.size()>1)
    nodo<T>*p=mini;

    //auto it =binomial.begin();
    it=binomial.begin();

    //nodo<T> *p1=&(*it);
    //combinar(p1);
    combinar();
}

template <class T>
void binomialH<T>::decreaseKey(T valorBH,T d)
{


}



/*
template<class T>
void binomialH<T>::print_dot_pos(nodo<T> *p,const T &d,ostream &os)
{
    if(!p)return;
    cout<<p->m_dato<<endl;
    print_dot_pos(p->m_ptr_son[0],p->m_dato,os);
    print_dot_pos(p->m_ptr_son[1],p->m_dato,os);
    if(p==mini){os<<d<<";"<<endl;return;}
    os<<d<<";"<<endl;
    os<<p->m_dato<<";"<<endl;
    os<<d<<"->"<<p->m_dato<<";"<<endl;
}

template<class T>
void binomialH<T>::imprimir_dot()
{
    ofstream Esc("visual.dot");
    Esc<<"digraph A {"<<endl;
    Esc<<" node[fontcolor=white,style=filled,fillcolor=black];"<<endl;
    if(!mini)return;
    nodo<T> *tmp=mini;

    print_dot_pos(tmp,tmp->m_dato,Esc);

   Esc<<"}"<<endl;
   Esc.close();
   system("dot lista.dot -Tpdf -o lista.pdf");
   cout<<endl<<"mostrar dot:"<<endl;

}
*/
#endif // BINOMIALH_H_INCLUDED

