#ifndef BKTREE_H
#define BKTREE_H

#include <map>
#include <utility>
#include <string>

#include "BKNode.h"


typedef typename std::string STRING; 


class BKTree
{
private:
    BKNode* root;

public:
    BKTree () : root(0) {}
    ~BKTree() {delete root;}

    void add(const std::pair <STRING, int> & _term);
    void query(const STRING & searchObject, int threshold, std::map<int, int> & collected);
};

#endif // BKTREE_H
