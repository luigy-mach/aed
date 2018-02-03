#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

template<class T>
class ListaSimple
{
	private:
		Nodo<T> *mp_head;
		Nodo<T> *mp_last;
    public:
    	ListaSimple():mp_head(0),mp_last(0),m_size(0){} 
    	virtual ~ListaSimple();
        void Mypushfront(const T &d);
        void Mypushback(const T &d);
        bool Myfind(const T &d);
        bool Myadd(const T &d);
        void Mypopfront();
        void Mypopback();
        bool Myremove(const T &d);
 		void Myreverse();   
 		void Myreverse_rec();   
        ListaSimple<T> dividir();
        void reordenar();
 		ListaSimple<T> Myunion(const ListaSimple<T> &L2);
 		ListaSimple<T> Myinterseccion(ListaSimple<T> L2);
        void complemento(ListaSimple<T> L1, ListaSimple<T> List1);

        void Myprint_reverse();
        void Myprint();
        void clear(Nodo<T> *tmp);
        size_t Mysize();
        T& operator [](size_t pos);
        T& nelem_pos(size_t i,size_t n);//En una lista circular, encontrar el n-esimo elemento a partir de una posicion inicial dada, recorriendo la lista como maximo una vez.
        ListaSimple<T>& ejercicio8(ListaSimple<T> &L1,ListaSimple<T> &L2);
        ListaSimple<T> mezclar(ListaSimple<T> &L1,ListaSimple<T> &L2);
        void Mypush(size_t pos,const T &d);
        ListaSimple<T> Mymap(ListaSimple<T> &L1,T (*f) (const T &d));
        ListaSimple<T>& operator >>(const T &d);
        ListaSimple<T>& operator=(const ListaSimple<T> &L);
        ListaSimple<T> operator+(const ListaSimple<T> &L2);
        ListaSimple<T> operator-(ListaSimple<T> L2);
    protected:
     	size_t m_size;	
     	bool Myfind(const T &d,Nodo<T> **&p);	
     	void Myprint_reverse(Nodo<T> *tmp);	
     	void Myreverse_rec(Nodo<T> *&r,Nodo<T> *ant);
};

/*************************FUNCIONES*******************************/
template<class T>
ListaSimple<T>::~ListaSimple()
{
    if(mp_head) mp_head->matate();
}

template<class T>
T& ListaSimple<T>:: operator[](size_t pos)
{
     try
   {
      if(!mp_head)
         throw 1;
      else
      {
         Nodo<T> *temp=mp_head;
         size_t cont=0;
         while(cont<pos)
         {
            temp=temp->mp_next[1];
            ++cont;
         }
         return temp->m_dato;
      }
   }
   catch (int e)
   {
      cout<<"Lista Vacia"<<endl;
   }
}

template<class T>
T& ListaSimple<T>::nelem_pos(size_t i,size_t n)
{
     try
   {
      if(!mp_head)
         throw 1;
      else
      {
         size_t pos=i+n;
         Nodo<T> *temp=mp_head;
         size_t cont=0;
         while(cont<pos)
         {
            temp=temp->mp_next[1];
            ++cont;
         }
         return temp->m_dato;
      }
   }
   catch (int e)
   {
      cout<<"Lista Vacia"<<endl;
   }
}

template<class T>
ListaSimple<T> ListaSimple<T>::Mymap(ListaSimple<T> &L1, T (*fun)(const T &d))
{
    ListaSimple<T> Ldestino;
    Nodo<T> *tmp=L1.mp_head;
     while(tmp)
      {
       Ldestino.Mypushback( fun(tmp->m_dato) );
        tmp=tmp->mp_next[1]; 
      } 
      return Ldestino;
}

template<class T>
ListaSimple<T>& ListaSimple<T>::ejercicio8(ListaSimple<T> &L1,ListaSimple<T> &L2)
{
    try
    {
        if(!L2.mp_head) throw 1;
        else
        {
            T d=L2.mp_head->m_dato;
            L1.Mypushfront(d);
            L2.Mypopfront();
            return L2;
        } 
    }
    catch(int e)
    {
        cout<<"Error, segunda lista vacia"<<endl;
    }
}

template<class T>
void ListaSimple<T>::Mypush(size_t pos,const T &d)
{
    if(pos>=Mysize())
    {
        cout<<"Fuera de rango"<<endl;
        return;
    }
    else
    {
        size_t cont=0;
        Nodo<T> *tmp=mp_head;
        while(cont<pos)
        {
            tmp=tmp->mp_next[1];
            ++cont;
        }
        /*if(tmp=mp_head) Mypushfront(d);
        if(tmp=mp_last) Mypushback(d);*/
        Nodo<T> *nuevo=new Nodo<T>(d);
        //cout<<tmp->m_dato<<endl;
        nuevo->mp_next[1]=tmp->mp_next[1];
        tmp->mp_next[1]=nuevo;
        ++m_size;    
    }
}

