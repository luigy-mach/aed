#include "BKTree.h"


#include <ctype.h>
#include <string>


// Transforma un string a minúsculas y borra caracteres no letras
void clean( const STRING & str, STRING & newStr, int &newPos) 
{
    assert(newStr.empty());

    int i = 0;
    STRING buff;

    while(str[i]){
    	if(isalpha(str[i]))
    		buff+=tolower(str[i]);
    	i++;
    	newPos++;
    }
    newStr=buff;
    return;
}

// Añade una palabra, con su posición al árbol
void BKTree::add( const PAIR_S_I & _term)
{
    STRING word;
    int newPos = _term.second	;
    clean(_term.first, word, newPos);
    PAIR_S_I temp_pair = std::make_pair(STRING(word), _term.second);

    if (!word.empty())
    {
        if (root)
            root->add(temp_pair);
        else
            root = new BKNode(temp_pair);
    }
}


// Busca una palabra, en una distancia dada, y añade a collected su posición y longitud
void BKTree::query( const STRING & word, int distance, MAP_OUT & collected) const
{
    STRING newWord;
    int x;
    clean(word, newWord, x);

    if (!newWord.empty())
        if (root)
            root->query(word, distance, collected);
}
