#include <iostream>
#include "binomialH.h"

using namespace std;

int main()
{
    binomialH<int> nuevoBH;
    for(int i=0;i<7;i++){
    cout<<"inserte "<<i<<endl;
    nuevoBH.insertt(i);}
    //nuevoBH.insertt(5);
    //nuevoBH.insertt(2);
    //nuevoBH.insertt(8);
    //nuevoBH.print();
}
