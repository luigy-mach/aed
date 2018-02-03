#include "CBKTree.h"
#include "BKTree.h"

extern "C" {

CBKTree * bktree_new()
{
    BKTree *t = new BKTree;

    return (CBKTree *) t;
}

void bktree_add(CBKTree *t, const char * key, int value)
{
    BKTree *t2 = (BKTree *) t;
    
    t2->add(PAIR_S_I(key, value));
}

void bktree_query(CBKTree *t, const char * key, int treshold, int **out, int *n)
{
    BKTree *t2 = (BKTree *) t;
    
    MAP_OUT out2;
    
    t2->query(key, treshold, out2);
    
    *n = out2.size();

    *out = new int[*n];
    int * asd = *out;

    MAP_OUT::iterator it = out2.begin();

    while (it != out2.end())
    {
        *asd = it->first;

        ++it; ++asd;
    }
}

void bktree_delete(CBKTree *t)
{
    BKTree *t2 = (BKTree *) t;
    
    delete t2;
}

} // extern
