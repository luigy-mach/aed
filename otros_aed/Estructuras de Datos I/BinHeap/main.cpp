#include <iostream>
/*#include "binomial.h"
#include "garbageCollector.h"
#include "garbage.h"*/
#include "binomial.h"

using namespace std;
int main()
{

    /*garbagecollector * w= new garbagecollector<Persona>();
    Persona *p = (per)w->New(sizeof(Persona));*/

    binomial<int> * H = binomial<int>::Init();
    H=H->MAKE_BINOMIAL_HEAP();
    nodoB<int> * np1 = new nodoB<int>(5);
    nodoB<int> * np2 = new nodoB<int>(3);
    nodoB<int> * np3 = new nodoB<int>(15);

    H->BINOMIAL_HEAP_INSERT(np1);
    H->BINOMIAL_HEAP_INSERT(np2);
    H->BINOMIAL_HEAP_INSERT(np3);
    //H->BINOMIAL_HEAP_DELETE(H,np3);
    //H->BINOMIAL_HEAP_DECREASE_KEY(H,np3,10);
    //cout<<H->getHead()->getSibling()->getChild()->getKey();
    //cout<<heap->;
    //cout<<H->getHead()->getKey();
    cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey();
    //cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey();


}
    /*binomial<int> * H =binomial<int>::Init();
    H=H->MAKE_BINOMIAL_HEAP();
    nodoB<int> * np1 = new nodoB<int>(5);
    nodoB<int> * np2 = new nodoB<int>(3);
    nodoB<int> * np3 = new nodoB<int>(15);

    H=H->BINOMIAL_HEAP_INSERT(H,np1);
    H=H->BINOMIAL_HEAP_INSERT(H,np2);
    H=H->BINOMIAL_HEAP_INSERT(H,np3);
    //H->BINOMIAL_HEAP_DELETE(H,np2);
    //H->BINOMIAL_HEAP_DECREASE_KEY(H,np3,10);
    //cout<<H->getHead()->getSibling()->getChild()->getKey();
    //cout<<heap->;
    //cout<<H->getHead()->getKey();
    cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey()<<endl;
    cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey();
    //binomial<garbage*> *bin=new binomial<garbage*>();
*/

/*
int main()
  {
    binomial<int> * H = new binomial<int>();
    H=H->MAKE_BINOMIAL_HEAP();
    nodoB<int> * np1 = new nodoB<int>(5);
    nodoB<int> * np2 = new nodoB<int>(3);
    nodoB<int> * np3 = new nodoB<int>(15);

    H=H->BINOMIAL_HEAP_INSERT(H,np1);
    H=H->BINOMIAL_HEAP_INSERT(H,np2);
    H=H->BINOMIAL_HEAP_INSERT(H,np3);
    //H->BINOMIAL_HEAP_DELETE(H,np3);
    //H->BINOMIAL_HEAP_DECREASE_KEY(H,np3,10);
    //cout<<H->getHead()->getSibling()->getChild()->getKey();
    //cout<<heap->;
    //cout<<H->getHead()->getKey();
    cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey();
    //cout<<H->BINOMIAL_HEAP_EXTRACT_MIN(H)->getKey();
  }
*/
/*
#include "nodo.h"
#include <map>

typedef map<int,string> T_mapa;
//typedef map<long int, Nodo*> T_mapa;
//typedef map<long int, string> T_mapa;
int main()
{
    T_mapa m;
    m.insert(pair<int,string>(10,"carlos"));
    m.insert(pair<int,string>(2,"eddy"));
    m.insert(pair<int,string>(50,"alal"));
    m.insert(pair<int,string>(15,"jose"));
    m.insert(pair<int,string>(34,"juan"));
    cout << m[10] << endl;
    /*string data[] = {"carlos","juan","maria","rosa"};
    T_mapa m;
    m.insert(pair<long int,string>((long int)&(data[0]),data[0]));
    m.insert(pair<long int,string>((long int)&(data[1]),data[1]));
    m.insert(pair<long int,string>((long int)&(data[2]),data[2]));
    m.insert(pair<long int,string>((long int)&(data[3]),data[3]));
    cout << m[(long int)(&data[1])] <<endl;
    return 0;

}
*/
