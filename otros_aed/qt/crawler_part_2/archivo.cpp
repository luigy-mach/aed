#include "archivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <QString>
#include <fstream>
#include <iostream>
using namespace std;

Archivo::Archivo(int pos)
{
    id=pos;
}
void Archivo::cargar_stopWords()
{
    ifstream file ("/home/luis/qt/crawler_part_2/stop.txt");
    string palabra;
    while(!file.eof())
    {

        file>>palabra;
        stop_words[palabra]=true;

    }
    /*for(auto& x:stop_words )
        cout<<x.first<<endl;*/

}

void Archivo::cargar_vecFrecuencia()
{
    QString direc="/home/luis/qt/crawler_part_2/"+QString::number(this->id)+".txt";

    ifstream file (direc.toStdString().c_str());

    int peso;
    string palabra;
    while(!file.eof())
    {
        file>>peso;
        file>>palabra;
        vec_frecuencia[palabra]=peso;
       // cout<<"llegue"<<endl;
    }
    for(auto& x:vec_frecuencia)
        cout<<x.first<<" "<<x.second<<endl;
}
