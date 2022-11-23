/*
	+	increment current cell by 1
	-	decrement curren cell by 1
	>	pointer goes to next cell
	<	pointer goes back to last cell
	.	prints value on the current cell (ASCII table)
	[	initiates a loop
	]	ends a loop (just if the current cell is 0)
*/

#include "libAux.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10000

int main(int argc, char** argv) {
	/*this section contains the vector of values that go from 0 to 255 and the pointer for the current cell*/
	char* fita = malloc(LENGTH * sizeof(char));
	for(int i = 0; i<LENGTH; i++)
		fita[i] = 0;
	int index = 0;
	
	char fileName[40];
	strcpy(fileName, argv[argc-1]);

	char convert[80];
	strcpy(convert, "cat ");
	strcat(convert, fileName);
	strcat(convert, " | ");
	strcat(convert, "tr -d '\\n\\t' ");
	strcat(convert, "> arch");
	system(convert);


	FILE* file = fopen("arch", "r");
	if(!file){
		printf("ERROR: unable to open file");
		exit(1);
	}
	int pSize = getSize(file); //program size
	
	
	fclose(file);
	file = fopen("arch", "r");

	char* program = malloc((pSize+1) * sizeof(char));
	fgets(program, pSize+1, file);

	if(validProgram(program, pSize)){
		printf("ERROR: your program has invalid loop statements\n");
		free(program);
		fclose(file);
		system("rm arch");
		free(fita);
		return 1;
	}


	pilha_t* pilha = criaPilha(pSize/2);

	// /*char representing the command input ( one of the 8 possible commands on BF described in the header )*/
	char command;

	for(int i = 0; i<pSize; i++){
		command = program[i];
		switch(command){
				case '>':
					if(index == LENGTH-1){
						index = 0;
					}
					else
						index++;
				break;
				
				case '<': 
					if(index == 0){
						index = LENGTH - 1;
					}
					else
						index --;
				break;
				
				case '+':
					if(fita[index] == 255){
						fita[index] = 0;
					}
					else
						fita[index]++;
				break;

				case '-':
					if(fita[index] == 0){
						fita[index] = 255;
					} 
					else
						fita[index]--;
				break;

				case '.':
					printf("%c", fita[index]);
				break;

				case '[':
					push(pilha, i);
				break;

				case ']':
					int k = pop(pilha)-1;
					if(fita[index] > 0)
						i = k;
				break;
				
				default:
					break;
		}
	}


	destroiPilha(pilha);
	free(program);
	fclose(file);
	system("rm arch");
	free(fita);
	return 0;
}
