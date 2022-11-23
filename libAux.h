#include <stdio.h>
#include <stdlib.h>
struct pilha{
    int* vetor;
    int topo;
};
typedef struct pilha pilha_t;

int validProgram(char* string, int tam);

int getSize(FILE* file);

pilha_t* criaPilha(int max);
void destroiPilha(pilha_t* pilha);

void push(pilha_t* pilha, int value);
int pop(pilha_t* pilha);