#include "../../include/game/GameManager.h"

GameManager *newGameManager(ArrayList *populations)
{
    // malloc
    GameManager *this = (GameManager *)malloc(sizeof(GameManager));
    // bind methods
    this->createPlayers = &createPlayersGm;

    this->logger = &loggerGm;
    this->destroy = &destroyGameManager;
    this->calculatePossibleWarCountPerRound = &calculatePossibleWarCountPerRoundGm;
    this->generateRandomSymbols = &generateRandomSymbolsGm;
    this->growOrganizer = &growOrganizerGm;
    this->battle = &battleGm;
    this->versus = &versusGm;
    // fields setup
    this->totalWarCount = 0;
    this->tour = -1;
    this->populations = populations; // done

    this->SelectedSymbols = createArrayList(10, INT); // CHANGE

    this->players = this->createPlayers(this);     // done
    this->toursLogPack = createArrayList(25, PTR); // done
}
int generateRandomSymbolsGm(ArrayList *selectedSymbolList) {}

ArrayList *createPlayersGm(GameManager *this)
{
    // popoulations array list stores intager values
    ArrayList *players = createArrayList(this->populations->size, _COLONY);
    Colony *colony;
    int i;
    for (i = 0; i < this->populations->size; i++)
    {
        colony = newColony(*(int *)this->populations->get(this->populations, i));
        players->append(players, colony);
    }
    return players;
}

ArrayList *loggerGm(ArrayList *colonies)
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

// a,b,c,d colonies. a vs b,c,d | b vs c,d | c vs d | 3+2+1=6
int calculatePossibleWarCountPerRoundGm(ArrayList *colonies)
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

void growOrganizerGm(ArrayList *players)
{
    Colony *col;
    int i = 0;
    for (i = 0; i < players->size; i++)
    {
        col = ((Colony *)players->get(players, i));
        col->grow(col);
    }
}

void battleGm(GameManager *this)
{
    Colony *c0;
    Colony *c1;
    // combat alghorithm
    int i, j = 0;
    for (i = 0; i < this->players->size - 1; i++)
    {
        c0 = ((Colony *)this->players->get(this->players, i));
        // controll c0 is alive
        if (c0->amIALive != true)
            continue;
        for (j = i + 1; j < this->players->size; j++)
        {
            c1 = ((Colony *)this->players->get(this->players, j));
            // controll c1 is alive
            if (c1->amIALive != true)
                continue;
            // The situation where 'c0' did not survive the combat with the previous colonies.
            if (c0->amIALive != true)
                break;
            this->versus(c0, c1); // FIGHTTTTTT
        }
    }
}

void versusGm(Colony *c0, Colony *c1)
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

        c0->victory++;
        c1->loose++;
    }
    else if (c0->fightPower < c1->fightPower)
    {
        ratio = (float)(c1->fightPower - c0->fightPower) / INDEX;
        c0->population -= c0->population * ratio; // reduce c0's(looser) population.

        // transfer c0's(looser) food stock to c1(winner)
        c1->foodStock += c0->foodStock * ratio;
        c0->foodStock -= c0->foodStock * ratio;

        c1->victory++;
        c0->loose++;
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

            c0->victory++;
            c1->loose++;
        }
        else if (c0->population < c1->population)
        {
            ratio = (float)(c1->population - c0->population) / INDEX;
            c0->population -= c0->population * ratio; // reduce c0's(looser) population.

            // transfer c0's(looser) food stock to c1(winner)
            c1->foodStock += c0->foodStock * ratio;
            c0->foodStock -= c0->foodStock * ratio;

            c1->victory++;
            c0->loose++;
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

                c0->victory++;
                c1->loose++;
            }
            else
            {
                // randomly colony1 is winner
                ratio = (float)(c1->foodStock, -c0->foodStock) / INDEX;
                c0->population -= c0->population * ratio; // reduce c0's(looser) population.

                // transfer c0's(looser) food stock to c1(winner)
                c1->foodStock += c0->foodStock * ratio;
                c0->foodStock -= c0->foodStock * ratio;

                c1->victory++;
                c0->loose++;
            }
        }
    }
    c0->reportLifeStatus(c0);
    c1->reportLifeStatus(c1);
    // above results: populations affected, foodstocks transfared, amIAlive updated
}

void destroyGameManager(GameManager *this)
{
    /*WILL BE CLEARED
    ArrayList *SelectedSymbols;
    ArrayList *players;
    ArrayList *toursLogPack;
    ArrayList *populations; destroy at out of gm
    */
    ArrayList *temp;

    // to destroy selected symbols arraylist
    if (this->SelectedSymbols != NULL)
    {
        temp = this->SelectedSymbols;
        temp->destroyArrayList(temp);
    }

    // to destroy players(colonies) arraylist
    if (this->players != NULL)
    {
        temp = this->players;
        temp->destroyArrayList(temp);
    }

    // to destroy players(colonies) arraylist, temp is list of log lists
    ArrayList *tmpLogList; // log list of one tour
    Log *tmpLog;           // log
    int i, j;
    if (this->toursLogPack != NULL)
    {
        temp = this->toursLogPack;

        for (i = 0; i < temp->size; i++)
        {
            tmpLogList = temp->get(this->toursLogPack, i);

            // roam through the log list.
            for (j = 0; j < tmpLogList->size; j++)
            {
                // destroy logs
                tmpLog = ((Log *)tmpLogList->get(tmpLogList, j));
                tmpLog->destroy(tmpLog);
            }
            // destroy log list
            tmpLogList->destroyArrayList(tmpLogList);
        }

        temp->destroyArrayList(temp);
    }

    // temp = this->populations; , outer parameter destroy at out of gm
    // temp->destroyArrayList(temp);
    free(this);
};
