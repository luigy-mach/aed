#include "nodoT.h"
#include <vector>

using namespace std;
template <class T>
class BTree
{
private:
    Nodo<T> * m_pRoot;

public:
    BTree()
    {
        m_pRoot=0;
    }
    Nodo<T> * getroot(){return m_pRoot;}

    Nodo<T>* papa(T d)
    {
         Nodo<T>* p =m_pRoot;

         while(p&&p->m_Dato!=d)
         {
             p=(p->m_Son[p->m_Dato<d]);
         }
             return p;
    }

    bool find(T d, Nodo<T>** &p)
    {
        p=&m_pRoot;
        while(*p)
        {
            if((*p)->m_Dato==d)
                return true;
            p=&((*p)->m_Son[(*p)->m_Dato<d]);
        }
        return false;
    }

    bool find2(T d, Nodo<T>** &p)
    {
        p=&m_pRoot;
        while(*p)
        {
            if((*p)->m_Dato!=d)
                return true;
            p=&((*p)->m_Son[(*p)->m_Dato>d]);
        }
        return false;
    }
        
    Nodo<T> * add(T d)
    {
        Nodo<T> ** p;
        if(find(d,p))	return false;
        else
        {
            (*p)=new Nodo<T>(d);

            return (*p);
        }
    }

    void rii(Nodo<T>*&p)
    {
        Nodo<T>*q=p->m_Son[0];
        p->m_Son[0]=q->m_Son[1];
        q->m_Son[0]=p;
        p=q;
        p->fe=q->fe=0;
    }
    void rdd(Nodo<T>*&p)
    {
        Nodo<T>*q=p->m_Son[1];
        p->m_Son[1]=q->m_Son[0];
        q->m_Son[1]=p;
        p=q;
        p->fe=q->fe=0;
    }
    void rid(Nodo<T>* &p)
    {
        Nodo<T>*q=p->m_Son[0];
        Nodo<T>*z=q->m_Son[0];
        p->m_Son[1]=z->m_Son[0];
        q->m_Son[0]=z->m_Son[1];
        z->m_Son[0]=p;
        z->m_Son[1]=q;

    }

    void restructurar(int a,vector<Nodo<T>*> &vi)
    {

    }

