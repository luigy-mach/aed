#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

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
int main()
{
	char string[] = "luigy es la persona mas marica que he visto";
	char word[50];
	
	printf("%s\n",string);
	printf("Inserte palabra\n");

	int c=1;
	while(c!=-1)
	{
		if(is_in(string,word))
			printf("contiene\n");
		else
			printf("no contiene\n");
		printf("inserte -1 para terminar, 1 para seguir\n");
		scanf("%d",&c);
		if(c==1)
		{
			printf("%s\n",string);
			printf("Inserte palabra\n");
		}
	}
	//is_in(string,word);
/*
	char string[] = "luigy es el mas marica";
	//const char delimiters[] = " .,;:!-";
	const char delimiters[] = " ";
	char *token=NULL;

	token = strtok (string, delimiters);     
	while(token)
	{
		printf("%s\n",token);
		token = strtok (NULL, delimiters);   
	
	}*/

	return 0;

}
		
/*
char string[] = "luigy es el mas marica";
const char delimiters[] = " .,;:!-";
//const char delimiters[] = " ";
char *token=NULL;

token = strtok (string, delimiters);     
while(token)
{
	printf("%s\n",token);
	token = strtok (NULL, delimiters);   
	
}*/

//cp = strdupa (string);               

/*
token = strtok (string, delimiters);      
printf("%s\n",token);
token = strtok (NULL, delimiters);   
printf("%s\n",token);
token = strtok (NULL, delimiters);    
printf("%s\n",token);
token = strtok (NULL, delimiters);   
printf("%s\n",token);
token = strtok (NULL, delimiters);   
printf("%s\n",token);
token = strtok (NULL, delimiters);    
printf("%s\n",token);
token = strtok (NULL, delimiters);
*/   
//printf("%s\n",token);

