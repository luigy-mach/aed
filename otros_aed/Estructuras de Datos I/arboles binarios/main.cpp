/*#include <iostream>
#include "btree.cpp"
using namespace std;

int main()
{
    btree<int> a;
    a.add(5);
    a.add(3);
    a.add(4);
    a.add(10);
    a.ra();
    cout << "Hello world!" << endl;
    return 0;
}
*/

#include<iostream>
#include<vector>
using namespace std;
int absoluto(int a)
{
	if(a<0)
		return (-1)*a;
	return a;
}
void saltarina(int t,vector<int> l)
{
	vector<int> r;
	for(int i=0;i<t-1;i++)
	{
		r.at(absoluto(l[i]-l[i+1]));
	}
	int cont=r[0];
	bool test;
	for(int i=1;i<r.size();i++)
	{
		if(r[i]==cont-i)
			test=true;
		test=false;
	}
	if(test)
		cout<<"Jolly";
	cout<<"Not jolly";
}
int main()
{
	int t;
    vector<int> l;
    while(cin>>t)
	{
		if(t>0)
		{
			int *a=new int[t];
			for(int i=0;i<t;i++)
			{
				int s;
				cin>>s;
				a[i]=s;
				l.push_back(a[i]);
			}
			cout<<"lleno"<<endl;
			saltarina(t,l);
			cout<<endl;
		}
	}
}
