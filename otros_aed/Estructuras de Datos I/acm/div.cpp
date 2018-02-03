#include <iostream>
using namespace std;
int div(int a,int b)
{
	int r=0;
	for(;a>=b;a=a-b)
	{
		r++;
	}
	return r;
}

int main()
{
	int c;
	int d;
	int a=div(c,d);
	cin>>c;
	cin>>d;
	cout<<a<<endl;
	return 0;
}

