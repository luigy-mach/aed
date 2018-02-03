#ifndef BKNODE_H
#define BKNODE_H

#include <cassert>

#include <map>
#include <utility>
#include <string>

#include "LevenshteinDistance.h"
class BKNode;

typedef std::string STRING; 
typedef std::map<int, int> MAP_OUT;
typedef typename std::map<int, int>::iterator IT_MAP_OUT;

typedef std::pair <STRING, int> PAIR_S_I; 


typedef std::pair <int, BKNode* > PAIR_I_PBK; 

typedef std::map<int, BKNode*> MAP_CHILDEN;
typedef typename std::map<int, BKNode*>::const_iterator IT_CHILDREN;


class BKNode
{
private:    
    MAP_CHILDEN children; //hijos
    PAIR_S_I term; // Palabra y posición

public:
    BKNode( const PAIR_S_I & _term) : children(), term(_term) {}
    ~BKNode();

    void add( const PAIR_S_I & _term);
    void query( const STRING & word, int distance, MAP_OUT & collected) const;
};

#endif // BKNODE_H
