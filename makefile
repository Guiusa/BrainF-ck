OBJECTS = comp.c libRead.c

all: ${OBJECTS} libRead.h
	gcc ${OBJECTS} -o bf

gen: gen.c
	gcc gen.c -o gen
	
purge: bf
	rm bf gen