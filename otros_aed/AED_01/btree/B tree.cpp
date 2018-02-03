#include <iostream>
#include <vector>
using namespace std;
typedef long ptr2reg;
enum error_code{ok=1, overflow, underflow, duplicated};

template <typename T>
struct keyinfo
{
    T dato;
    ptr2reg id;
    //keyinfo(keyinfo &_ki): dato(_ki.dato), id(_ki.id){}
    keyinfo(T &_d, ptr2reg &_id): dato(_d), id(_id){}
};
template <typename T>
class CBTree;
template <typename T>
class CBTreePage
{
    friend class CBTree<T>;
    private:
        vector<keyinfo<T> > veckey;
        vector<CBTreePage<T> *> vecPCB;
        size_t m_ordenkey;
        size_t m_count;
        size_t m_hijo;
        size_t m_countvp;
        size_t m_c_hijo;

    public:
        CBTreePage(size_t orden):
            m_ordenkey(orden), m_hijo(false), m_count(0), m_c_hijo(0), m_countvp(0){}
        error_code insert_P(CBTreePage<T>*&, CBTreePage<T>*&, T, ptr2reg);
        void insert_at(CBTreePage<T> *&, CBTreePage<T> *&, size_t, size_t);
        size_t buscar_P(T);
        void move(CBTreePage<T>*&, size_t&, T&, ptr2reg&);
        error_code splitpage(CBTreePage<T>*&, CBTreePage<T>*&, CBTreePage<T>*&);
        void mostrar(CBTreePage<T>*);

};
template <typename T>
error_code CBTreePage<T>::insert_P(CBTreePage<T> *&rp, CBTreePage<T> *&ov, T _d, ptr2reg _id)
{
    if(rp->m_count<=rp->m_ordenkey)
    {
        size_t pos=rp->buscar_P(_d);
        size_t tamVP=rp->vecPCB.size();
        cout<<"pos: "<<pos<<endl;
        if(tamVP!=0)
        {
            rp->m_hijo=pos;
            rp->insert_P(rp->vecPCB[pos],ov,_d,_id);
        }
        else
        {
            rp->move(rp,pos,_d,_id);
            if(rp->m_count>rp->m_ordenkey)
            {
                ov=rp;
                return overflow;
            }
            else
                return ok;
        }
    }
}
template <typename T>
void CBTreePage<T>::insert_at(CBTreePage<T> *&rp, CBTreePage<T> *&pPage, size_t pos1, size_t pos2)
{
    while(pos1<=pos2)
    {
        keyinfo<T> ki=rp->veckey[pos1];
        pPage->veckey.push_back(ki);
        pPage->m_count++;
        pos1++;
    }
}

template <typename T>
size_t CBTreePage<T>::buscar_P(T vec_dato)
{
    if(m_count==0)
        return 0;
    size_t ini=0;
    size_t fin=m_count-1;
    size_t med=(ini+fin)/2;
    while(true)
    {
        if(vec_dato<veckey[med].dato&&med==0)
            return ini;
        if(vec_dato>veckey[med].dato&&med==m_count-1)
            return fin+1;
        if(vec_dato>veckey[med].dato&&vec_dato<veckey[med+1].dato)
            return med+1;
        if(vec_dato<veckey[med].dato)
            fin=med;
        if(vec_dato>veckey[med+1].dato)
            ini=med+1;
        med=(ini+fin)/2;
    }
}
template <typename T>
void CBTreePage<T>::move(CBTreePage<T> *&rp, size_t &posicion, T &_d, ptr2reg &_id)
{
    keyinfo<T> ki(_d,_id);
    if(posicion==rp->m_count&&rp->veckey.size()==rp->m_count)
    {
        rp->veckey.push_back(ki);
        m_count++;
        return;
    }
    else
    {
        while(posicion<rp->m_count)
        {
            keyinfo<T> temp=rp->veckey[posicion];
            rp->veckey[posicion]=ki;
            ki=temp;
            posicion++;
        }
    }
    if(rp->m_count!=rp->veckey.size())
    {
        rp->veckey[posicion]=ki;
        m_count++;
        return;
    }

    move(rp,posicion,ki.dato,ki.id);
}
template <typename T>
error_code CBTreePage<T>::splitpage(CBTreePage<T> *&rp, CBTreePage<T> *&ov, CBTreePage<T> *&pPage1)
{
    size_t pos=0;
    size_t ini=0;
    size_t fin=ov->m_count-1;
    size_t med=fin/2;
    if(rp==ov&&ov->m_countvp==0)
    {
        ov=new CBTreePage<T>(m_ordenkey);
        ov->insert_at(rp,ov,med,med);
        ov->vecPCB.push_back(rp);
        ov->m_countvp++;

        pPage1=new CBTreePage<T>(m_ordenkey);
        pPage1->insert_at(rp,pPage1,med+1,fin);
        ov->vecPCB.push_back(pPage1);
        ov->m_countvp++;

        rp->m_count=med;
        rp=ov;
        if(rp->m_count>rp->m_ordenkey)
            return overflow;
        else
            return ok;
    }
    if(rp==ov&&rp->m_countvp!=0)
    {
        ov=new CBTreePage<T>(m_ordenkey);
        ov->insert_at(rp,ov,med,med);
        ov->vecPCB.push_back(rp);
        ov->m_countvp++;

        pPage1=new CBTreePage<T>(m_ordenkey);
        pPage1->insert_at(rp,pPage1,med+1,fin);
        ov->vecPCB.push_back(pPage1);
        ov->m_countvp++;

        rp->m_count=1;

        if(rp->m_countvp!=0)
        {
            size_t tamvp=rp->vecPCB.size();
            size_t medvp=tamvp/2;
            while(med<fin)
            {
                pPage1->vecPCB.push_back(rp->vecPCB[med]);
                pPage1->m_countvp++;
                //rp->m_countvp--;
                med++;
            }
            rp->m_count=med;
            rp->m_countvp=medvp;
            rp=ov;
            if(rp->m_count>rp->m_ordenkey)
                return overflow;
            else
                return ok;
        }
    }
    if(rp->vecPCB[rp->m_hijo]==ov)
    {
        rp->veckey[m_hijo]=ov->veckey[med];
        rp->m_count+=1;
        pPage1=new CBTreePage<T>(m_ordenkey);
        pPage1->insert_at(ov,pPage1,med+1,fin);
        rp->vecPCB.push_back(pPage1);
        rp->m_countvp++;
        ov->m_count=med;
        ov=rp;
        if(rp->m_count>rp->m_ordenkey)
            return overflow;
        else
            return ok;
    }
        //cout<<"no es lo mismooooo..."<<endl;
}

