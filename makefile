OBJECTS = comp.c libAux.c

all: ${OBJECTS} libAux.h
	gcc ${OBJECTS} -o bf

gen: gen.c
	gcc gen.c -o gen
	
purge: bf
	rm bf gen
