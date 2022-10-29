#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){


    int x = atoi(argv[1]);

    int tam = 44 + (x-1)*29 + x*11 + (x+1) + ((x-1)*(x-1) )*2;
    
    char* programa = malloc(tam*sizeof(char));

    strcpy(programa, "++++++++[");
    for(int i=1; i<x; i++)
        strcat(programa, ">");
    for(int i=0; i<x; i++)
        strcat(programa, ">++++++");
    strcat(programa, ">++++");
    for(int i=0; i<x; i++)
        strcat(programa, "<<");
    strcat(programa, "-]++++++++++");
    for(int i=1; i<x; i++)
        strcat(programa, "[>++++++++++");
    strcat(programa, "[");
    for(int i=0; i<x; i++)
        strcat(programa, ">.");
    strcat(programa, "+>.");
    for(int i=0; i<=x; i++)
        strcat(programa, "<");
    strcat(programa, "-]");
    for(int i=1; i<x; i++){
        for(int j=1; j<x; j++)
            strcat(programa, ">");
        strcat(programa, "+>----------");
        for(int j=0; j<=x; j++)
            strcat(programa, "<");
        strcat(programa, "-]");
    }
    strcat(programa, ">++++++++++.");

    printf("%s\n", programa);
    free(programa);
    return 0;
}