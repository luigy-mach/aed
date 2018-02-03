/*#include <stdio.h>
#include <iostream>
//#include <QString>
#include <fstream>
#include "image.h"
#include "gradicador.h"
#include <string>
#include <stdlib.h>
using namespace std;

sdsdds main000000()
{*/
   /* vector<string> images;
    //vector<string> vecgi;
    //vector<string> vecgr;
    ifstream ifsimg("image.txt");

    int i=0;
    char buffer[100];
    while(!ifsimg.eof()&&i<200)
    {
        i++;
        ifsimg.getline(buffer,100);
        ifsimg.getline(buffer,100);
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            images.push_back(a);

        }
    }
    gradicador * dot = new gradicador(images);
*/
//}
    /*system("ls images/ > image.txt");
    ifstream ifs("image.txt");
    ofstream vecgi("vecgi.txt");
    ofstream vecgr("vecgr.txt");
    char buffer[100];
    while(!ifs.eof())
    {
        ifs.getline(buffer,100);
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            images.push_back(a);
        }
    }
    for(int i=0;i<images.size();i++)
    {
        cout<<"Estamos en la imegen ->"<<i<<"   "<<endl;
        string a=images[i];
        string b="./gabor2d images/";
        string c=b+a;
        cout<<c<<endl;
        system(c.c_str());

        QString m;
        m.setNum(i);
        a=m.toStdString();
        b="filter_i.pgm";
        c="filter_i";
        string pg=c+"_"+a+".pgm";
        string img1=pg;
        vecgi<<img1<<endl;
        string mv="mv ";
        string mvsi=mv+b+" "+pg;
        system(mvsi.c_str());

        m.setNum(i);
        a=m.toStdString();
        b="filter_r.pgm";
        c="filter_r";
        pg=c+"_"+a+".pgm";
        string img2=pg;
        vecgr<<img2<<endl;
        mv="mv ";
        string mvsr=mv+b+" "+pg;
        system(mvsr.c_str());
        system("rm gabor_i.pgm");
        system("rm gabor_r.pgm");
    }


   }*/
/*system("tree>image.txt");
ifstream ifs("image.txt");
ofstream ofs("prueba.txt");
char buffer[100];
ifs.getline(buffer,100);
while(!ifs.eof())
{
    ifs.getline(buffer,100);
    string a;
    for(int i=0;i<100;i++)
    {
        if(buffer[i]!='─'&&buffer[i]!='\0'&&buffer[i]!='├')
            a.push_back(buffer[i]);
    }
    ofs<<a<<endl;
}
//vector<string> vecimg;
//vector<string> vecgi;
//vector<string> vecgr;
for(int i=4;i<85;i++)
{
    QString m;
    m.setNum(i);

    string a= "img"+m.toStdString()+".pgm";
    vecimg.push_back(a);
}

// gradicador * dot = new gradicador(vecimg);
// dot->execute();*/




    /*for(int i=0;i<subdirectorios.size();i++)
    {
        QString num;
        num.setNum(i);
        string m="ls images/"+subdirectorios[i]+"/ > image"+2+".txt";
        cout<<m<<endl;
        system(m.c_str());
        ifstream ifs2("image2.txt");
        while(!ifs2.eof())
        {
            ifs2.getline(buffer,100);
            cout<<buffer<<endl;
            if(!std::string(buffer).empty())
            {
                string a=buffer;
                cout<<buffer<<endl;
                subdirectorios2.push_back(a);
            }
        }
    }
    for(int i=0;i<subdirectorios.size()-1;i++)
    {
        for(int j=0;j<subdirectorios2.size()-1;j++)
        {
            string m="ls images/"+subdirectorios[i]+"/"+subdirectorios2[j]+"/ > image3.txt";
            cout<<m<<endl;
            system(m.c_str());
            ifstream ifs3("image3.txt");
            while(!ifs3.eof())
            {
                ifs3.getline(buffer,100);
                cout<<buffer<<endl;
                if(!std::string(buffer).empty())
                {
                    string a=buffer;
                    images.push_back(a);

                }
            }
        }
    }
*/
