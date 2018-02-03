#include <iostream>
#include "btreeT.h"

using namespace std;

int main()
{
    BTree<int>  arbol;
    //arbol<<8<<10<<5<<20;


 /*   arbol.asig(3);
    arbol.asig(1);
    arbol.asig(5);
    arbol.asig(6);
    arbol.asig(9);
    arbol.asig(4);
    arbol.asig(0);
    arbol.asig(2);

    arbol.asig(1);
    arbol.asig(2);
    arbol.asig(3);
    arbol.asig(4);
    arbol.asig(5);
    arbol.asig(6);
    arbol.asig(7);
    arbol.asig(8);


    arbol.asig(8);
    arbol.asig(7);
    arbol.asig(6);
    arbol.asig(5);
    arbol.asig(4);
    arbol.asig(3);
    arbol.asig(2);
    arbol.asig(1);
*/
    arbol.asig(9);
    arbol.asig(13);
    arbol.asig(10);
    arbol.asig(5);
    arbol.asig(6);
    arbol.asig(25);
    arbol.asig(4);
    arbol.asig(0);
    arbol.asig(2);
    arbol.print(cout);

    return 1;
}
