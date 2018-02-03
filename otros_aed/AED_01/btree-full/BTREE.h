
#include <vector>
#include <algorithm>
#include "KEYINFO.h"

using namespace std;

enum error_code{ok=1,overflow_error,underflow_error,duplicated_error,not_found_error};
typedef size_t ST;
typedef long pReg;
const ST orden_default=128;
template<typename T>class BTREE;
template<typename T>class BTREEPAGE;
/************************FUNCIONES************************/


/************************BTREEPAGE************************/
template<typename T>
class BTREEPAGE{
  private:
  vector< KEYINFO<T> > m_keys;
  vector<BTREEPAGE*> m_pChildren;
  ST m_orden,m_nkeys;

  public:
  BTREEPAGE(ST _orden):m_orden(_orden),m_nkeys(0){
    m_keys.resize(_orden+1);
    m_pChildren.resize(_orden+2);
    for(register ST i=0;i<_orden+2;++i)
       m_pChildren[i]=0;
  }
  error_code insert(const KEYINFO<T> &ki);
  void clean();
  void insert_at(BTREEPAGE<T> *p1,KEYINFO<T> &ki,BTREEPAGE *p2,int pos);
  int binary(vector< KEYINFO<T> > &v,int _ini,int _fin,const KEYINFO<T> &ki);
  bool buscar(KEYINFO<T> &ki);
  ST altura();
  friend class BTREE<T>;
};

template<typename T>
void BTREEPAGE<T>::clean()
{
  for(register ST i=0;i<=m_nkeys;++i) m_pChildren[i]=0;
  m_nkeys=0;
}

template<typename T>
void BTREEPAGE<T>::insert_at(BTREEPAGE<T> *p1,KEYINFO<T> &ki,BTREEPAGE *p2,int pos)
{
  BTREE<T> *pt=0;
  pt->insert_at_ki(m_keys,pos,ki,m_nkeys);++m_nkeys;
  pt->insert_at_prev(m_pChildren,pos,p1);
  pt->insert_at_post(m_pChildren,pos+1,p2,m_nkeys);
}

template<typename T>
int BTREEPAGE<T>::binary(vector< KEYINFO<T> > &v,int inf,int sup,const KEYINFO<T> &ki)
{
  int max=sup,medio;
  --sup;
  while(inf<=sup)
  {
    medio=(inf+sup)/2;
    if(v[medio].dato==ki.dato) return medio;
    if(ki.dato<v[medio].dato) {
      sup=medio-1;
      if(sup<0 || v[sup].dato<ki.dato) return medio;
    }
    else {
      inf=medio+1;
      if(inf==max || v[inf].dato>ki.dato) return inf;
    }
  }
  return 0;
}

template<typename T>
error_code BTREEPAGE<T>::insert(const KEYINFO<T> &ki)
{
  BTREE<T> *pt=0;
  int pos=binary(m_keys,0,m_nkeys,ki);
  if(pos<m_nkeys)
    if(m_keys[pos].dato==ki.dato)
       return duplicated_error;

  if(m_pChildren[pos])
  {
    error_code e=m_pChildren[pos]->insert(ki);
    if(e==duplicated_error || e==ok)
      return e;
    BTREEPAGE<T> *pPage1,*pPage2;
    KEYINFO<T> ki;
    pt->splitpage(m_pChildren[pos],pPage1,ki,pPage2);
    insert_at(pPage1,ki,pPage2,pos);
  }
  else {pt->insert_at_ki(m_keys,pos,ki,m_nkeys);++m_nkeys;}
  if(m_nkeys>m_orden) return overflow_error;
  return ok;
}

template<typename T>
bool BTREEPAGE<T>::buscar(KEYINFO<T> &ki)
{
  int pos=binary(m_keys,0,m_nkeys,ki);
  if(m_keys[pos].dato==ki.dato) return true;
  if(!m_pChildren[pos]) return false;
  m_pChildren[pos]->buscar(ki);
}

