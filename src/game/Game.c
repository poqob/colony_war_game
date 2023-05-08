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
// TODO: to complate
void colonyFight(ArrayList *colonies)
{
    Colony *colony;
    int i;
    for (i = 0; i < colonies->size; i++)
    {
        colony = ((Colony *)colonies->get(colonies, i));
        printf("%d ", colony->manufacturePower);
    }

    INDEX;
}

// local function --private
int calculatePossibleWarCount(int colonyCount)
{
    int result;

    if (colonyCount % 2 == 0)
        return (((colonyCount) / 2) - 1) * colonyCount + colonyCount / 2;
    else
        return (colonyCount / 2) * colonyCount;
}

Game *newGame(ArrayList *populations)
{
    // popoulations array list stores intager values
    Game *this = (Game *)malloc(sizeof(Game));
    this->destroy = &destroyGame;
    this->report = &gameReport;
    this->play = &gamePlay;
    createPlayers(populations, this);
    this->tour = 0;
    this->totalWarCount = calculatePossibleWarCount(this->colonies->size);
};

// TODO: works like: in while loop, play-analyze-play ; analyze: Keep playing until there is only one colony left. ; update possible war count after every tour.
// TODO: What is the total number of wars that can be experienced among colonies? CALCULATE Done.
// TODO: update calculatePossibleWarCount method, new parameters : colony list or colonies that are still alive.
void gamePlay(Game *game)
{
    int i;
    for (i = 0; i < game->totalWarCount; i++)
    {
    }
};

// TODO: console output after every tour.
void gameReport(Game *game){};

void destroyGame(Game *this)
{
    this->colonies->destroyArrayList(this->colonies);
    free(this);
};