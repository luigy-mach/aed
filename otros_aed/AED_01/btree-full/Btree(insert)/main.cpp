#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdio>


using namespace std;

#include "BTREE.h"

int main()
{
    /*BTREE<int> arbol(128);
    for(register int i=1;i<=1500000;++i)
       arbol.insert(i,0);
    cout<<arbol.size();
    cout<<" altura->"<<arbol.altura();

    getchar();*/

    KEYINFO<int> ki(5,0);
    int n=10;
    n=(int)ki;
    cout<<n<<endl;
    return 0;
}
