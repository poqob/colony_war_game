#if !defined(COLONY)
#define COLONY
#include <stdio.h>
#include <stdlib.h>
#include "../utils/Bool.h"

typedef struct Colony Colony;

struct Colony
{
    // fields
    int foodStock;
    int population;
    boolean amIALive;
    char symbol; // char code 1-21

    // functions
    void (*destroyColony)(Colony *);
};

Colony *newColony(int population);
void destroyColony(Colony *colony);

#endif // COLONY
