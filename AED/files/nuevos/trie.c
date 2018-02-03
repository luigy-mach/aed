#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

trieNodo_t *TrieCrearNodo(char key, trieVal_t data);

void TrieCrear(trieNodo_t **root)
{
 *root = TrieCrearNodo('\0', 0xffffffff);
}

trieNodo_t *TrieCrearNodo(char key, trieVal_t data)
{
    trieNodo_t *node = NULL;
    node = (trieNodo_t *)malloc(sizeof(trieNodo_t));

    node->key = key;
    node->next = NULL;
    node->children = NULL;
    node->value = data;
    node->parent= NULL;
    node->prev= NULL;
    return node;
}

void TrieInsertar(trieNodo_t **root, char *key, int data)
{
    trieNodo_t *pTrav = NULL;

    if(NULL == *root) return;

    pTrav = (*root)->children;

    if(pTrav == NULL)
    {
        for(pTrav = *root; *key; pTrav = pTrav->children)
        {
            pTrav->children = TrieCrearNodo(*key, 0xffffffff);
            pTrav->children->parent = pTrav;
            key++;
        }

        pTrav->children = TrieCrearNodo('\0', data);
        pTrav->children->parent = pTrav;

        return;
    }

    if(TrieBuscar(pTrav, key)) return;

    while(*key != '\0')
    {
        if(*key == pTrav->key)
        {
            key++;
            pTrav = pTrav->children;
        }
        else
            break;
    }

    while(pTrav->next)
    {
        if(*key == pTrav->next->key)
        {
            key++;
            TrieInsertar(&(pTrav->next), key, data);
            return;
        }
        pTrav = pTrav->next;
    }

    if(*key)
    {
        pTrav->next = TrieCrearNodo(*key, 0xffffffff);
    }
    else
    {
        pTrav->next = TrieCrearNodo(*key, data);
    }

    pTrav->next->parent = pTrav->parent;
    pTrav->next->prev = pTrav;

    if(!(*key))
        return;

    key++;

    for(pTrav = pTrav->next; *key; pTrav = pTrav->children)
    {
        pTrav->children = TrieCrearNodo(*key, 0xffffffff);
        pTrav->children->parent = pTrav;
        key++;
    }

    pTrav->children = TrieCrearNodo('\0', data);
    pTrav->children->parent = pTrav;

    return;
}

trieNodo_t* TrieBuscar(trieNodo_t *root, const char* key)
{
    trieNodo_t *level = root;
    trieNodo_t *pPtr = NULL;

    int lvl=0;
    while(1)
    {
        trieNodo_t *found = NULL;
        trieNodo_t *curr;

        for (curr = level; curr != NULL; curr = curr->next)
        {
            if (curr->key == *key)
            {
                found = curr;
                lvl++;
                break;
            }
        }

        if (found == NULL)
            return NULL;
 
        if (*key == '\0')
        {
            pPtr = curr;
            return pPtr;
        }
 
        level = found->children;
        key++;
    }
}

void TrieEliminar(trieNodo_t **root, char *key)
{
    trieNodo_t *tPtr = NULL;
    trieNodo_t *tmp = NULL;

    if(NULL == *root || NULL == key)
        return;

    tPtr = TrieBuscar((*root)->children, key);

    if(NULL == tPtr) return;

    while(1)
    {
        if( tPtr->prev && tPtr->next)
        {
            tmp = tPtr;
            tPtr->next->prev = tPtr->prev;
            tPtr->prev->next = tPtr->next;

            free(tmp);
            break;
         }
        else if(tPtr->prev && !(tPtr->next))
        {
            tmp = tPtr;
            tPtr->prev->next = NULL;

            free(tmp);
            break;
        }
        else if(!(tPtr->prev) && tPtr->next)
        {
            tmp = tPtr;
            tPtr->parent->children = tPtr->next;
            free(tmp);
            break;
        }
        else
        {
            tmp = tPtr;
            tPtr = tPtr->parent;
            tPtr->children = NULL;

            free(tmp);
        }
    }
}

void TrieDestruir( trieNodo_t* root )
{
    trieNodo_t *tPtr = root;
    trieNodo_t *tmp = root;

    while(tPtr)
    {
        while(tPtr->children)
            tPtr = tPtr->children;

        if( tPtr->prev && tPtr->next)
        {
            tmp = tPtr;
            tPtr->next->prev = tPtr->prev;
            tPtr->prev->next = tPtr->next;

            free(tmp);
        }
        else if(tPtr->prev && !(tPtr->next))
        {
            tmp = tPtr;
            tPtr->prev->next = NULL;
            free(tmp);
        }
        else if(!(tPtr->prev) && tPtr->next)
        {
            tmp = tPtr;
            tPtr->parent->children = tPtr->next;
            tPtr->next->prev = NULL;
            tPtr = tPtr->next;
            free(tmp);
        }
        else
        {
            tmp = tPtr;
            if(tPtr->parent == NULL)
            {
                /*Root*/
                free(tmp);
                return;
            }
            tPtr = tPtr->parent;
            tPtr->children = NULL;

            free(tmp);
        }
    }
}
