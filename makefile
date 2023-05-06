all: compile run

compile:
	gcc -I ./include/utils -o ./lib/ArrayList.o -c ./src/utils/ArrayList.c
	gcc -I ./include/utils -o ./lib/Bool.o -c ./src/utils/Bool.c
	gcc -I ./include/utils -o ./lib/DataType.o -c ./src/utils/DataType.c

	gcc -I ./include/colony -o ./lib/Colony.o -c ./src/colony/Colony.c

	gcc -I ./include -o ./bin/Test ./lib/ArrayList.o ./lib/Bool.o ./lib/DataType.o ./lib/Colony.o ./src/Test.c

run:
	./bin/Test
