typedef int trieVal_t;
typedef char* data;
 
typedef struct trieNodo
{
    char key;
    trieVal_t value;
    
    struct trieNodo *next;
    struct trieNodo *prev;
    struct trieNodo *children;
    struct trieNodo *parent;
} trieNodo_t;
 
void TrieCrear(trieNodo_t **root);
trieNodo_t* TrieBuscar(trieNodo_t *root, const char* key);
void TrieInsertar(trieNodo_t **root, data key, int data);
void TrieEliminar(trieNodo_t **root, data key);
void TrieDestruir( trieNodo_t* root );
