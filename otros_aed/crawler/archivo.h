#ifndef ARCHIVO_H
#define ARCHIVO_H


#include "includes.h"
#include "defines.h"


class Archivo
{
    public:

        int id;
        unordered_map<string,int > unor_map_frecuencia;

    public:
        Archivo(int _num_de_archivo);
        void cargar_vecFrecuencia(vector< Archivo* >& _archivos_procesados, unordered_map<string, bool>& _unor_map_stop_words);
        void cargar_vecFrecuencia_busqueda(unordered_map<string, bool>& _unor_map_stop_words);
        bool esta_vacio();

};

#endif // ARCHIVO_H
