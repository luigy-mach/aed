#ifndef GRADICADOR_H
#define GRADICADOR_H
#include "grafo.h"
#include <vector>

class gradicador
{
    private:
        grafo * grafoClase;
    public:
        gradicador();
        //~gradicador();
        gradicador(vector<string> & a);
        void execute();
};

#endif // GRADICADOR_H
