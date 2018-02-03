#include <QtGui/QApplication>
#include "mainwindow.h"
#include <omp.h>
int main(int argc, char *argv[])
{
    omp_set_num_threads(8);
    #pragma omp parallel for num_threads(8)
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}





/*#include "binarizacion.h"
#include "quadtree.h"
#include <stdlib.h>
#include <QtGui/QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    time_t start,end;
    time (&start);
    cout<<"Empezando a binarizar"<<endl;
    binarizacion * bin =new binarizacion();
    string name="lena.jpg";
    bin->binarizar(name);
    //bin->print();
    cout<<"Binarizacion de "<<name.c_str()<<endl;
    cout<<"Guardando Imagen Binarizada"<<endl;
    bin->savePGM();
    cout<<"Graficando Imagen Binarizada"<<endl;
    bin->load_binarizacion();
    cout<<"Iniciando Quadtree"<<endl;
    Quadtree<int> quad(255,255);
    quad.setMat(bin->getMatriz());
    quad.setH(255);
    quad.setW(255);
    cout<<"Subdivisiones del Quadtree"<<endl;
    quad.subdividir(quad.mRoot);
    cout<<"Compresion de Quadtree a zip.txt"<<endl;
    quad.ptam(quad.mRoot,"zip.txt");
    cout<<"Descomprension de zip.txt a Quadtree"<<endl;
    quad.descomprimir("zip.txt");
    cout<<"Guardando Imagen Descomprimida del Quadtree"<<endl;
    quad.save_des("unzip.txt");
    cout<<"Mostrando Imagen Descomprimida"<<endl;
    bin->mostrar_img("unzip.txt");
    time (&end);
    double timedif = difftime (end,start);
    cout<<"Tiempo de Ejecucion "<<timedif<<endl;

}
*/
