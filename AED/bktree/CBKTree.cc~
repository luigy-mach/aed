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

void bktree_query(CBKTree *t, const char * key, int treshold, char **out, int *n)
{
    BKTree *t2 = (BKTree *) t;
    
    MAP_OUT out2;
    
    t2->query(key, treshold, out2);
    
    *n = out2.size();
}

void bktree_delete(CBKTree *t)
{
    BKTree *t2 = (BKTree *) t;
    
    delete t2;
}

} // extern
