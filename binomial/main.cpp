#include<iostream>
#include "binomial.h"
using namespace std;

int main () {
	
	Binomial<int> b;
	
	for(int i=1;i<1000;i++)
		b.insert(i);
	b.print_dot();

	
	
	return 0;
}

