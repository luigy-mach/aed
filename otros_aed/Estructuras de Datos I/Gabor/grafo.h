#ifndef GRAFO_H
#define GRAFO_H
#include <stdio.h>
#include <iostream>
//#include <QString>
#include <string>
#include <fstream>
#include <vector>
#include "image.h"
using namespace std;

class grafo
{
   friend class gradicador;

   private:
        float ** mygraf;
        int filas;
        int columnas;
        image * pimg;
        vector<string> imgconv;
   public:
        grafo();
        vector< vector<float> > prim();
        vector< vector<float> > Kruskal();
        void setgrafo( float** );
        float ** getgrago( );
        int get_filas();
        string changeimg(string img);
        void setVector(vector<string> & v);


};

#endif // GRAFO_H
