
#include "../../include/colony/Colony.h"
// TODO:
//  produce() method will be added.
// toString() method will be added.

// it creates propper strategy according to population count and attempts strategy type to colony.
void *pickStrategy(Colony *colony)
{
    void *st;
    enum StrategiesE strategy = colony->population % 3; // 0-1-2 , 0= strategy0 ,1= st"1, 2= st"2

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

        return newStrategy0();

    default:
        break;
    }
}

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

    this->strategy = pickStrategy(this); // attempt strategy and strategy type.

    this->manufacture = newManufacture0();

    this->destroyColony = &destroyColony;

    this->fight = &colonyFight;
}

void colonyFight(Colony *colony0, Colony *colony1)
{
    int c0FightPower;
    int c1FightPower;
    // TODO: change destroys to strategy value.
    // TODO: code the fight alghorithm under switchs.

    // dedecting colony0's strategy
    switch (colony0->strategyType)
    {
    case strategy0:
        c0FightPower = ((Strategy0 *)colony0->strategy)->fight();
        break;
    case strategy1:
        c0FightPower = ((Strategy1 *)colony0->strategy)->fight();
        break; /*
     case strategy2:
         ((Strategy2 *)colony->strategy)->destroy((Strategy2 *)colony->strategy);
         break;*/
    default:
        c0FightPower = ((Strategy0 *)colony0->strategy)->fight(); // TODO: Delete this line after other strategies added.

        break;
    }

    // dedecting colony1's strategy
    switch (colony1->strategyType)
    {
    case strategy0:
        c1FightPower = ((Strategy0 *)colony1->strategy)->fight();
        break; /*
     case strategy1:
         ((Strategy1 *)colony->strategy)->destroy((Strategy1 *)colony->strategy);
         break;
     case strategy2:
         ((Strategy2 *)colony->strategy)->destroy((Strategy2 *)colony->strategy);
         break;*/
    default:
        c1FightPower = ((Strategy0 *)colony1->strategy)->fight(); // TODO: Delete this line after other strategies added.
        break;
    }

    // fight algorithm.

    INDEX;
}

void destroyColony(Colony *colony)
{
    // destroy strategy
    colony->manufacture->destroy(colony->manufacture);
    switch (colony->strategyType)
    {
    case strategy0:
        ((Strategy0 *)colony->strategy)->destroy((Strategy0 *)colony->strategy);
        break; /*
     case strategy1:
         ((Strategy1 *)colony->strategy)->destroy((Strategy1 *)colony->strategy);
         break;
     case strategy2:
         ((Strategy2 *)colony->strategy)->destroy((Strategy2 *)colony->strategy);
         break;*/
    default:
        ((Strategy0 *)colony->strategy)->destroy((Strategy0 *)colony->strategy); // TODO: Delete this line after other strategies added.
        break;
    }

    free(colony);
}