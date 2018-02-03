#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class Archivo
{
public:
    int id;
    unordered_map<string,int > vec_frecuencia;
    unordered_map<string, bool> stop_words;
    Archivo(int);
    void cargar_stopWords();
    void cargar_vecFrecuencia();

};

#endif // ARCHIVO_H
