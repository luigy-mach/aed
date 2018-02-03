#ifndef CRAWLER_H
#define CRAWLER_H
#include <unordered_map>
#include <utility>
#include <queue>

#include "includes.h"
#include "archivo.h"

using namespace std;


//**************************PARA EL PRIORITY_QUEUE ***************************************
class compara
{
    public:

        bool operator()(pair<int,double> n1,pair<int,double> n2)
        {

        if(n1.second<n2.second)
            return true;
        else
            return false;
        }

};
//***************************************************************************************

typedef pair<int, int > peso;

class Crawler
{
    public:
        int m_numero_archivos;
        priority_queue<pair<int,double >,vector<pair<int, int > >,compara > mas_cercanos;

        unordered_map<string, bool> unor_map_stop_words;

        vector< Archivo* > v_archivos_procesados;

        friend class compara;
        friend class Archivo;

    public:
        Crawler();
        void set_num_archivos(int _num);
        void cargar_stop_words();
        double distancia_vectoresed_map_coseno(unordered_map<string, int>& a, unordered_map<string, int>& b);
        double distancia_vectoresed_map_euclidia(unordered_map<string, int>& a, unordered_map<string, int>& b);
        void llenar_mas_cercanos(Archivo* _principal_main);
        void imprimir_priority();
        void get_priority_qt();

};

#endif // CRAWLER_H
