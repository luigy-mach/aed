#include "grafo.h"

grafo::grafo()
{
    pimg= new image();
}

/*grafo::~grafo()
{

}
vector< vector<float> > grafo::prim()
{
    cout<<"entraprim"<<endl;
    const float INF = 1000.0;
    int cn= filas;
    cout<<"filas "<<cn<<endl;
    vector< vector<float> > arbol(cn);
    vector<int> markedLines;
    vector<int> :: iterator itVec;
    for(int i = 0; i < cn; i++)
        arbol[i] = vector<float> (cn, INF);

    int padre = 0;
    int hijo = 0;
    while(markedLines.size() + 1 < cn){
        padre = hijo;
        markedLines.push_back(padre);
        for(int i = 0; i < cn; i++)
            mygraf[i][padre] = INF;

        float min = INF;
        for(itVec = markedLines.begin(); itVec != markedLines.end(); itVec++)
            for(int i = 0; i < cn; i++)
                if(min > mygraf[*itVec][i]){
                    min = mygraf[*itVec][i];
                    padre = *itVec;
                    hijo = i;
                }
        arbol[padre][hijo] = min;
        arbol[hijo][padre] = min;
    }
    return arbol;
}

void grafo::setgrafo( float** a)
{
    mygraf = a;
}
float ** grafo::getgrago()
{
   return mygraf;
}

int grafo::get_filas(){ return filas;}
string grafo::changeimg(string img)
{
    string nuevo;
    for(int i=0;i<img.size();i++)
        if(img[i]!='.')
            nuevo.push_back(img[i]);
         else
            break;
    string rpta = "convert " + img + " " +nuevo+".png";
    string nuevo2= nuevo+".png";
    system(rpta.c_str());
    return nuevo2;
}

 void grafo::setVector(vector<string> & v)
 {
     this->pimg->llenar_vector(v);
     for(int i=0;i<v.size();i++)
     {
         string a=changeimg(v[i]);
         imgconv.push_back(a);
     }

     this->pimg->start();
     cout<<"empieza!!!"<<endl;
     //pimg->print_matriz();
 }

 vector< vector<float> > grafo::Kruskal()
 {

         const float INF = 1000.0;
         int cn=filas; //cantidad de nodos

             vector< vector<float> > arbol(cn);
             vector<int> pertenece(cn); // indica a que arbol pertenece el nodo

             for(int i = 0; i < cn; i++){
                 arbol[i] = vector<float> (cn, INF);
                 pertenece[i] = i;
             }

             int nodoA;
             int nodoB;
             int arcos = 1;
             while(arcos < cn){
                 // Encontrar  el arco minimo que no forma ciclo y guardar los nodos y la distancia.
                 float min = INF;
                 for(int i = 0; i < cn; i++)
                     for(int j = 0; j < cn; j++)
                         if(min > mygraf[i][j] && pertenece[i] != pertenece[j]){
                             min = mygraf[i][j];
                             nodoA = i;
                             nodoB = j;
                         }

                 // Si los nodos no pertenecen al mismo arbol agrego el arco al arbol minimo.
                 if(pertenece[nodoA] != pertenece[nodoB]){
                     arbol[nodoA][nodoB] = min;
                     arbol[nodoB][nodoA] = min;

                     // Todos los nodos del arbol del nodoB ahora pertenecen al arbol del nodoA.
                         int temp = pertenece[nodoB];
                         pertenece[nodoB] = pertenece[nodoA];
                         for(int k = 0; k < cn; k++)
                                 if(pertenece[k] == temp)
                                         pertenece[k] = pertenece[nodoA];

                     arcos++;
                 }
             }
             return arbol;



 }*/
