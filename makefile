all: compile run

compile:
	gcc -I ./include/utils -o ./lib/ArrayList.o -c ./src/utils/ArrayList.c
	gcc -I ./include/utils -o ./bin/Test ./lib/ArrayList.o ./src/Test.c

run:
	./bin/Test