    void verificar(vector<Nodo<T>*> &v)
    {
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i]->m_Dato>v[i+1]->m_Dato&&v[i+1]->visit==true)
            {
                v[i+1]->visit=false;
                v[i]->fe=v[i]->getfe()-1;
                v[i]->visit=true;
            }
            else if(v[i]->m_Dato<v[i+1]->m_Dato&&v[i+1]->visit==true)
            {
                v[i+1]->visit=false;
                v[i]->fe=v[i]->getfe()+1;
                v[i]->visit=true;
            }
        }

    }

    void asig(T d)
    {
        if(m_pRoot==0)
        {
            Nodo<T> * p= add(d);
            p->m_Parent=0;
        }
        else
        {
            Nodo<T> * v;
            Nodo<T> * p= add(d);
            vector<Nodo<T>*> vi;
            v=padre(d,vi);
            cout<<"papa: "<<endl;
            p->m_Parent=v;
            /*if(p->m_Dato < p->getParent()->m_Dato)
            {
                p->getParent()->key-=1;
            }
            else
            {
                p->getParent()->key+=1;
            }*/
            vi.push_back(p);
            if(m_pRoot)
                verificar(vi);
        }
    }

    Nodo<T> * padre(T d,vector<Nodo<T>*> &vi)
    {
        Nodo<T> * p = m_pRoot;

        while(p && p->m_Dato!=d)
        {
            vi.push_back(p);
            p=(p->m_Son[p->m_Dato<d]);
        }
        return vi.back();
    }

        
    void print(ostream &os)
    {
        print(m_pRoot, os);
    }
        
    void print (Nodo<T> * r, ostream &os)
    {
       	if(!r) return;    
        os<<r->m_Dato<<"("<<r->fe<<") ";
        print(r->m_Son[0],os);
        print(r->m_Son[1],os);
    }

    BTree & operator <<(T d)
    {
        add(d);
        return *this;
    }
    void borrar(T d)
       {
           Nodo <T> **p;
           if(find(d,p))
           {
               if(!(*p)->m_Son[0] && !(*p)->m_Son[1])
               {
                   (*p)=0;
                   delete (*p);
                   return;
               }
               if((*p)->m_Son[!(*p)->m_Son[0]]&& !((*p)->m_Son[!(*p)->m_Son[1]]))
               {
                   Nodo<T> * tmp =(*p);
                   (*p)=tmp->m_Son[!(*p)->m_Son[0]];
                   delete tmp;
               }
               if((*p)->m_Son[1]&&(*p)->m_Son[0])
               {
                   Nodo<T> ** q= &((*p)->m_Son[0]);
                   while((*q)->m_Son[1])
                       q=&((*q)->m_Son[1]);
                   (*p)->m_Dato=(*q)->m_Dato;
                   Nodo<T> * r= (*q);
                   (*q)=(*q)->m_Son[0];
                   delete r;
               }
           }
       }
   void minimo(Nodo<T> * p)
   {
       if(!p)return;
       if(!p->m_Son[0])
           cout<<"El minimo es"<<"  "<<p->m_Dato<<endl;
       minimo(p->m_Son[0]);
   }
   void maximo(Nodo<T> * p)
   {
       if(!p)return;
       if(!p->m_Son[1])
           cout<<"El maximo es"<<"  "<<p->m_Dato<<endl;
       maximo(p->m_Son[1]);
   }

   void minimo()
   {
       Nodo<int> * p=getroot();
       minimo(p->m_Son[0]);
   }
   void maximo()
   {
       Nodo<int> * p=getroot();
       maximo(p->m_Son[1]);
   }
   void printAncestros(T d)
   {
       Nodo<T> * p =m_pRoot;
       vector<T> vi;
        while(p&&p->m_Dato!=d)
        {
            vi.push_back(p->m_Dato);
            p=(p->m_Son[p->m_Dato<d]);
        }
            for(unsigned int i=0;i<vi.size();i++)
                cout<<"  "<<(vi[i])<<endl;
    }
   void printhojas(Nodo<T> * r)
   {
       if(!r)return;
       if(!r->getson0()&&!r->getson1())
       {
           cout<<"Dato de hoja"<<"     "<<r->m_Dato<<endl;
       }
       printhojas(r->getson0());
       printhojas(r->getson1());
   }

   T getmayoromenor(bool i)
   {
       Nodo<T> * tmp =m_pRoot;
       while(tmp->m_Son[i])
       {
           tmp=tmp->m_Son[i];
       }
       return tmp->m_Dato;
   }
   void printbrother(T d)
   {
       Nodo<T> * p;
       Nodo<T> * q;
       p=m_pRoot;
       q=m_pRoot;
       while(p)
       {
           if(p==m_pRoot&&d==p->m_Dato)
           {
               cout<<"No hay hermano porque es la Raiz"<<endl;
               return;
           }
           else
           {
               q=p;
               if(p->m_Dato>d)
                   p=p->m_Son[0];
               if(p->m_Dato<d)
                   p=p->m_Son[1];
               else
               {
                  if(q->m_Son[1]==p)
                  {
                      cout<<q->m_Son[0]->m_Dato;
                      return;
                  }
                  if(q->m_Son[0]==p)
                  {
                      cout<<q->m_Son[1]->m_Dato;
                      return;
                  }
               }
           }
       }
       cout<<"comprobar si hay hijo primero"<<endl;
   }

};
/*for(int i=vi.size()-1;i>=0;i--)
{
    cout<<"entra al for con  "<<"valor de  i :   "<<i<<endl;
    if((vi[i])->fe!=100)//(vi[i])->fe<2&&(vi[i])->fe>-2)
    {
        cout<<"entra al if de 2"<<endl;
        //cout<<vi[i]->m_Dato<<"     "<<vi[i-1]->m_Dato<<endl;
        if(i==0)
        {
            cout<<"entra al if si es 0"<<endl;
            /*if((vi[i+1])->fe==0||(vi[i+1])->fe==1||(vi[i+1])->fe==-1)
            {
                cout<<"raiz a no modificar"<<endl;
                return;
            }
            else
            {
                cout<<"el fe de la raiz se va modificar"<<endl;
                if((vi[i])->m_Dato>(vi[i+1])->m_Dato)
                    (vi[i])->fe=(vi[i]->getfe())-1;
                (vi[i])->fe=(vi[i]->getfe())+1;

            //}
        }
        else
        {
            if((vi[i])->m_Dato<vi[i-1]->m_Dato)
            {
                cout<<"entra al if para  -1"<<endl;
                vi[i-1]->fe=(vi[i-1]->getfe())-1;
            }
            else
            {
                cout<<"entra al if pa +1"<<endl;
                (vi[i-1])->fe=(vi[i-1]->getfe())+1;
            }
        }
    }
    else
    {

        //restructurar(i,vi);
        return;
    }

}*/


