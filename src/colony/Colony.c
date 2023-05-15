
#include "../../include/colony/Colony.h"

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
//  it creates proper strategy randomly and attempts strategy type to colony.
// return type is void* because, it is not possible to know which strategy structure will be picked :D
void *pickStrategy(Colony *colony)
{
    srand(time(NULL));
    int rnum = (rand() + colony->population) % 3;
    enum Strategies strategy = rnum; // 0-1-2 , 0= strategy0 ,1= st"1, 2= st"2

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
// it creates proper manufacture structure randomly and atempts it to colony's manufactureType
// return type is void* because, it is not possible to know which manufacture structure will be picked :D
void *pickManufacture(Colony *colony)
{
    srand(time(NULL));
    int rnum = (rand() + colony->population) % 3;
    enum Manufactures manufacture = rnum; // 0-1-2, 0= manufacture0 ...

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
// destroy picked strategy structure according to colony's strategyType.
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
// destroy picked manufacture structure according to colony's manufactureType.
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

// constructor
Colony *newColony(int population, int symbol)
{
    // allocate
    Colony *this = malloc(sizeof(Colony));
    if (this == NULL)
        return NULL;

    // attempt fields
    this->amIALive = true;
    this->population = population;
    this->symbol = symbol;
    this->foodStock = population * population;
    this->victory = 0;
    this->loose = 0;

    this->strategy = pickStrategy(this); // attempt strategy and strategy type.

    this->manufacture = pickManufacture(this); // attempt manufacture and manufacture type randomly.
    // attempt strategy's (which picked randomly) fightpower to Colony::fightpower(field) via (private)Colony::getFightPower()
    this->fightPower = getFightPower(this);

    // attempt Manufacture's (which picked randomly) manufacture power to Colony::manufacturePower(field) via Colony::getManufacturePower()
    this->manufacturePower = getManufacturePower(this);

    this->destroyColony = &destroyColony; // ~destruction

    // grow method, the method increases colony's population per every single tour.
    // Decreases foodstock and calls produce() method from ManufactureX structure.
    this->grow = &colonyGrow;

    this->toString = &toStringColony;

    // the GameManager structure calls this method after every combat to report current(after combat) life status of the colony.
    this->reportLifeStatus = &colonyDeadControll;

    return this;
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

// destructor
void destroyColony(Colony *this)
{
    // destroy the str which stores toString() method's result if it exists.
    if (this->str != NULL)
        this->str->destroy(this->str);

    // destroy randomly attemted strategy
    destroyStrategy(this);
    // destroy randomly attemted manufacture
    destroyManufacture(this);
    // destroy the Colony.
    free(this);
}

// toString method: toString method creates a String structure on memory and attempts it to Colony's (STRING*)str field.
// The purpose of the str pointer is to store the generated value in memory so that it can be destroyed during the destruction process.
String *toStringColony(Colony *this)
{

    if (this->str == NULL)
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
        // attemt created string exprassion to
        this->str = output;
        return output;
    }
    else
        return this->str;
}

// controlls the colony's life status, GameManager calls it after every single combat.
void colonyDeadControll(Colony *this)
{
    // controlling if food stock is under level zero.
    if (this->foodStock <= 0 || this->population <= 0)
    {
        this->amIALive = false;
    }
}