
#include "../../include/colony/Colony.h"
// TODO:
// fight(), produce() methods will be added.
// toString() method will be added.

Colony *newColony(int population)
{
    // take location in ram
    Colony *this = malloc(sizeof(Colony));
    if (this == NULL)
        return NULL;

    // attempt fields
    this->amIALive = true;
    this->population = population;
    this->symbol = population % 21; // in ascii symbols defined between 1-21
    this->foodStock = population * population;

    // attempt functions
    this->destroyColony = &destroyColony;
}

void destroyColony(Colony *colony)
{
    free(colony);
}