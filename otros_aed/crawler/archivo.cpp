#include "archivo.h"

Archivo::Archivo(int _num_de_archivo)
{
    id=_num_de_archivo;
}

void Archivo::cargar_vecFrecuencia(vector< Archivo* >& _archivos_procesados, unordered_map<string, bool>& _unor_map_stop_words)
{
    if(esta_vacio())
        return;
    QString direc=UBICACION_TXT;
            direc+=QString::number(this->id)+".txt";

    ifstream file (direc.toStdString().c_str());

    int peso=0;
    string palabra="";
    while(!file.eof())
    {
        file>>peso;
        file>>palabra;
        auto it = _unor_map_stop_words.find(palabra);
        //unordered_map<string,bool>::const_iterator it=unor_map_stop_words.find(palabra);
        if(it==_unor_map_stop_words.end())
            {

            unor_map_frecuencia[palabra]=peso;
            //cout<<unor_map_frecuencia[palabra]<<endl;
            }
    }
    //cout<<"------------------------------"<<endl;

    _archivos_procesados.push_back(this);

    /*for(auto& x:unor_map_frecuencia)
        cout<<x.first<<" "<<x.second<<endl;*/
}


void Archivo::cargar_vecFrecuencia_busqueda( unordered_map<string, bool>& _unor_map_stop_words)
{
    QString direc=UBICACION_TXT;
            direc+=QString::number(this->id)+".txt";

    ifstream file (direc.toStdString().c_str());

    int peso;
    string palabra;

    while(!file.eof())
    {
        file>>peso;
        file>>palabra;
        //unordered_map<string,bool>::const_iterator it=unor_map_stop_words.find(palabra);
        auto it = _unor_map_stop_words.find(palabra);
        if(it==_unor_map_stop_words.end())
            {
                unor_map_frecuencia[palabra]=peso;

                cout<<unor_map_frecuencia[palabra]<<endl;
            }
    }
    //cout<<"------------------------------"<<endl;

    /*for(auto& x:unor_map_frecuencia)
        cout<<x.first<<" "<<x.second<<endl;*/
}



//***********************optimizar_BEBA*******************
bool Archivo::esta_vacio()
{
    QString direc=UBICACION;
            direc+=QString::number(this->id)+".txt";

    ifstream in(direc.toStdString().c_str());
        if(in.is_open())
        {
            in.seekg(0,ios::end);
            size_t size = in.tellg();
            if( size == 0)
            {
              return true;
            }
        }

    return false;
}
