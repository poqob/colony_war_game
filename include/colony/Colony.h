#if !defined(COLONY)
#define COLONY
#include <stdio.h>
#include <stdlib.h>
#include "../utils/Bool.h"
#include "../utils/String.h"
#include "../strategy/Strategies.h"
#include "../strategy/Strategy0.h"
#include "../strategy/Strategy1.h"
#include "../strategy/Strategy2.h"
#include "../manufacture/Manufactures.h"
#include "../manufacture/Manufacture0.h"
#include "../manufacture/Manufacture1.h"
#include "../manufacture/Manufacture2.h"
/*This class includes the characteristics of a colony such as food stock, population, symbol, victory and defeat counts, fighting power and production power.
 It also includes functions that exhibit different behaviors according to the selected strategy and production type.
  The Colony class also includes functions for reporting the growth, death, and status of colonies, as well as for converting them to string data.*/
#define INDEX 1000
#define POPULATION_SCALE_AS_PERCENTAGE 120

typedef struct Colony Colony;

struct Colony
{
    // fields
    int foodStock;
    int population;
    boolean amIALive;
    char symbol;
    int victory;
    int loose;
    // If the toString method is called, a string data is stored in the memory.
    // 'str' is a variable created to store the address of this created string and to perform its destruction.
    String *str;

    void *strategy;
    enum Strategies strategyType; // stores which strategy struct picked.

    void *manufacture;
    enum Manufactures manufactureType; // stores which manufacture struct picked.
    // functions
    void (*destroyColony)(Colony *);
    void (*grow)(Colony *);
    String *(*toString)(Colony *);
    void (*reportLifeStatus)(Colony *);

    int fightPower;
    int manufacturePower;
};

Colony *newColony(int, int);
void destroyColony(Colony *);
void colonyGrow(Colony *);
String *toStringColony(Colony *);
void colonyDeadControll(Colony *);

#endif // COLONY
