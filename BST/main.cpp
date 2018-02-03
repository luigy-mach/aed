#include<iostream>
using namespace std;

#include<stdlib.h> 
#include<time.h>

#include "btree.h"


int main(){
	
/*	srand(time(NULL));

	cout<<"----"<<endl;
	Btree<int> tree;
	for(int i=0;i<8;i++)
		tree.add(rand()%77);
//	tree>>12>>15>>4>>16;
	tree.print_BFS();
	
	cout<<"----"<<endl;
	Btree<int> tree2;
	for(int i=0;i<8;i++)
		tree2.add(rand()%77);
*/

//	tree2>>121>>15>>41>>16;
	/*tree2.print_BFS();

	cout<<"----"<<endl;
	Btree<int> tree3;
	tree3=tree-tree2;

	tree3.print_BFS();
	tree2.print_BFS();
	tree.print_BFS();*/
//---------------------------------------------
	Btree<int> a;
	//a>>20>>10>>5>>45>>60>>25;
	a.add(20);
	a.add(10);
	a.add(0);
	a.add(5);
	a.add(50);
	a.add(25);
	a.add(60);
//	a.print_infijo_re(a.m_pRoot);
	a.print_BFS();

return 0;
}




