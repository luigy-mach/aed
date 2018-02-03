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

PG_FUNCTION_INFO_V1(igualdad1);

Datum
igualdad1(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	if(!strcmp(VARDATA(texto),VARDATA(palabra)))
		PG_RETURN_BOOL(true);
	else
		PG_RETURN_BOOL(false);

}

PG_FUNCTION_INFO_V1(igualdad2);

Datum
igualdad2(PG_FUNCTION_ARGS)
{
	text *texto = PG_GETARG_TEXT_P(0);
	text *palabra = PG_GETARG_TEXT_P(1);

	char tmp1[5000];
	strcpy(tmp1,VARDATA(texto));

	char tmp2[50];
	strcpy(tmp2,VARDATA(palabra));

	if(!strcmp(tmp1,tmp2))
		PG_RETURN_BOOL(true);
	else
		PG_RETURN_BOOL(false);

}