template <typename T>
void CBTreePage<T>::mostrar(CBTreePage<T> *rp)
{
    size_t hijo=0;
    size_t tamvk=rp->m_count;
    size_t tamvp=rp->m_countvp;
    CBTreePage<T> *temp=rp;

    cout<<"vector: ";
    for(size_t i=0;i<tamvk;i++)
        cout<<rp->veckey[i].dato<<" ";
    cout<<"        termino"<<endl;
    while(tamvp!=0&&hijo<tamvp)
    {
        temp=rp->vecPCB[hijo];
        size_t tamavk=temp->m_count;
        size_t tamavp=temp->m_countvp;
        cout<<"hijo: ";
        for(size_t i=0;i<temp->m_count;i++)
            cout<<temp->veckey[i].dato<<" ";
        cout<<endl;
        hijo++;
    }
}

//---------------------------------------------------------//
template<typename T>
class CBTree
{
    private:
        CBTreePage<T> *m_proot;
        CBTreePage<T> *m_page;
        size_t m_orden;
        error_code m_estado;
    public:
        CBTree(size_t orden):
            m_orden(orden), m_page(0){m_proot=new CBTreePage<T>(m_orden);}
        void insert_T(T&, ptr2reg&);
        void insert_int(T&, ptr2reg&, CBTreePage<T>*&, CBTreePage<T>*&);
        error_code splitroot(CBTreePage<T>*&, CBTreePage<T>*&);
        void mostrarBT();
};

template <typename T>
void CBTree<T>::insert_T(T &_d, ptr2reg &_id)
{
    insert_int(_d,_id,m_proot,m_page);
}

template <typename T>
void CBTree<T>::insert_int(T &_d, ptr2reg &_id, CBTreePage<T> *& rp, CBTreePage<T> *&ov)
{
    m_estado=rp->insert_P(rp,ov,_d,_id);
    cout<<"estado: "<<m_estado<<endl;

    while(m_estado==overflow)
    {
        m_estado=splitroot(rp,ov);
        //cout<<"puntero overflow: .........."<<m_page->veckey[0].dato<<endl;
        //cout<<"posicion 0 vec ov: "<<ov->veckey[0].dato<<endl;
    }
    cout<<"posicion 0 vec rp: "<<rp->veckey[0].dato<<endl;
}

template <typename T>
error_code CBTree<T>::splitroot(CBTreePage<T> *&rp, CBTreePage<T> *&ov)
{
    CBTreePage<T> *pPage1=0;
    m_estado=rp->splitpage(rp,ov,pPage1);
}

template <typename T>
void CBTree<T>::mostrarBT()
{
    size_t hijo=0;
    CBTreePage<T> *temp=m_proot;
    temp->mostrar(temp);
    if(temp->vecPCB.size()!=0)
    {
        temp=temp->vecPCB[0];
        temp->mostrar(temp);
    }
    /*temp=temp->vecPCB[0];
    if(temp->vecPCB.size()!=0)
        cout<<"HAY ALGOO!!!!  "<<endl;*/
}

int main()
{
    ptr2reg x0=0,x1=1,x2=2,x3=3,x4=4,x5=5,x6=6,x7=7,x8=8,x9=9,x10=10,x11=11,x12=12,x13=13,x14=14,x15=15,x16=16,x17=17;
    int     y0=0,y1=1,y2=2,y3=3,y4=4,y5=5,y6=6,y7=7,y8=8,y9=9,y10=10,y11=11,y12=12,y13=13,y14=14,y15=15,y16=16,y17=17;
    CBTree<int> a(2);
    cout<<"insertando 2: "<<endl;
    a.insert_T(y2,x2);
    cout<<"insertando 4: "<<endl;
    a.insert_T(y4,x4);
    cout<<"insertando 7: "<<endl;
    a.insert_T(y7,x7);
    cout<<"insertando 8: "<<endl;
    a.insert_T(y8,x8);
    cout<<"insertando 12: "<<endl;
    a.insert_T(y12,x12);
    cout<<"insertando 13: "<<endl;
    a.insert_T(y13,x13);
    cout<<"insertando 14: "<<endl;
    a.insert_T(y14,x14);
    /*cout<<"insertando 13: "<<endl;
    a.insert_T(y13,x13);
    a.insert_T(y16,x16);*/
    a.mostrarBT();
}
