#include "image.h"
/*include <iostream>
//#include <queue>
//#include <algorithm>
#include <cstdio>
#include "ImageGray.h"
#include "xtprobeImageDiskXFile.h"

using namespace Torch;
using namespace std;*/

#include <iostream>
//#include <cv.h>
//#include<highgui.h>
#include <pthread.h>
//#include "FileList.h"
//#include "Graficador.h"
#include <sstream>
//#include "CImg.h"
#include <vector>
#include "ImageGray.h"
#include "xtprobeImageDiskXFile.h"

using namespace Torch;
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, float> iF;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iF> viF;



using namespace std;
image::image()
{
}
void image::llenar_vector(vector<string> vecimg)
{
    this->mivec=vecimg;

}


void image::get_distacia(vector<string> &vecs, vector<string> &vecgi, vector<string> &vecgr)
{
  /*  ImageDiskXFile *image_file = NULL;
    Image ** grayimages =  new Image*[1];
    cout<<"Comparando "<<1<<" imagenes ..."<<endl;//<<"en "<<n<<"hilos de ejecucion .."<<endl;
    for(int i = 0 ; i<1;i++)
    {
        image_file = new xtprobeImageDiskXFile(strdup(vecs[0].c_str()), "r");
        grayimages[i] = new ImageGray();
        grayimages[i]->loadImageXFile(image_file);
        delete image_file;
    }*/
    /*bool verbose=true;
    ImageDiskXFile *image_file = NULL;
	Image *grayimage1 = new ImageGray();
	Image *grayimage2 = new ImageGray();

	//grayimage1 = new ImageGray();
	//grayimage1->setBOption("verbose", verbose);

	//grayimage2 = new ImageGray();
	//grayimage2->setBOption("verbose", verbose);

	image_file = new xtprobeImageDiskXFile(strdup((vecgi[0]).c_str()), "r");
	grayimage1->loadImageXFile(image_file);
	delete image_file;

	image_file = new xtprobeImageDiskXFile(strdup((vecgr[0]).c_str()), "r");
	grayimage2->loadImageXFile(image_file);
	delete image_file;

	if(verbose)
	{
		print("Image 1 info:\n");
		print("   width = %d\n", grayimage1->width);
		print("   height = %d\n", grayimage1->height);
		print("   format = %s (%d)\n", grayimage1->coding, grayimage1->n_planes);
		print("Image 2 info:\n");
		print("   width = %d\n", grayimage2->width);
		print("   height = %d\n", grayimage2->height);
		print("   format = %s (%d)\n", grayimage2->coding, grayimage2->n_planes);
	}*/
}
/*
void load_grafo(vector<string> & files, grafo * g)
{
    //time_t start,end;
    //ti/me (&start);
    //int  s = files.size();
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

*/






void image::get_gabor(vector<string> &vecs, vector<string> &vecgi, vector<string> &vecgr)
{
    /*for(int i=0;i<vecs.size();i++)
    {
        string a=vecs[i];
        string b="./gabor2d ";
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
        vecgi.push_back(img1);
        string mv="mv ";
        string mvsi=mv+b+" "+pg;
        system(mvsi.c_str());

        m.setNum(i);
        a=m.toStdString();
        b="filter_r.pgm";
        c="filter_r";
        pg=c+"_"+a+".pgm";
        string img2=pg;
        vecgr.push_back(img2);
        mv="mv ";
        string mvsr=mv+b+" "+pg;
        system(mvsr.c_str());
        system("rm gabor_i.pgm");
        system("rm gabor_r.pgm");

    }*/
    int i=0;
    int j=0;
    char buffer[100];
    ifstream ifsvgi("vecgi.txt");
    while(!ifsvgi.eof()&&i<200)
    {
        i++;
        ifsvgi.getline(buffer,100);
        ifsvgi.getline(buffer,100);
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            vecgi.push_back(a);

        }
    }
    ifstream ifsvgr("vecgr.txt");
    while(!ifsvgr.eof()&&j<200)
    {
        j++;
        ifsvgr.getline(buffer,100);
        ifsvgr.getline(buffer,100);
        if(!std::string(buffer).empty())
        {
            string a=buffer;
            cout<<buffer<<endl;
            vecgr.push_back(a);
        }
    }

}
float image::read_distancia(string ai, string ar, string bi, string br)
{
    string ais="./mimagediff "+ai+" "+bi;
    cout<<ais.c_str()<<endl;
    system(ais.c_str());
    ifstream ifs1("fichero.txt");
    char buffer1[100];
    ifs1.getline(buffer1,100,' ');
    ifs1.getline(buffer1,100);
    //cout<<buffer<<endl;
    float fais = atof(buffer1);
    string ars="./mimagediff "+ar+" "+br;
    cout<<ars.c_str()<<endl;
    system(ars.c_str());
    ifstream ifs2("fichero.txt");
    char buffer2[100];
    ifs2.getline(buffer2,100,' ');
    ifs2.getline(buffer2,100);
    //cout<<buffer<<endl;
    float fars = atof(buffer2);
    cout<<"Float leido: fais  ->  "<<fais<<endl;
    cout<<"Float leido: fars  ->  "<<fars<<endl;
    float c=((fais+fars)/2.0000000);
    //float c=(fais+fars)/2.00;
    cout<<"Resultado a guardar: c  ->  "<<c<<endl;
    return c;
}

