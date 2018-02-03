#ifndef COMPRENSOR_H
#define COMPRENSOR_H
#include "quadtree.h"
#include "binarizacion.h"
#include <fstream>
#include <vector>

using namespace std;

class MainWindow;

class Comprensor
{
    friend class MainWindow;
    private:
       binarizacion * bina;
       Quadtree<int> * quadt;
       string originalFile;
       string bcimgFile;
       string compresFile;
       string bmyFile;
    public:
        Comprensor()
        {
            bina= new binarizacion();
            quadt = new Quadtree<int>(256,256);
        }
        ~Comprensor()
        {
            delete bina;
            delete quadt;
        }

        void setOriFile(string a ){ originalFile =a;}
        void setBcimgFile(string b ){ bcimgFile=b;}
        void setCompFile(string c){compresFile=c;}
        void setbmyFle(string d){bmyFile=d;}
        void save_cimg_bin(){bina->savePGM(bcimgFile);}
        void binarisar(){ bina->binarizar(originalFile);}
        void showBin(){ bina->load_binarizacion(bcimgFile);}
        void save_comp(NodoQ<int> * & node)
        {
                ofstream file(compresFile.c_str());
                file<<quadt->getH()<<endl;
                comprimir(node);
        }
        void comprimir(NodoQ<int> * & node)
        {
                ofstream file(compresFile.c_str(),ios::app);
                if(node->getKey()==1)
                {
                        for(int i=0;i<4;i++)
                                file<<node->dom[i]<<"#";
                        file<<node->getKey()<<"#";
                        file<<endl;
                }
                if(node->getKey()==-1)
                {
                        for(int k=0;k<4;k++)
                        {
                            comprimir(node->hij[k]);
                        }
                }
        }

        void descomprimir()
        {
                string size;
                ifstream file(compresFile.c_str());
                getline(file,size);
                int tam = atoi(size.c_str());

                    vector<string> vs;
                    vector<vector<int> > vi;
                    while(!file.eof())
                    {
                           string b;

                           getline(file,b);
                           vs.push_back(b);
                           vector<int> vec;
                           string val;
                           for(int i=0;i<b.size();i++)
                           {
                               if(b[i]!='#')
                                    val+=b[i];
                               else
                               {
                                   int v = atoi(val.c_str());
                                   vec.push_back(v);
                                   val.clear();
                               }

                            }
                           vi.push_back(vec);
                     }
                    for(int k=0;k<vi.size()-1;k++)
                    {
                        for(int i=vi[k][0]; i<=vi[k][2];i++)
                              for(int j=vi[k][1];j<=vi[k][3];j++)
                                    quadt->mymat(i,j)=vi[k][4];
                    }
        }

        void save_des()
        {
            NodoE<int> ** p;
            ofstream img(bmyFile.c_str());
            img<<"P2"<<endl;
            img<<quadt->weight+1<<" "<<quadt->weight+1<<endl;
            for(int i=0;i<=quadt->weight;i++)
                for(int j=0;j<=quadt->weight;j++)
                {
                    if(quadt->mymat.find_col(i,j,p))
                        img<<255<<endl;
                    else
                        img<<0<<endl;
                }

        }
};

#endif // COMPRENSOR_H
