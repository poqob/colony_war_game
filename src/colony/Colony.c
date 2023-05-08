
#include "../../include/colony/Colony.h"
// TODO:
// toString() method will be added.

// local function --private
int getFightPower(Colony *colony)
{
    // dedect colony's strategy type and get fight power from the strategy.
    switch (colony->strategyType)
    {
    case strategy0:
        return ((Strategy0 *)colony->strategy)->fight();
    case strategy1:
        return ((Strategy1 *)colony->strategy)->fight();
    case strategy2:
        return ((Strategy2 *)colony->strategy)->fight();
    default:
        break;
    }
}

// local function --private
//  it creates propper strategy according to population count and attempts strategy type to colony.
void *pickStrategy(Colony *colony)
{
    enum Strategies strategy = colony->population % 3; // 0-1-2 , 0= strategy0 ,1= st"1, 2= st"2

    // TODO: edit 1-2 situations constructors.
    switch (strategy)
    {
    case strategy0:
        colony->strategyType = strategy0;
        return newStrategy0();

    case strategy1:
        colony->strategyType = strategy1;

        return newStrategy1();
    case strategy2:
        colony->strategyType = strategy2;

        return newStrategy2();

    default:
        break;
    }
}

// local function --private
void *pickManufacture(Colony *colony)
{
    enum Manufactures manufacture = colony->population % 3; // 0-1-2, 0= manufacture0 ...

    switch (manufacture)
    {
    case manufacture0:
        colony->manufactureType = manufacture0;
        return newManufacture0();

    case manufacture1:
        colony->manufactureType = manufacture1;
        return newManufacture1();
    case manufacture2:
        colony->manufactureType = manufacture2;
        return newManufacture2();
    default:
        break;
    }
};

// local function --private
void destroyStrategy(Colony *colony)
{
    // destroy strategy
    switch (colony->strategyType)
    {
    case strategy0:
        ((Strategy0 *)colony->strategy)->destroy((Strategy0 *)colony->strategy);
        break;
    case strategy1:
        ((Strategy1 *)colony->strategy)->destroy((Strategy1 *)colony->strategy);
        break;
    case strategy2:
        ((Strategy2 *)colony->strategy)->destroy((Strategy2 *)colony->strategy);
        break;
    default:
        break;
    }
}

// local function --private
void destroyManufacture(Colony *colony)
{
    // destroy manufacture
    switch (colony->manufactureType)
    {
    case manufacture0:
        ((Manufacture0 *)colony->manufacture)->destroy((Manufacture0 *)colony->manufacture);
        break;
    case manufacture1:
        ((Manufacture1 *)colony->manufacture)->destroy((Manufacture1 *)colony->manufacture);
        break;
    case manufacture2:
        ((Manufacture2 *)colony->manufacture)->destroy((Manufacture2 *)colony->manufacture);
        break;
    default:
        break;
    }
}

Colony *newColony(int population)
{
    // allocate
    Colony *this = malloc(sizeof(Colony));
    if (this == NULL)
        return NULL;

    // attempt fields
    this->amIALive = true;
    this->population = population;
    this->symbol = population % 21; // in ascii symbols defined between 1-21
    this->foodStock = population * population;

    this->strategy = pickStrategy(this); // attempt strategy and strategy type.

    this->manufacture = pickManufacture(this); // attempt manufacture and manufacture type.

    this->fightPower = getFightPower(this);

    this->destroyColony = &destroyColony;
}

void destroyColony(Colony *this)
{
    destroyStrategy(this);
    destroyManufacture(this);
    free(this);
}