#include "/usr/local/pgsql/include/server/postgres.h"
#include "/usr/local/pgsql/include/server/fmgr.h" 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <stddef.h>
//#include "trie.h"
//#include "utils/geo_decls.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif


int compara(char* texto,char* palabra)
{  
	char ** res  = NULL;
	char *  p    = strtok (texto, " ");
	int n_spaces = 0, i;

	while (p) {
  	res = realloc (res, sizeof (char*) * ++n_spaces);

  	if (res == NULL)
    	exit (-1); 

  	res[n_spaces-1] = p;

  	p = strtok (NULL, " ");
	}

	for (i = 0; i < n_spaces; ++i)
	{	
		if(!strcmp(res[i],palabra))
		{
			return 1;
			free(res);
		}

	}
	free(res);
	return 0;	
}

PG_FUNCTION_INFO_V1(compara10);
Datum
compara10(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	char ** res  = NULL;
	char *  p    = strtok (VARDATA(texto)," ");
	int n_spaces = 0, i;

	while (p) {
  	res = realloc (res, sizeof (char*) * ++n_spaces);

  	if (res == NULL)
    	exit (-1); 

  	res[n_spaces-1] = p;

  	p = strtok (NULL, " ");
	}

    /*
	for (i = 0; i < n_spaces; ++i)
	{	
		if(!strcmp(res[i],VARDATA(palabra)))
		{
			PG_RETURN_BOOL(true);
			free(res);
		}

	}*/
	free(res);
	PG_RETURN_BOOL(false);	
}

int main()
{
    printf("Hello world\n");
    return 0;
}


