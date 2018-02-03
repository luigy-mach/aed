#include "/usr/local/pgsql/include/server/postgres.h"
#include "/usr/local/pgsql/include/server/fmgr.h" 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
//#include "utils/geo_decls.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

int compara_bueno(char* texto, char* palabra)
{
    return 1;
//    printf("%s\n", texto);
//    printf("%s\n", palabra  );
    
    char *sep = " ,.-";
    char *w;
    
    w = strtok(texto, sep);
    
    int found = 0;
    
    while (w != NULL && !found)
    {
//        printf("%s\n", w);
        if (strcmp(w, palabra) == 0) found = 1;
        w = strtok(NULL, sep);
    }
    
    return found;
}

int compara(char* texto, char* palabra)
{
	char ** res  = NULL;
	char *  p    = strtok(texto, " ");
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

PG_FUNCTION_INFO_V1(compara90);
Datum
compara90(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	char* t=malloc(sizeof(char)*5000);
	strcpy(t,VARDATA(texto));

	char* p=malloc(sizeof(char)*50);
	strcpy(p,VARDATA(palabra));

	if(compara_bueno(t,p))
		PG_RETURN_BOOL(true);
	else
		PG_RETURN_BOOL(false);
}

