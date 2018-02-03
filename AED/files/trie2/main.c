#include <stdio.h>
#include <stdlib.h>

#include "trie.h"
 
int main()
{
    trieNodo_t *root;
    printf("Trie Example\n");
     
    /*Create a trie*/
    TrieCrear(&root);
     
    TrieInsertar(&root, "andrew", 1);
    TrieInsertar(&root, "tina", 2);
    TrieInsertar(&root, "argo", 3);
    TrieInsertar(&root, "timor", 5);
    TrieEliminar(&root, "tim");
    TrieInsertar(&root, "tim", 6);
    TrieEliminar(&root, "tim");
    TrieInsertar(&root, "ti", 6);
    TrieInsertar(&root, "amy", 7);
    TrieInsertar(&root, "aramis", 8);

    printf("Buscar \n");

    trieNodo_t* val = TrieBuscar(root->children, "andrew");

    if (val)
        printf("%d\n", val->value);

    val = TrieBuscar(root->children, "aramis");

    if (val)
        printf("%d\n", val->value);
 
    /*Destroy the trie*/
    TrieDestruir(root);
}
