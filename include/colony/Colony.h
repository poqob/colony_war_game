#if !defined(COLONY)
#define COLONY
#define INDEX 1000
#include <stdio.h>
#include <stdlib.h>
#include "../utils/Bool.h"
#include "../strategy/StrategiesE.h"
#include "../strategy/Strategy0.h"
#include "../strategy/Strategy1.h"
#include "../manufacture/Manufacture0.h"

typedef struct Colony Colony;

struct Colony
{
    // fields
    int foodStock;
    int population;
    boolean amIALive;
    char symbol; // char code 1-21
    void *strategy;
    enum StrategiesE strategyType; // stores which strategy picked.

    Manufacture0 *manufacture;
    // functions
    void (*destroyColony)(Colony *);
    void (*fight)(Colony *, Colony *);
    // TODO: Produce
    void (*produce)();
};

Colony *newColony(int population);
void destroyColony(Colony *colony);
void colonyFight(Colony *colony0, Colony *colony1);

#endif // COLONY
