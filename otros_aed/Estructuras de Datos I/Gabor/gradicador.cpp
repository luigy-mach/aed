#include "gradicador.h"

gradicador::gradicador()
{
    grafoClase= new grafo();
}
/* gradicador:: gradicador ( vector<string> & a)
{

    grafoClase= new grafo();
    grafoClase->setVector(a);

}

gradicador::~gradicador();
{

}*/
void gradicador::execute()
{
    /*grafoClase->filas = this->grafoClase->pimg->vecgi.size();
    cout<<grafoClase->filas;
    grafoClase->setgrafo(this->grafoClase->pimg->get_Matriz_llena());
    cout<<"  31252"<<endl;
        grafoClase->Kruskal();
         cout<<"  end prim"<<endl;
        const float INF = 1000.0;
        ofstream file("imagen3.dot");
        file<<"graph A {"<<endl;
        for(int i=0;i<grafoClase->get_filas();i++)
        {

                file<<i<<"[image= \""<< grafoClase->imgconv[i]<<"\"]"<<endl;
                for(int j=i;j< grafoClase->get_filas();j++)
                {
                    if( grafoClase->getgrago()[i][j]!=INF )
                    {
                        file<<i<<"--"<<j<<"[len="<<(grafoClase->getgrago()[i][j])*10<<","<<"label= \""<< (grafoClase->getgrago()[i][j])<<"\"];"<<endl;
                    }
                }
        }
        file <<"}"<<endl;
        file.close();
        system("neato -Tps imagen3.dot -o nuevo3.ps");*/

}
