
#include "../../include/colony/Colony.h"

Colony *newColony(int population)
{
    // take location in ram
    Colony *this = malloc(sizeof(Colony));
    if (this == NULL)
        return NULL;

    this->amIALive = true;
    this->population = population;
    this->symbol = population % 21; // in ascii symbols defined between 1-21
    this->foodStock = population * population;
}