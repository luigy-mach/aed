#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;



class image
{
     friend class grafo;
private:
    vector<string> mivec;
    vector<string> vecgi;
    vector<string> vecgr;
    float ** mimatriz;
    public:
    image();
    ~image();
    void llenar_vector(vector<string> vecimg);
    void get_gabor(vector<string> &vecs,vector<string> &vecgi,vector<string> &vecgr);
    float read_distancia(string ai , string ar,string bi , string br);
    void get_matriz(vector<string> &vecgi,vector<string> &vecgr);
    void start();
    float ** get_Matriz_llena();
    void print_matriz();
    void get_distacia(vector<string> &vecs, vector<string> &vecgi, vector<string> &vecgr);
};

#endif // IMAGE_H
