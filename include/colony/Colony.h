#if !defined(COLONY)
#define COLONY
#include <stdio.h>
#include <stdlib.h>
#include "../utils/Bool.h"

typedef struct Colony Colony;

struct Colony
{
    int foodStock;
    int population;
    boolean amIALive;
    char symbol; // char code 1-21
};

Colony *newColony(int population);
#endif // COLONY
