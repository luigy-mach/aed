#include "/usr/local/pgsql/include/server/postgres.h"
#include "/usr/local/pgsql/include/server/fmgr.h" 

#include <string.h>
#include <stdio.h>
//#include "utils/geo_decls.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(compara3);

Datum
compara3(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	if(!strcmp(VARDATA(texto),VARDATA(palabra)))
		PG_RETURN_BOOL(true);
	else
		PG_RETURN_BOOL(false);

}

bool is_in(char* texto,char* palabra)
{
	const char delimiters[] = " ";
	char *token=NULL;

	token = strtok(texto, delimiters);     
	while(token)
	{
		//printf("%s\n",token);
		if(!strcmp(token,palabra))
			return true;
		token = strtok (NULL, delimiters);   
	}
	return false;

}
