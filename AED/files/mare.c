#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

int main()
{
	//char t[]="luigy es bien marica recontra marica";
	char t[]="cuadros sabe joder y es aburrido";
	int longitud=strlen(t);
	char *tmp;
	char q[]="ash";
	const int n=10;
	
	//char* word[n]={"luigy","sape","cuadros","melas","jueputa","aburrido","rata","mare","jejeje"};	
	char* words[n];
	words[0]="luigy";
	words[1]="sape";
	words[2]="cuadros";
	words[3]="recontra";	
	words[4]="aburrido";	
	words[5]="marica";	
	words[6]="mare";	
	words[7]="jejeje";	
	words[8]="rata";	
	words[9]="bien";
	

	for(int i=0;i<n;i++)
	{
		tmp=(char *)malloc(sizeof(char)*longitud);
		strcpy(tmp,t);
		if(compara(tmp,words[i]))
			printf("Contiene...-%s\n",words[i]);
		else
			printf("No contiene...\n");
		free(tmp);
	}			

	/*if(compara(t,q))
		printf("Contiene...\n");
	else
		printf("No contiene...\n");
	*/

/*
char    str[]= "luigy es bien marica";
char ** res  = NULL;
char *  p    = strtok (str, " ");
int n_spaces = 0, i;




while (p) {
  res = realloc (res, sizeof (char*) * ++n_spaces);

  if (res == NULL)
    exit (-1); 

  res[n_spaces-1] = p;

  p = strtok (NULL, " ");
}

//res = realloc (res, sizeof (char*) * (n_spaces+1));
//res[n_spaces] = 0;


for (i = 0; i < n_spaces+1; ++i)
  printf ("res[%d] = %s\n", i, res[i]);
*/

return 0;

}