template<class T>
ListaSimple<T> ListaSimple<T>::mezclar(ListaSimple<T> &L1,ListaSimple<T> &L2)
{
 //   ListaSimple<T> Ldestino;
    Nodo<T> *tmp=L1.mp_head;
    Nodo<T> *tmp1=L2.mp_head;
    int i=0;
    if(L1.Mysize()<=L2.Mysize())
    {
        while(tmp && i<L2.Mysize())
            {           
             L2.Mypush(i,tmp->m_dato);
             tmp=tmp->mp_next[1];
             i=i+2;
            }        
        return L2;
    }
    else
    {
         while(tmp && i<L1.Mysize())
            {            
             L1.Mypush(i,tmp->m_dato);
             tmp1=tmp1->mp_next[1];
            }
        return L1;
    }
}

template<class T>
void ListaSimple<T>:: clear(Nodo<T> *tmp)
{
   if(!tmp) return;
   clear(tmp->mp_next[1]);
   delete tmp;
}

template<class T>
size_t ListaSimple<T>::Mysize()
{
	return m_size;
}

template<class T>
void ListaSimple<T>::Mypushfront(const T &d)
{
    Nodo<T> *nuevo=new Nodo<T>(d);
    if(!mp_head)
    {
    	mp_head=mp_last=nuevo;
    	++m_size;
    }
    else
    {
    	nuevo->mp_next[1]=mp_head;
    	mp_head=nuevo;
    	++m_size;
    }
}

template<class T>
void ListaSimple<T>::Mypushback(const T &d)
{
    Nodo<T> *nuevo=new Nodo<T>(d);
    if(!mp_head)
    {
    	mp_head=mp_last=nuevo;
    	++m_size;
    }
    else
    {
    	mp_last->mp_next[1]=nuevo;
    	mp_last=nuevo;
    	++m_size;
    }
}

template<class T>
bool ListaSimple<T>::Myfind(const T &d,Nodo<T> **&p)
{
     p=&mp_head;
     while(*p)
     {
     	 if((*p)->m_dato==d) {return true;}
     	 if((*p)->m_dato>d)  {return false;}
     	 p=&((*p)->mp_next[1]);
     }
     return false;
}

template<class T>
bool ListaSimple<T>::Myfind(const T &d)
{
	Nodo<T> **q=&mp_head;
	return Myfind(d,q);
}

template<class T>
void ListaSimple<T>::Mypopfront()
{
    if(!mp_head)   return;
    else
    {
        Nodo<T>* tmp=mp_head;
        mp_head=tmp->mp_next[1];
        delete tmp;
        --m_size;
        return;
    }
}


template<class T>
void ListaSimple<T>::Mypopback()
{
    if(!mp_head)   return;
    if(!mp_head->mp_next[1])
    {
       delete mp_last;
       mp_last=mp_head=0; 
       --m_size;
       return;
    }
    else
    {
        Nodo<T> *tmp=mp_head;
        while(tmp->mp_next[1]->mp_next[1])
        {
            tmp=tmp->mp_next[1];
        }
        tmp->mp_next[1]=0;
        delete mp_last;
        mp_last=tmp;
        --m_size;
        return;
    }
}

template<class T>
bool ListaSimple<T>::Myadd(const T &d)
{
    Nodo<T> **tmp;
    if(Myfind(d,tmp))
      {
        return false;
      }
    Nodo<T> *mp_nuevo=new Nodo<T>(d);
    if(*tmp==0) mp_last=mp_nuevo;
    mp_nuevo->mp_next[1]=(*tmp);
    (*tmp)=mp_nuevo;
    ++m_size;
    return true;
}

template <class T>
ListaSimple<T>& ListaSimple<T>:: operator >>(const T &d)
{
	Myadd(d);
	return *this;
}


template <class T>
bool ListaSimple<T>::Myremove(const T &d)
{
    Nodo<T> **t;
    if(!Myfind(d,t)) return false;
    Nodo<T> *tmp=*t;
    *t=(*t)->mp_next[1];
    delete *t;
    return true;
}


template<class T>
ListaSimple<T> ListaSimple<T>::dividir()
{
    size_t tam2=m_size/2;
    size_t tam1=m_size-tam2;
    Nodo<T> *temp=mp_head;
    ListaSimple<T> List1;
    for(size_t i=1;i<tam1;i++)
    {
        temp = temp->mp_next[1];
    }
    List1.mp_head=temp->mp_next[1];
    List1.m_size=tam2;
    List1.mp_last=mp_last;
    mp_last=temp;
    temp->mp_next[1]=NULL;
    List1.Myreverse();
    return List1;
}

template<class T>
void ListaSimple<T>::reordenar()
{
    Nodo<T> *temp=mp_head;
    while(temp)
    {
        T data = temp->m_dato;
        temp=temp->mp_next[1];
        Myremove(data);
        Myadd(data);
    }
}

