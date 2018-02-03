#include "crawler.h"
#include <fstream>
#include <iostream>


using namespace std;

Crawler::Crawler()
{

}

void Crawler::set_num_archivos(int _num)
{
    this->m_numero_archivos=_num;
}

void Crawler::cargar_stop_words()
{

    ifstream file (ARCHIVO_STOP_WORDS);
    string palabra;
    while(!file.eof())
    {
        file>>palabra;
        unor_map_stop_words[palabra]=true;
    }
    /*for(auto& x:unor_map_stop_words )
        cout<<x.first<<endl;*/

}





double Crawler::distancia_vectoresed_map_coseno(unordered_map<string, int>& a, unordered_map<string, int>& b)
{
    size_t tam_a = a.size();
    size_t tam_b = b.size();
    //cout<<"tam_a"<<tam_a<<"<<<<<<<<"<<endl;
    //cout<<"tam_b"<<tam_b<<"<<<<<<<<"<<endl;
    //tam_a<tam_b? unordered_map<string,int>& aa=a : unordered_map<string,int>& aa=b;0

    double producto_punto=0.0;
    if(tam_a<tam_b){
        for(auto& it_bulcle: b){
            auto it_1 = a.find(it_bulcle.first);
            auto it_2 = b.find(it_bulcle.first);
            if( it_1!=b.end() && it_2!=b.end()){
                if(it_1->first==it_2->first){
                    producto_punto+=(it_1->second * it_2->second);
                    //cout<<"|"<<it_1->second<<"."<<it_2->second<<"|->>111>>"<<producto_punto<<endl;
                }

            }
        }
    }
    else{
        for(auto& it_bulcle: a){
            auto it_1 = a.find(it_bulcle.first);
            auto it_2 = b.find(it_bulcle.first);
            if( it_1!=a.end() && it_2!=a.end()){
                if(it_1->first==it_2->first){
                    producto_punto+=(it_1->second * it_2->second);
                    //cout<<"|"<<it_1->second<<"."<<it_2->second<<"|->>222>>"<<producto_punto<<endl;
                }

            }
        }

    }
    producto_punto=sqrt(producto_punto);

    double modulo_a=0.0;
    double modulo_b=0.0;
    for(auto& x: a)
        modulo_a+=pow(x.second,2);

    for(auto& y: b)
        modulo_b+=pow(y.second,2);

    /*cout<<"|a|"<<modulo_a<<endl;
    cout<<"|b|"<<modulo_b<<endl;
     cout<<"|a.b|"<<producto_punto<<endl;*/

    return producto_punto/(modulo_a*modulo_b);
}


double Crawler::distancia_vectoresed_map_euclidia(unordered_map<string, int>& a, unordered_map<string, int>& b)
{
    size_t tam_a = a.size();
    size_t tam_b = b.size();
    //cout<<"tam_a"<<tam_a<<"<<<<<<<<"<<endl;
    //cout<<"tam_b"<<tam_b<<"<<<<<<<<"<<endl;
    //tam_a<tam_b? unordered_map<string,int>& aa=a : unordered_map<string,int>& aa=b;0

    double producto_punto=0.0;
    if(tam_a<tam_b){
        for(auto& it_bulcle: b){
            auto it_1 = a.find(it_bulcle.first);
            auto it_2 = b.find(it_bulcle.first);
            if( it_1!=b.end() && it_2!=b.end()){
                if(it_1->first==it_2->first){
                    producto_punto+= pow((it_1->second - it_2->second),2);

                    //cout<<"|"<<it_1->second<<"."<<it_2->second<<"|->>111>>"<<producto_punto<<endl;
                }

            }
        }
    }
    else{
        for(auto& it_bulcle: a){
            auto it_1 = a.find(it_bulcle.first);
            auto it_2 = b.find(it_bulcle.first);
            if( it_1!=a.end() && it_2!=a.end()){
                if(it_1->first==it_2->first){
                    producto_punto+= pow((it_1->second - it_2->second),2);
                    //cout<<"|"<<it_1->second<<"."<<it_2->second<<"|->>222>>"<<producto_punto<<endl;
                }

            }
        }

    }
    producto_punto=sqrt(producto_punto);

    return producto_punto;
}



void Crawler::llenar_mas_cercanos(Archivo *_principal_main)
{

    vector<Archivo*>::iterator it;
    for(it=this->v_archivos_procesados.begin();it<v_archivos_procesados.end();it++)
    {
        pair <int,double> foo;
        double dis=distancia_vectoresed_map_euclidia(_principal_main->unor_map_frecuencia,(*it)->unor_map_frecuencia);
        foo = make_pair ((*it)->id,dis);
        /*cout<<"--------%%%%%%%%%%%-------"<<endl;
        cout<<foo.first<<" "<<foo.second<<endl;
        cout<<"--------%%%%%%%%%%%-------"<<endl;*/
        this->mas_cercanos.push(foo);
      }

}

void Crawler::imprimir_priority()
{
           cout<<"--------%%%%%imprimir_priority_queue%%%%%%-------"<<endl;
    while(!mas_cercanos.empty())
   {
       cout<<mas_cercanos.top().first<<".html"<<endl;
       mas_cercanos.pop();

   }

          cout<<"--------%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%-------"<<endl;
}



/*
vector<pair<int,double>>& Crawler::get_priority_qt()
{
       return this->mas_cercanos;
}

*/








