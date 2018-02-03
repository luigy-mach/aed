#ifndef BKTREE_H
#define BKTREE_H

#include <map>
#include <utility>
#include <string>

#include "BKNode.h"


typedef typename std::string STRING; 
typedef std::map<int, int> MAP_OUT;
typedef std::pair <STRING, int> PAIR_S_I; 


class BKTree
{
private:
    BKNode* root;

public:
    BKTree () : root(0) {}
    ~BKTree() {delete root;}

    void add( const PAIR_S_I & _term);
    void query( const STRING & searchObject, int threshold, MAP_OUT & collected) const;
};

#endif // BKTREE_H
