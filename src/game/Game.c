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

    int i;
    for (i = 0; i < colonies->size; i++)
    {
        printf("%d ", ((Colony *)colonies->get(colonies, i))->population);
    }

    INDEX;
}

Game *newGame(ArrayList *populations)
{
    // popoulations array list stores intager values
    Game *this = (Game *)malloc(sizeof(Game));
    this->destroy = &destroyGame;
    this->report = &gameReport;
    this->play = &gamePlay;
    createPlayers(populations, this);
    //  printf("\ncoloies size: %d", this->colonies->size);
};

void gamePlay(Game *game)
{
    colonyFight(game->colonies);
};

void gameReport(Game *game){};

void destroyGame(Game *this)
{
    this->colonies->destroyArrayList(this->colonies);
    free(this);
};