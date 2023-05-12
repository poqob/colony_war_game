all: compile run

compile:
	gcc -I ./include/utils -o ./lib/ArrayList.o -c ./src/utils/ArrayList.c
	gcc -I ./include/utils -o ./lib/Bool.o -c ./src/utils/Bool.c
	gcc -I ./include/utils -o ./lib/DataType.o -c ./src/utils/DataType.c
	gcc -I ./include/utils -o ./lib/String.o -c ./src/utils/String.c

	gcc -I ./include/strategy -o ./lib/AStrategy.o -c ./src/strategy/AStrategy.c
	gcc -I ./include/strategy -o ./lib/Strategy0.o -c ./src/strategy/Strategy0.c
	gcc -I ./include/strategy -o ./lib/Strategy1.o -c ./src/strategy/Strategy1.c
	gcc -I ./include/strategy -o ./lib/Strategy2.o -c ./src/strategy/Strategy2.c
	gcc -I ./include/strategy -o ./lib/Strategies.o -c ./src/strategy/Strategies.c

	gcc -I ./include/manufacture -o ./lib/AManufacture.o -c ./src/manufacture/AManufacture.c
	gcc -I ./include/manufacture -o ./lib/Manufacture0.o -c ./src/manufacture/Manufacture0.c
	gcc -I ./include/manufacture -o ./lib/Manufacture1.o -c ./src/manufacture/Manufacture1.c
	gcc -I ./include/manufacture -o ./lib/Manufacture2.o -c ./src/manufacture/Manufacture2.c
	gcc -I ./include/manufacture -o ./lib/Manufactures.o -c ./src/manufacture/Manufactures.c


	gcc -I ./include/colony -o ./lib/Colony.o -c ./src/colony/Colony.c

	gcc -I ./include/log -o ./lib/Log.o -c ./src/log/Log.c

	gcc -I ./include/utils -o ./lib/DebugPrinter.o -c ./src/utils/DebugPrinter.c

	gcc -I ./include/ui -o ./lib/UI.o -c ./src/ui/UI.c

	gcc -I ./include/game -o ./lib/GameManager.o -c ./src/game/GameManager.c
	gcc -I ./include/game -o ./lib/Game.o -c ./src/game/Game.c

	gcc -I ./include -o ./bin/Test ./lib/ArrayList.o ./lib/Bool.o ./lib/DataType.o ./lib/String.o ./lib/AStrategy.o ./lib/Strategy0.o ./lib/Strategy1.o ./lib/Strategy2.o ./lib/Strategies.o ./lib/AManufacture.o ./lib/Manufacture0.o ./lib/Manufacture1.o ./lib/Manufacture2.o ./lib/Manufactures.o ./lib/Colony.o ./lib/Log.o ./lib/DebugPrinter.o ./lib/UI.o ./lib/GameManager.o ./lib/Game.o ./src/Test.c

run:
	./bin/Test 13 24
