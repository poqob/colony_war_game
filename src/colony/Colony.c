
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
int getManufacturePower(Colony *colony)
{
    switch (colony->manufactureType)
    {
    case manufacture0:
        return ((Manufacture0 *)colony->manufacture)->produce();
    case manufacture1:
        return ((Manufacture1 *)colony->manufacture)->produce();
    case manufacture2:
        return ((Manufacture2 *)colony->manufacture)->produce();
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
    this->symbol = population % 31; // in ascii symbols defined between 1-31
    this->foodStock = population * population;
    this->victory = 0;
    this->loose = 0;

    this->strategy = pickStrategy(this); // attempt strategy and strategy type.

    this->manufacture = pickManufacture(this); // attempt manufacture and manufacture type.

    this->fightPower = getFightPower(this);

    this->manufacturePower = getManufacturePower(this);

    this->destroyColony = &destroyColony;

    this->grow = &colonyGrow;

    this->toString = &toStringColony;

    this->reportLifeStatus = &colonyDeadControll;
}

void colonyGrow(Colony *this)
{
    // controlling population, if the population is under 0 set colony is dead.
    if (this->population <= 0)
    {
        this->amIALive = false;
        return;
    }

    if (this->amIALive == true)
    {

        // new population per round.
        this->population = this->population * POPULATION_SCALE_AS_PERCENTAGE / 100;

        // minus food stock
        this->foodStock -= this->population * 2;

        //  produce according to updated population.
        switch (this->manufactureType)
        {
        case manufacture0:
            this->foodStock += ((Manufacture0 *)this->manufacture)->produce();
            break;
        case manufacture1:
            this->foodStock += ((Manufacture1 *)this->manufacture)->produce();
            break;
        case manufacture2:
            this->foodStock += ((Manufacture2 *)this->manufacture)->produce();
            break;
        default:
            break;
        }

        // controlling if food stock is under level zero.
        if (this->foodStock <= 0)
        {
            this->amIALive = false;
            return;
        }
    }
}

void destroyColony(Colony *this)
{
    if (this->str != NULL)
        this->str->destroy(this->str);

    destroyStrategy(this);
    destroyManufacture(this);

    free(this);
}

// yahu ben bunu nasil silecegim bellekten??? kullanildigi yerde silinsin kullanima en uygun oyle oluyor
String *toStringColony(Colony *this)
{
    // output
    String *output = newString("\n***************************\n");

    // symbol
    output->appendStr(output, newString("symbol: "));
    output->appendChar(output, &this->symbol);
    output->appendChar(output, "\n");

    // life status
    output->appendChar(output, "life status: ");
    output->appendInt(output, this->amIALive);
    output->appendChar(output, "\n");

    // population
    output->appendChar(output, "population: ");
    output->appendInt(output, this->population);
    output->appendChar(output, "\n");

    // food stock
    output->appendChar(output, "food stock: ");
    output->appendInt(output, this->foodStock);
    output->appendChar(output, "\n");

    // strategy type
    output->appendChar(output, "strategy type: ");
    output->appendChar(output, StrategiesStrings[this->strategyType]);
    output->appendChar(output, "\n");

    // fight power
    output->appendChar(output, "fight power: ");
    output->appendInt(output, this->fightPower);
    output->appendChar(output, "\n");

    // Manufacturer type
    output->appendChar(output, "Manufacturer type: ");
    output->appendChar(output, ManufacturesStrings[this->manufactureType]);
    output->appendChar(output, "\n");

    // Manufacturer power
    output->appendChar(output, "Manufacture power: ");
    output->appendInt(output, this->manufacturePower);
    output->appendChar(output, "\n");

    // Victory count
    output->appendChar(output, "Victories: ");
    output->appendInt(output, this->victory);
    output->appendChar(output, "\n");

    // Loose count
    output->appendChar(output, "Looses: ");
    output->appendInt(output, this->loose);
    output->appendChar(output, "\n***************************\n");

    this->str = output;
    return output;
}

void colonyDeadControll(Colony *this)
{
    // controlling if food stock is under level zero.
    if (this->foodStock <= 0 || this->population <= 0)
    {
        this->amIALive = false;
    }
}