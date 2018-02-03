#include<iostream>
#include<vector>
using namespace std;
int absoluto(int a)
{
	if(a<0)
		return (-1)*a;
	return a;
}

void limpiar_vector(int vector[])
{
	for(int i=0;i<3002;i++)
		vector[i]=0;
}
int revision(int vector[],int tope)
{
	int res=1;
	for(int i=0;i<tope&&res==1;i++)
	{
		if(vector[i]==0)
			res=0;
	}
	return res;
}
int main()
{
	int tope;
	while(cin>>tope){
	if(tope==1)
	{
		cout<<"Jolly"<<endl;
		return 0;
	}
	if(tope==0)
	{
		cout<<"Not jolly"<<endl;
		return 0;
	}
	else{
	int vector[3002];
	limpiar_vector(vector);
	int vtmp[tope];
	for(int i=0;i<tope;i++)
	{
		cin>>vtmp[i];
	}
	for(int i=0;i<tope-1;i++)
	{
		int a=vtmp[i];
		int b=vtmp[i+1];
		int r=absoluto(a-b);
		vector[r]=1;
	}
	vector[0]=vector[3001]=1;
	if(revision(vector,tope))
		cout<<"Jolly"<<endl;
	else
		cout<<"Not jolly"<<endl;
	}
	}
}
/*void saltarina(int t,vector<int> &l)
{
	bool test;
	if(t>1)
	{
	vector<int> r;
	for(int i=0;i<t-1;i++)
	{
		if(absoluto(l[i]-l[i+1])<t)
			r.push_back(1);
		else
		{
			r.push_back(0);
		}
	}
	
	for(int i=1;i<r.size();i++)
	{
		if(r[i]==1)
			test=true;
		else
		{
			test=false;
			break;		
		}	
	}
	}
	if(t==1)
	{
		test=true;
	}
	if(test)
		cout<<"Jolly";
	else
		cout<<"Not jolly";
}
int main()
{
	int t;
    vector<int> l;
    cin>>t;
	if(t>0&&t<3000)
	{
		for(int i=0;i<t;i++)
		{
			int s;
			cin>>s;
			//a[i]=s;
			l.push_back(s);
		}
		saltarina(t,l);
	}
	return 0;
	
}
*/