priority_queue<pair<double,ii> > minHeap;
vi estado;

vector<viF> listaAdj;

        void process(int val)
        {
                estado[val]=1;
                for(unsigned int i=0;i<listaAdj[val].size();i++)
                {
                        pair<int,double>v = listaAdj[val][i];
                        if(!estado[v.first])
                        {
                                minHeap.push(make_pair(-v.second,ii(-val ,-v.first)));
                        }
                }
        }


        string changeimg(string img)
        {
            string nuevo;
            for(unsigned int i=0;i<img.size();i++)
                if(img[i]!='.')
                    nuevo.push_back(img[i]);
                 else
                    break;
            string rpta = "convert " + img + " " +nuevo+".png";
            string nuevo2= nuevo+".png";
            system(rpta.c_str());
            return nuevo2;
        }


void image::get_matriz(vector<string> &vecgi,vector<string> &vecgr)
{
    double cost=0;
    //cout<<"empieza!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
    ofstream file("imagen3.dot");
     file<<"graph A {"<<endl;

    int vert, u,v ;
//    int edge;
    float weight;
    vert =vecgr.size();
    listaAdj.assign(vert, viF());

//    int edge =25;
    for(unsigned int i=0;i<vecgr.size();i++)
    {
        file<<i<<"[image= \""<<changeimg(this->mivec[i])<<"\"]"<<endl;
       // cout<<"empieza!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!2222"<<endl;
        for(unsigned int j=0;j<vecgr.size();j++)
        {


            //for(int )


                         cout<<"bucle"<<endl;
                        //scanf("%d %d", &vert, &edge);


                        //vector<pair<float, ii> > edgeList;
                        //for(int h=0;h<edge;h++)
                        //{
                            u= i;
                            v= j;
                            weight=read_distancia(vecgi[i],vecgr[i],vecgi[j],vecgr[j]);
                            if(i==j)
                            {

                               float inf=1000000;
                               weight=inf;

                            }
                            listaAdj[u].push_back(iF(v, weight));
                            listaAdj[v].push_back(iF(u, weight));
                        //}

                        //cout<<"y el costo es: "<<cost<<endl;
        }
    }
    estado.assign(vert,0);
    process(0);
    while(!minHeap.empty())
    {
            pair<double,ii> front = minHeap.top();
            minHeap.pop();
            u = -front.second.second , weight = -front.first;
            if(!estado[u])
            {
                    cost+= weight ;
                    process(u);

                   // cout<<"("<<-front.first<<","<<-front.second.first<<","<<-front.second.second<<")"<<endl;
                    file<<-front.second.first<<"--"<<-front.second.second<<"[len="<<(-front.first)*900<<","<<"label= \""<<-front.first<<"\"];"<<endl;
            }

    }


    cout<<"y el costo total es: "<<cost<<endl;
    file <<"}"<<endl;
    file.close();
    system("neato -Tps imagen3.dot -o nuevo3.ps");
}



void image::start()
{


    this->get_gabor(mivec,vecgi,vecgr);
    get_matriz(vecgi,vecgr);
    //cout<<"empieza!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
}

float ** image::get_Matriz_llena()
{
    return this->mimatriz;
}
image::~image()
{
    for(unsigned int i=0;i<this->vecgi.size();i++)
    {
        string rm="rm ";
        string sys=rm+vecgi[i];
        system(sys.c_str());
        sys=rm+vecgr[i];
        system(sys.c_str());
    }
    //return;
}

void image::print_matriz()
{
    cout<<"Imprimiendo Matriz: "<<endl;
    for(unsigned int i=0;i<vecgi.size();i++)
    {
        for(unsigned int j=0;j<vecgr.size();j++)
        {
            cout<<"i:"<<i<<" j:"<<j<<" -> "<<"[ "<<mimatriz[i][j]<<" ]"<<"   ";
        }
        cout<<endl;
    }
}
