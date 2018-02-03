#ifndef BINARIZACION_H
#define BINARIZACION_H
#include "matrize.h"
#include <fstream>
#include "CImg.h"

using namespace cimg_library;

class binarizacion
{
private:
    string imagename;
    MatrizE<int,256,256> mimatriz;
    int fil,col;
public:
    binarizacion(){};
    void setname(string n){ imagename=n;}
    string getname(){return imagename;}
    void binarizar(string f);
    void print();
    MatrizE<int,256,256>  getMatriz();
    void savePGM(string archivo);
    void load_binarizacion(string file);
    void mostrar_img(string name);
};

#endif // BINARIZACION_H
