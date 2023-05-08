#include "../../include/game/Game.h"

void createPlayers(ArrayList *populations, Game *this)
{
    // popoulations array list stores intager values
    ArrayList *players = createArrayList(populations->size, COLONYY);
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
void gameTurn(ArrayList *colonies){};
void gameReport(ArrayList *colonies){};

void destroyGame(Game *this)
{
    this->colonies->destroyArrayList(this->colonies);
    free(this);
};
Game *newGame(ArrayList *populations)
{
    // popoulations array list stores intager values
    Game *this = (Game *)malloc(sizeof(Game));
    this->createColonies = &createPlayers;
    this->destroy = &destroyGame;
    this->turn = &gameTurn;
    this->report = &gameReport;
    createPlayers(populations, this);
    // printf("\ncoloies size: %d", this->colonies->size);
}