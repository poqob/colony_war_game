#if !defined(COLONY)
#define COLONY
#define INDEX 1000
#include <stdio.h>
#include <stdlib.h>
#include "../utils/Bool.h"
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
    void *strategy;
    enum Strategies strategyType; // stores which strategy picked.

    void *manufacture;
    enum Manufactures manufactureType;
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
