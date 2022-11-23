#include "libAux.h"

int getSize(FILE* file){
    char c = fgetc(file);
    int count = 0;
    
    while(c != -1){
        count++;
        c = fgetc(file);
    }
    return count;
}

pilha_t* criaPilha(int max){
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->vetor = malloc(max * sizeof(int));
    pilha->topo = 0;

    return pilha;
}

void destroiPilha(pilha_t* pilha){
    free(pilha->vetor);
    free(pilha);
    return;
}

void push(pilha_t* pilha, int value){
    pilha->vetor[pilha->topo] = value;
    pilha->topo++;
    return;
}
int pop(pilha_t* pilha){
    pilha->topo--;
    return pilha->vetor[pilha->topo];
}

int validProgram(char* string, int tam){
    pilha_t* p = criaPilha(tam);
    
    for(int i=0; i<tam; i++){
        if(string[i] == '['){
            push(p, 1);
        }
        else if(string[i] == ']')
            pop(p);
    }
    int k = p->topo;
    destroiPilha(p);

    if(k != 0)
        return 1;
    return 0;
}