#include "/usr/local/pgsql/include/server/postgres.h"
#include "/usr/local/pgsql/include/server/fmgr.h" 

#include <string.h>
#include <stdio.h>
#include <stddef.h>
//#include "utils/geo_decls.h"


#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(compara4);
Datum
compara4(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	const char delimiters[] = " ";
	char *token=NULL;

	token = strtok(VARDATA(texto), delimiters);

	while(token)
	{
		if(!strcmp(token,VARDATA(palabra)))
			PG_RETURN_BOOL(true);
		token = strtok (NULL, delimiters);   
	}
	PG_RETURN_BOOL(false);

}

