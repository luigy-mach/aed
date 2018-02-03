#include <iostream>
//#include <cv.h>
//#include<highgui.h>
#include <pthread.h>
#include "FilesList.h"
#include "Graficador.h"
#include <sstream>
//#include "CImg.h"

#include "ImageGray.h"
#include "xtprobeImageDiskXFile.h"

using namespace Torch;
using namespace std;

void ShowBar(double porcentaje)
{
    if(porcentaje==-1) porcentaje = 100;
	int tamMax = 58;
	char * Msg = "Completado";
    int i = 0,a = 0, b;
    b = (porcentaje < 10)? 2:3;
        for(i = tamMax+strlen(Msg)+2+b+5; i>=0; --i) putchar('\b'); // vamos al principio de la barrita

    putchar('[');
        for(i = (porcentaje*tamMax)/100; a<i-1; ++a) putchar('=');
        putchar('>');
        for(; a < tamMax; ++a) putchar(' ');
    putchar(']');

    printf("%0.3f%% %s",porcentaje,Msg);
    fflush(stdout);
}

void * mostrarprogreso(void * porcentaje)
{
    double* p = ((double *)porcentaje);
    double r = 0;
    while(r!=-1)
    {
            r=*p;
            ShowBar(r);
    }
}

void * comparsionWorker(void * data)
{

}

void lanzarhilos()
{

}

double comparador(Image *grayimage1 ,Image *grayimage2)
{
   	if(grayimage1->width != grayimage2->width)
		error("Images of different width");

	if(grayimage1->height != grayimage2->height)
		error("Images of different height");

	int n = grayimage1->width * grayimage1->height;

	real mse = 0.0;

	for(int i = 0 ; i < n ; i++)
	{
		real z = (real) (grayimage1->data[i] - grayimage2->data[i]) / 255.0;
		mse += z*z;
	}
	mse /= (real) n;

	return mse;
}

void load_grafo(vector<string> & files, grafo * g)
{
    time_t start,end;
    time (&start);
    int  s = files.size();
    double diff , timedif, count = 0, p = 0, total  = s*s/2+s/2+((s%2)? 1:0);;
    ImageDiskXFile *image_file = NULL;
    Image ** grayimages =  new Image*[s];
    cout<<"Comparando "<<s<<" imagenes ..."<<endl;//<<"en "<<n<<"hilos de ejecucion .."<<endl;
    for(int i = 0 ; i<s;i++)
    {
        image_file = new xtprobeImageDiskXFile(strdup(files[i].c_str()), "r");
        grayimages[i] = new ImageGray();
        grayimages[i]->loadImageXFile(image_file);
        delete image_file;
    }
     pthread_t hebra1;
     pthread_create(&hebra1,0,mostrarprogreso,(void*)(&p));
    for(int i = 0 ; i<s;i++)
        for(int j = i ; j<s;j++)
        {
            diff = comparador(grayimages[i],grayimages[j]);
            g->setady(i,j,diff);
            count ++;
            p = (count/total)*100;
        }
        p=-1;
        delete [] grayimages;
        g->Completar();
        time (&end);
        timedif = difftime (end,start);
        cout<<endl<<count<<" comparaciones realizadas en "<<timedif<<" segundos"<<endl;

}

int main(int argc , char * argv[])
{
    FilesList F(argv[1]);
    if(F.buscarArchivos() == -1) cout<<"error"<<endl;
    vector<string> nodos;
    nodos = *F.getfiles();
    int num ;
    num = 1000;//atoi(argv[2]);
    if(num == -1) num = nodos.size();
    else if(num >nodos.size() ) num = nodos.size();
    vector<string> nodos2(num);
    copy(nodos.begin(),nodos.begin()+num,nodos2.begin());
    grafo a(nodos2);
    load_grafo(nodos2,&a);
    cout<<"Calculando árbol de expansión mínima ..."<<endl;
    grafo * g1 = a.prim1();
    Graficador G(g1,"g1","png");
    cout<<"Graficando ...`" <<endl;
    G.graficar();

    system("shotwell g1.png &");
    return 0;
}
