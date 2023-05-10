#include "../../include/game/Game.h"

// local function --private
void createPlayers(ArrayList *populations, Game *this)
{
    // popoulations array list stores intager values
    ArrayList *players = createArrayList(populations->size, _COLONY);
    Colony *colony;
    int i;
    for (i = 0; i < populations->size; i++)
    {
        colony = newColony(*(int *)populations->get(populations, i));
        players->append(players, colony);
    }
    // printf("\ncoloies size: %d", players->size);
    this->colonies = players;
}

// local function --private
void aVSb(Colony *c0, Colony *c1)
{
    // combat forces ratio ~ population ratio
    float ratio;
    if (c0->fightPower > c1->fightPower)
    {
        ratio = (float)(c0->fightPower - c1->fightPower) / INDEX;
        c1->population -= c1->population * ratio; // reduce c1's(looser) population.

        // transfer c1's(looser) food stock to c0(winner)
        c0->foodStock += c1->foodStock * ratio;
        c1->foodStock -= c1->foodStock * ratio;
    }
    else if (c0->fightPower < c1->fightPower)
    {
        ratio = (float)(c1->fightPower - c0->fightPower) / INDEX;
        c0->population -= c0->population * ratio; // reduce c0's(looser) population.

        // transfer c0's(looser) food stock to c1(winner)
        c1->foodStock += c0->foodStock * ratio;
        c0->foodStock -= c0->foodStock * ratio;
    }
    else // c0:fp == c1:fp situation
    {
        // compare population scales.
        if (c0->population > c1->population)
        {
            ratio = (float)(c0->population - c1->population) / INDEX;
            c1->population -= c1->population * ratio; // reduce c1's(looser) population.

            // transfer c1's(looser) food stock to c0(winner)
            c0->foodStock += c1->foodStock * ratio;
            c1->foodStock -= c1->foodStock * ratio;
        }
        else if (c0->population < c1->population)
        {
            ratio = (float)(c1->population - c0->population) / INDEX;
            c0->population -= c0->population * ratio; // reduce c0's(looser) population.

            // transfer c0's(looser) food stock to c1(winner)
            c1->foodStock += c0->foodStock * ratio;
            c0->foodStock -= c0->foodStock * ratio;
        }
        else // c0:population equals c1:population situation
        {
            // ratio depends on foodStocks
            srand(time(NULL)); // Seed the random number generator with the current time
            if ((rand() % 2) == 0)
            {
                // randomly colony0 is winner
                ratio = (float)(c0->foodStock - c1->foodStock) / INDEX;
                c1->population -= c1->population * ratio; // reduce c1's(looser) population.

                // transfer c1's(looser) food stock to c0(winner)
                c0->foodStock += c1->foodStock * ratio;
                c1->foodStock -= c1->foodStock * ratio;
            }
            else
            {
                // randomly colony1 is winner
                ratio = (float)(c1->foodStock, -c0->foodStock) / INDEX;
                c0->population -= c0->population * ratio; // reduce c0's(looser) population.

                // transfer c0's(looser) food stock to c1(winner)
                c1->foodStock += c0->foodStock * ratio;
                c0->foodStock -= c0->foodStock * ratio;
            }
        }
    }
    // above results: populations affected, foodstocks transfared.
}

// local function --private
/*
All members of the colony list should fight only once with each other.
 'i' represents the colony that is being held and it is the turn to fight.
  'j' represents the colonies that have not yet fought (ready to fight) with 'i'
  */
void combatOrganizer(ArrayList *cols)
{
    Colony *c0;
    Colony *c1;
    // combat alghorithm
    int i, j = 0;
    for (i = 0; i < cols->size - 1; i++)
    {
        c0 = ((Colony *)cols->get(cols, i));

        for (j = i + 1; j < cols->size; j++)
        {
            c1 = ((Colony *)cols->get(cols, j));
            aVSb(c0, c1); // FIGHTTTTTT
        }
    }
}

void growOrganizer(ArrayList *cols)
{
    Colony *col;
    int i = 0;
    for (i = 0; i < cols->size; i++)
    {
        col = ((Colony *)cols->get(cols, i));
        col->grow(col);
    }
}

// local function --private
// a,b,c,d colonies. a vs b,c,d | b vs c,d | c vs d | 3+2+1=6
int calculatePossibleWarCountPerRound(ArrayList *colonies)
{
    int colonyCount = 0;
    int i;
    // to count alive colonies.
    for (i = 0; i < colonies->size; i++)
    {
        if (((Colony *)colonies->get(colonies, i))->amIALive == true)
        {
            colonyCount++;
        }
    }

    // return total war count
    if (colonyCount % 2 == 0)
        return (((colonyCount) / 2) - 1) * colonyCount + (colonyCount / 2);
    else
        return (colonyCount / 2) * colonyCount;
}

Game *newGame(ArrayList *populations)
{
    // popoulations array list stores intager values
    Game *this = (Game *)malloc(sizeof(Game));
    this->destroy = &destroyGame;
    this->inspect = &gameInspect;
    this->play = &gamePlay;
    createPlayers(populations, this);
    this->tour = -1;
    this->totalWarCount = 0;
    this->toursLogPack = createArrayList(100, PTR);
};

ArrayList *logger(ArrayList *colonies)
{
    // DebugPrinter *dprinter = newDebugPrinter();
    ArrayList *logs = createArrayList(colonies->size + 1, _LOG);
    Colony *colony;
    Log *log;

    int i;
    for (i = 0; i < colonies->size; i++)
    {
        colony = ((Colony *)colonies->get(colonies, i));
        log = newLog(colony);
        // dprinter->println(log, _LOG);
        logs->append(logs, log);
    }

    return logs;
}

void gamePlay(Game *game)
{

    int warCount = calculatePossibleWarCountPerRound(game->colonies);
    boolean isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;
    while (isThereMoreThanOneColonyALive == true)
    {

        game->totalWarCount += warCount;
        game->tour++;

        combatOrganizer(game->colonies); // WORKS FINE

        game->toursLogPack->append(game->toursLogPack, logger(game->colonies));

        growOrganizer(game->colonies); // WORKS FINE

        warCount = calculatePossibleWarCountPerRound(game->colonies);
        isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;
    }
};

void gameInspect(Game *game)
{
    String *inspect;
    Colony *col;
    int i;
    for (i = 0; i < game->colonies->size; i++)
    {
        col = ((Colony *)game->colonies->get(game->colonies, i));
        inspect = col->toString(col);
        inspect->appendChar(inspect, "@@@@@@@@@@@");
        inspect->appendInt(inspect, i);
        printf(inspect->str);
        inspect->destroy(inspect);
    }
};

void destroyGame(Game *this)
{
    ArrayList *list; // temp arraylist
    Log *log;        // temp log
    int i, j;        // loop variables

    // roam through the this->toursLogPack which stores arraylists for each tour logs.
    for (i = 0; i < this->toursLogPack->size; i++)
    {
        list = this->toursLogPack->get(this->toursLogPack, i);

        // roam through the log list.
        for (j = 0; j < list->size; j++)
        {
            // destroy logs
            log = ((Log *)list->get(list, j));
            log->destroy(log);
        }
        // destroy log list
        list->destroyArrayList(list);
    }
    // destroy list of lists
    this->toursLogPack->destroyArrayList(this->toursLogPack);
    // destroy colonies
    this->colonies->destroyArrayList(this->colonies);
    // destroy the game
    free(this);
};