/*#include <iostream>
#include<vector>
#include<string>
#include <sstream>
#include <pthread.h>
#include <sstream>
#include <vector>
#include "ImageGray.h"
#include "xtprobeImageDiskXFile.h"

using namespace Torch;
using namespace std;

double comparador(Image *grayimage1 ,Image *grayimage2)
{
   	if(grayimage1->width != grayimage2->width)
		cout<<("Images of different width");

	if(grayimage1->height != grayimage2->height)
		cout<<("Images of different height");

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
string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
int main()
{
}
*/
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <sstream>
#include <vector>
#include "ImageGray.h"
#include "xtprobeImageDiskXFile.h"

using namespace Torch;
using namespace std;
/*
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
*/
double comparador(Image *grayimage1 ,Image *grayimage2)
{
   	if(grayimage1->width != grayimage2->width)
		cout<<("Images of different width")<<endl;

	if(grayimage1->height != grayimage2->height)
		cout<<("Images of different height")<<endl;

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
double** getmatriz(vector<string> &vecgi,vector<string> &vecgr)
{
    double** mimatriz=new double*[vecgi.size()];
    for(unsigned int i=0;i<vecgi.size();i++)
       mimatriz[i]=new double[vecgi.size()];

    ImageDiskXFile * image_file=NULL;
    Image * grayimage1=NULL;
    Image * grayimage2=NULL;
    grayimage1=new ImageGray();
    grayimage2=new ImageGray();

    for(unsigned int i=0;i<vecgi.size();i++)
    {
        for(unsigned int j=i;j<vecgr.size();j++)
        {
            image_file = new xtprobeImageDiskXFile(strdup(vecgi[i].c_str()), "r");
            grayimage1->loadImageXFile(image_file);
            delete image_file;
            image_file = new xtprobeImageDiskXFile(strdup(vecgr[j].c_str()), "r");
            grayimage2->loadImageXFile(image_file);
            delete image_file;
            mimatriz[i][j]=comparador(grayimage1,grayimage2);
        }
    }
    return mimatriz;
}
/*void load_grafo(vector<string> & files, grafo * g)
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
    }*/
     /*pthread_t hebra1;
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
        cout<<endl<<count<<" comparaciones realizadas en "<<timedif<<" segundos"<<endl;*/

//}

int main(int argc , char * argv[])
{
    /*FilesList F(argv[1]);
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

    system("shotwell g1.png &");*/
    vector<string> vecimg;
    vector<string> vecgi;
    vector<string> vecgr;

    ifstream ifsimg("image.txt");
    int i=0;
    char buffer[100];
    while(!ifsimg.eof()&&i<200)
    {
        i++;
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            vecimg.push_back(a);
        }
    }
    i=0;
    ifstream ifsvgi("vecgi.txt");
    while(!ifsvgi.eof()&&i<200)
    {
        i++;
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            vecgi.push_back(a);
        }
    }
    i=0;
    ifstream ifsvgr("vecgr.txt");
    while(!ifsvgr.eof()&&i<200)
    {
        i++;
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            vecgr.push_back(a);
        }
    }
    double ** matriz=getmatriz(vecgi,vecgr);
    for(unsigned int i=0;i<vecgi.size();i++)
    {
        for(unsigned int j=i;j<vecgr.size();j++)
        {
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
    return 0;
}

