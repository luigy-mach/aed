#ifndef CRAWLER_H
#define CRAWLER_H
#include <unordered_map>
#include <utility>
#include <queue>


using namespace std;

class compara
{
    public:

        bool operator()(pair<int,int> n1,pair<int,int> n2)
        {

        if(n1.second>n2.second)
        return true;
        else
        return false;

        }
};

typedef pair<int, int > peso;

class crawler
{
    friend class compara;
public:
    int numero_archivos;
    priority_queue<pair<int,int >,vector<pair<int, int > >,compara> cercania;


    crawler(int num);

    vector<archivo> lista;
    


};

#endif // CRAWLER_H