template<typename T>
ST BTREEPAGE<T>::altura()
{
  if(!m_pChildren[0]) return 0;
  return 1+m_pChildren[0]->altura();
}
/************************BTREE************************/
template<typename T>
class BTREE{
  private:
  BTREEPAGE<T> *m_pRoot;
  ST n;

  public:
  BTREE(ST _orden=orden_default):n(0){
    m_pRoot=new BTREEPAGE<T>(_orden);
  }
  void insert(const T &_key,const pReg &_reg);
  void splitpage(BTREEPAGE<T> *&father,BTREEPAGE<T> *&pPage1,KEYINFO<T> &ki,BTREEPAGE<T> *&pPage2);
  void insert_at_ki(vector< KEYINFO<T> > &v,ST pos,const KEYINFO<T> &ki,ST n_max);
  void insert_at_prev(vector< BTREEPAGE<T>* > &v,ST pos,BTREEPAGE<T> *child);
  void insert_at_post(vector< BTREEPAGE<T>* > &v,ST pos,BTREEPAGE<T> *child,ST n_max);
  bool buscar(const T &_dato);
  void splitroot();
  ST altura();
  ST size(){return n;}
};

template<typename T>
void BTREE<T>::insert(const T &_key,const pReg &_reg)
{
  error_code e=m_pRoot->insert(KEYINFO<T>(_key,_reg));
  if(e==overflow_error) splitroot();
  if(e!=duplicated_error) ++n;
}

template<typename T>
void BTREE<T>::splitpage(BTREEPAGE<T> *&father,BTREEPAGE<T> *&pPage1,KEYINFO<T> &ki,BTREEPAGE<T> *&pPage2)
{
  pPage1=new BTREEPAGE<T>(father->m_orden);
  pPage2=new BTREEPAGE<T>(father->m_orden);
  ST medio=father->m_orden/2;
  copy(father->m_keys.begin(),father->m_keys.begin()+medio,pPage1->m_keys.begin());pPage1->m_nkeys=medio;
  copy(father->m_pChildren.begin(),father->m_pChildren.begin()+medio+1,pPage1->m_pChildren.begin());
  ki=father->m_keys[medio];
  copy(father->m_keys.begin()+medio+1,father->m_keys.end(),pPage2->m_keys.begin());pPage2->m_nkeys=father->m_orden-medio;
  copy(father->m_pChildren.begin()+medio+1,father->m_pChildren.end(),pPage2->m_pChildren.begin());
}

template<typename T>
void BTREE<T>::splitroot()
{
  BTREEPAGE<T> *pPage1,*pPage2;
  KEYINFO<T> ki;
  splitpage(m_pRoot,pPage1,ki,pPage2);
  m_pRoot->clean();
  m_pRoot->insert_at(pPage1,ki,pPage2,0);
}

template<typename T>
void BTREE<T>::insert_at_ki(vector< KEYINFO<T> > &v,ST pos,const KEYINFO<T> &ki,ST n_max)
{
  for(register ST i=n_max;i>pos;--i) v[i]=v[i-1];
  v[pos]=ki;
}

template<typename T>
void BTREE<T>::insert_at_prev(vector< BTREEPAGE<T>* > &v,ST pos,BTREEPAGE<T> *child)
{
  delete  v[pos];
  v[pos]=child;
}

template<typename T>
void BTREE<T>::insert_at_post(vector< BTREEPAGE<T>* > &v,ST pos,BTREEPAGE<T> *child,ST n_max)
{
  for(register ST i=n_max;i>pos;--i) v[i]=v[i-1];
  v[pos]=child;
}

template<typename T>
bool BTREE<T>::buscar(const T &_dato)
{
  KEYINFO<T> ki(_dato,0);
  return m_pRoot->buscar(ki);
}

template<typename T>
ST BTREE<T>::altura()
{
    return 1+m_pRoot->altura();
}