template<class T>
void ListaSimple<T>::complemento(ListaSimple<T> L1, ListaSimple<T> List1)
{
    Nodo<T> *temp=L1.mp_head;
    ListaSimple<T> ListaTemp;
    while(temp)
    {
        ListaTemp.Myadd(temp->dato);
        temp=temp->mp_next[1];
    }
    L1.Myunion(L1,List1);
    List1.intersecar(List1,ListaTemp);
    temp=mp_head;
    while(temp)
    {
        if(List1.Myfind(temp->m_dato))
        {
            T dat=temp->m_dato;
            temp=temp->mp_next[1];
            Myremove(dat);
        }
        else
            temp=temp->mp_next[1];
    }
}   

template<class T>
ListaSimple<T>& ListaSimple<T>:: operator=(const ListaSimple<T> &L)
{
	this->clear(mp_head);
	Nodo<T> *mp=L.mp_head;
	while(mp)
	{
		this->Mypushback(mp->m_dato);
		mp=mp->mp_next[1];
	}      
   return *this;
}

template<class T>
void ListaSimple<T>::Myreverse()
{
	if(m_size<2) return;
	Nodo<T> *tmp2=mp_head->mp_next[1];
	Nodo<T> *tmp1=mp_head;
	Nodo<T> *tmp=0;
	while(tmp2)
	{
		tmp=tmp1;
		tmp1=tmp2;
		tmp2=tmp2->mp_next[1];
		tmp1->mp_next[1]=tmp;
	}
	mp_head->mp_next[1]=0;
	mp_last=mp_head;
	mp_head=tmp1;
}

template<class T>
void ListaSimple<T>::Myreverse_rec()
{
    if(m_size<2) return;
    Myreverse_rec(mp_head->mp_next[1]->mp_next[1],mp_head);
    mp_head->mp_next[1]=0;
    
    Nodo<T> *tmp1=mp_head;
    mp_head=mp_last;
    mp_last=tmp1;
    
}

template<class T>
void ListaSimple<T>::Myreverse_rec(Nodo<T> *&r,Nodo<T> *ant)
{
  if(r)
   Myreverse_rec(r->mp_next[1],ant->mp_next[1]);
   r=ant;
}

template<class T>
ListaSimple<T> ListaSimple<T>::Myunion(const ListaSimple<T> &L2)
{
	ListaSimple<T> Ldestino;
    Nodo<T> *tmp=mp_head;
    Nodo<T> *tmp2=L2.mp_head;
    while(tmp)
    {
         Ldestino.Myadd(tmp->m_dato);
         tmp=tmp->mp_next[1];
    }
    while(tmp2)
    {
         Ldestino.Myadd(tmp2->m_dato);
         tmp2=tmp2->mp_next[1];
    }
   return Ldestino;
}

template<class T>
ListaSimple<T> ListaSimple<T>::operator +(const ListaSimple<T> &L2)
{
    ListaSimple<T> tmp;
    tmp=Myunion(L2);
    return tmp;
}

template<class T>
ListaSimple<T> ListaSimple<T>::Myinterseccion(ListaSimple<T> L2)
{
	 ListaSimple<T> Ldestino;
     size_t tam2=L2.Mysize();
     if(m_size<=tam2        )
     {
        Nodo<T> *tmp1=mp_head;
        while(tmp1)
	    {
            if(L2.Myfind(tmp1->m_dato))
                {
                    Ldestino.Myadd(tmp1->m_dato);
                }
            tmp1=tmp1->mp_next[1];
        }
     }
     else
     {
        Nodo<T> *tmp2=L2.mp_head;
        while(tmp2)
        {
            if(Myfind(tmp2->m_dato))
                {
                    Ldestino.Myadd(tmp2->m_dato);
                }
            tmp2=tmp2->mp_next[1];
        }
    }
    return Ldestino;
}


template<class T>
ListaSimple<T> ListaSimple<T>::operator -(ListaSimple<T> L2)
{
    ListaSimple<T> tmp;
    tmp=Myinterseccion(L2);
    return tmp;
}


template <class T>
void ListaSimple<T>::Myprint()
{
	Nodo<T> *tmp=mp_head;
	while(tmp)
	{
		cout<<tmp->m_dato<<endl;
		tmp=tmp->mp_next[1];
	}
}


template <class T>
void ListaSimple<T>::Myprint_reverse()
{
    Nodo<T> * tmp=mp_head;
	Myprint_reverse(tmp);
}

template<class T>
void ListaSimple<T>::Myprint_reverse(Nodo<T> *r)
{
	if(!r) return;
	Myprint_reverse(r->mp_next[1]);
	cout<<r->m_dato<<endl;
}


#endif // LISTASIMPLE_H
