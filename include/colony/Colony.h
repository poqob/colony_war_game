#if !defined(COLONY)
#define COLONY
#define INDEX 1000
#define POPULATION_SCALE_AS_PERCENTAGE 120
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

typedef struct Colony Colony;

struct Colony
{
    // fields
    int foodStock;
    int population;
    boolean amIALive;
    char symbol; // char code 1-21
    int victory;
    int loose;

    void *strategy;
    enum Strategies strategyType; // stores which strategy struct picked.

    void *manufacture;
    enum Manufactures manufactureType; // stores which manufacture struct picked.
    // functions
    void (*destroyColony)(Colony *);
    void (*grow)(Colony *);
    void (*toString)(Colony *);

    int fightPower;
    int manufacturePower;
};

Colony *newColony(int);
void destroyColony(Colony *);
void colonyGrow(Colony *);
void toStringColony(Colony *);

#endif // COLONY
