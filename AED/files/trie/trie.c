#include <stdio.h>
#include <stdlib.h>

#include "trie.h"

trieNode_t *TrieCreateNode(char key, trieVal_t data);

void TrieCreate(trieNode_t **root)
{
 *root = TrieCreateNode('\0', 0xffffffff);
}

trieNode_t *TrieCreateNode(char key, trieVal_t data)
{
    trieNode_t *node = NULL;
    node = (trieNode_t *)malloc(sizeof(trieNode_t));

    node->key = key;
    node->next = NULL;
    node->children = NULL;
    node->value = data;
    node->parent= NULL;
    node->prev= NULL;
    return node;
}

void TrieAdd(trieNode_t **root, char *key, int data)
{
    trieNode_t *pTrav = NULL;

    if(NULL == *root) return;

    pTrav = (*root)->children;

    if(pTrav == NULL)
    {
        for(pTrav = *root; *key; pTrav = pTrav->children)
        {
            pTrav->children = TrieCreateNode(*key, 0xffffffff);
            pTrav->children->parent = pTrav;
            key++;
        }

        pTrav->children = TrieCreateNode('\0', data);
        pTrav->children->parent = pTrav;

        return;
    }

    if(TrieSearch(pTrav, key)) return;

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
            TrieAdd(&(pTrav->next), key, data);
            return;
        }
        pTrav = pTrav->next;
    }

    if(*key)
    {
        pTrav->next = TrieCreateNode(*key, 0xffffffff);
    }
    else
    {
        pTrav->next = TrieCreateNode(*key, data);
    }

    pTrav->next->parent = pTrav->parent;
    pTrav->next->prev = pTrav;

    if(!(*key))
        return;

    key++;

    for(pTrav = pTrav->next; *key; pTrav = pTrav->children)
    {
        pTrav->children = TrieCreateNode(*key, 0xffffffff);
        pTrav->children->parent = pTrav;
        key++;
    }

    pTrav->children = TrieCreateNode('\0', data);
    pTrav->children->parent = pTrav;

    return;
}

trieNode_t* TrieSearch(trieNode_t *root, const char *key)
{
    trieNode_t *level = root;
    trieNode_t *pPtr = NULL;

    int lvl=0;
    while(1)
    {
        trieNode_t *found = NULL;
        trieNode_t *curr;

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

void TrieRemove(trieNode_t **root, char *key)
{
    trieNode_t *tPtr = NULL;
    trieNode_t *tmp = NULL;

    if(NULL == *root || NULL == key)
        return;

    tPtr = TrieSearch((*root)->children, key);

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

void TrieDestroy( trieNode_t* root )
{
    trieNode_t *tPtr = root;
    trieNode_t *tmp = root;

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
