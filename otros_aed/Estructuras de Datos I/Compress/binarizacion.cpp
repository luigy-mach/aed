#include "binarizacion.h"

void binarizacion::binarizar(string file)
{
    fil=col=256;
    imagename=file;
    CImg<unsigned char> image(imagename.c_str());
    //image.display();
    unsigned char * vec =image.get_vector();
    int tope=120;
    int cont=0;
    int cont2=0;
    for(int i=0;i<256*256;i++)
     {
         float r=((int)vec[i]*0.3)+((int)vec[(i+(256*256*1))]*0.59)+((int)vec[(i+(256*256*2))]*0.11);
         if(r<tope)
             r=0;
         else
         {
             r=1;
         }
         if(cont<=255)
         {
             if(cont2==256)
             {
                 cont++;
                 cont2=0;
             }
             if(r==1) mimatriz(cont,cont2)=r;
             cont2++;

         }
     }
}

void binarizacion::print()
{
    mimatriz.Print();
}
MatrizE<int,256,256> binarizacion::getMatriz()
{
    return mimatriz;
}
void binarizacion::savePGM(string archivo)
{
    ofstream image(archivo.c_str());
    image<<"P2"<<endl;
    image<<fil<<" "<<col<<endl;
    NodoE<int> ** p;
    for(int i=0;i<256;i++)
    {
        for(int j=0;j<256;j++)
        {
            if(mimatriz.find_fil(i,j,p))
                image<<255<<endl;
            else
            {
                image<<0<<endl;
            }
        }

    }
}
void binarizacion::load_binarizacion(string file)
{
    CImg<unsigned char> image(file.c_str());
    image.save_png("binarizado.png");
}
void binarizacion::mostrar_img(string name)
{
    fil=col=256;
    imagename=name;
    CImg<unsigned char> image(imagename.c_str());
    image.save_png("nuevo.png");
}
