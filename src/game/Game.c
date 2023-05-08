#include "../../include/game/Game.h"

void createPlayers(ArrayList *populations, Game *this)
{
    // popoulations array list stores intager values
    ArrayList *players = createArrayList(populations->size, COLONYY);
    Colony *colony;
    int i;
    for (i = 0; i < populations->size; i++)
    {
        // colony = newColony(populations[i]);
        printf("\n%d.", *(int *)populations->get(populations, i));
    }
    printf("\n");
    populations->display(populations);
}
void destroyGame(Game *game){};
void gameTurn(ArrayList *colonies){};
void gameReport(ArrayList *colonies){};

Game *newGame(ArrayList *populations)
{
    // popoulations array list stores intager values
    Game *this = (Game *)malloc(sizeof(Game));
    this->createColonies = &createPlayers;
    this->destroy = &destroyGame;
    this->turn = &gameTurn;
    this->report = &gameReport;
    createPlayers(populations, this);
}