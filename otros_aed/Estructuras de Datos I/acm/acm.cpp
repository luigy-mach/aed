/* @BEGIN_OF_SOURCE_CODE */
#include<iostream>
using namespace std;
void ciclo(int n,int &cont)
{
   if(n==1)
   {
       cont=cont+1;
       return;
   }
   else
   {
       if(n%2==0)
       {
           cont=cont+1;
                n=n/2;
           if(n>=0)
           {
               ciclo(n,cont);
           }
           else
           {
               return;
           }
       }
       else
       {
           cont=cont+1;
           n=(3*n)+1;
           if(n>=0)
           {
                ciclo(n,cont);
           }
           else
           {
               return;
           }
       }
    }
}

int max_ciclo(int a,int b)
{
    if(a<1000000&&b<1000000&&a>0&&b>0)
    {
        int max=0;
        for(a;a<=b;a++)
        {
                int tmp=0;
                ciclo(a,tmp);
                    if(tmp>max)
                max=tmp;
        }
        return max;
    }
    return 0;
}

int main()
{
   int a,b;
   cin>>a;
   cin>>b;
   if(a>b)
   {
	int i=max_ciclo(a,b);
    cout<<a<<" "<<b<<" "<<i;
   }
   else
   {
	int i=max_ciclo(b,a);
    cout<<a<<" "<<b<<" "<<i;
   }   
   return 0;
}
/* @END_OF_SOURCE_CODE */


/*
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int size;
    int tmp=0;
    cin>>size;
    int * a= new int[size];
    for(int i=0;i<size;i++)
        cin>>a[i];
       
    for(int i=0;i<size-1;i++)
    {
        tmp =a[i+1];
           
        int b = sqrt(pow(a[i]-tmp,2));
        if(b>size)
        {
            cout<<"Not jolly";
            return 0;                               
        }
    }
    if(tmp ==a[size-1])
    {
        cout<<"Jolly";
        return 0;                               
    }
    delete a;
}*/
