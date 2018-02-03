#ifndef RECORD_H
#define RECORD_H

////////////////////////////////////////////////
#include"word.h"
////////////////////////////////////////////////
#include<string>
#include<vector>
using namespace std;


class Record
{
public:
    std::string word;
    vector< Word > traduccion;
    vector< Word >::iterator it;

public:
    Record(){it=traduccion.begin();}
    Record(std::string _word):word(_word){it=traduccion.begin();}

    //// para objetos
    bool operator==(Record& r);
    bool operator!=(Record& r);
    bool operator<(Record& r);
    bool operator>(Record& r);
    /// para punteros
    bool operator==(Record* r);
    bool operator!=(Record* r);
    bool operator<(Record* r);
    bool operator>(Record* r);
    //otros
    void operator=(Record& r);
    //void operator=(Record* r);
};

#endif // RECORD_H
