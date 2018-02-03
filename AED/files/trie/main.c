#include <stdio.h>
#include <stdlib.h>

#include "trie.h"
 
int main()
{
    trieNode_t *root;
    printf("Trie Example\n");
     
    /*Create a trie*/
    TrieCreate(&root);
     
    TrieAdd(&root, "andrew", 1);
    TrieAdd(&root, "tina", 2);
    TrieAdd(&root, "argo", 3);
    TrieAdd(&root, "timor", 5);
    TrieRemove(&root, "tim");
    TrieAdd(&root, "tim", 6);
    TrieRemove(&root, "tim");
    TrieAdd(&root, "ti", 6);
    TrieAdd(&root, "amy", 7);
    TrieAdd(&root, "aramis", 8);

    printf("Buscar \n");

    trieNode_t* val = TrieSearch(root->children, "andrew");

    if (val)
        printf("%d\n", val->value);

    val = TrieSearch(root->children, "aramis");

    if (val)
        printf("%d\n", val->value);
 
    /*Destroy the trie*/
    TrieDestroy(root);
}
