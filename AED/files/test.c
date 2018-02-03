#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compara_bueno(char* texto, char* palabra)
{
    printf("%s\n", texto);
    printf("%s\n", palabra  );
    
    char *sep = " ,.-";
    char *w;
    
    w = strtok(texto, sep);
    
    int found = 0;
    
    while (w != NULL && !found)
    {
        printf("%s\n", w);
        if (strcmp(w, palabra) == 0) found = 1;
        w = strtok(NULL, sep);
    }
    
    return found;
}

int main()
{
    char *t, *p;
    
    t = malloc(5000);
    p = malloc(50);
    
    strcpy(t, "luigy marica");
    strcpy(p, "maric");
    
    printf("%d\n", compara_bueno(t, p));
    
    free(t);
    free(p);
    
    return 0;
}

