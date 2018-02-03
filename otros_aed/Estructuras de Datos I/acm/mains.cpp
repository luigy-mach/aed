#include <QtGui/QApplication>
#include "mainwindow.h"
#include<iostream>
#include"math.h"
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



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int i=max_ciclo(1,10);
    cout<<1<<" "<<10<<" "<<i;
    return a.exec();
}
