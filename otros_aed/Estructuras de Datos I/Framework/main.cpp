#include <QtGui/QApplication>
#include "mainwindow.h"
#include "nodo.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*Nodo<int> A(4,1);
    int v[]={1,2,3,4};
    A.setDato(v);
    for(int i=0;i<4;i++)
        cout<<A.getDato()[i]<<endl;*/
    return a.exec();
}
