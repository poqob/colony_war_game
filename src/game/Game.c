#include "../../include/game/Game.h"

Game *newGame(GameManager *gameManager)
{
    // popoulations array list stores intager values

    Game *this = (Game *)malloc(sizeof(Game));
    this->gm = gameManager;
    this->destroy = &destroyGame;
    this->inspect = &gameInspect;
    this->play = &gamePlay;
};
void gamePlay(Game *game)
{
    DebugPrinter *dprinter = newDebugPrinter();
    int warCount = game->gm->calculatePossibleWarCountPerRound(game->gm->players);
    boolean isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;
    while (isThereMoreThanOneColonyALive == true)
    {

        game->gm->totalWarCount += warCount;
        game->gm->tour++;

        game->gm->battle(game->gm);
        // combatOrganizer(game->colonies);                                        // WORKS FINE
        game->gm->growOrganizer(game->gm->players);
        // growOrganizer(game->colonies);                                          // WORKS FINE
        game->gm->toursLogPack->append(game->gm->toursLogPack, game->gm->logger(game->gm->players)); // LOOGING

        warCount = game->gm->calculatePossibleWarCountPerRound(game->gm->players);
        isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;
        dprinter->print("tour: ", CHAR);
        dprinter->print(&game->gm->tour, INT);
        dprinter->print(" possible wars: ", CHAR);
        dprinter->print(&warCount, INT);
        dprinter->println(" ", CHAR);
    }
    dprinter->destroy(dprinter);
};

void gameInspect(Game *game)
{
    String *inspect;
    Colony *col;
    int i;
    for (i = 0; i < game->gm->players->size; i++)
    {
        col = ((Colony *)game->gm->players->get(game->gm->players, i));
        inspect = col->toString(col);
        inspect->appendChar(inspect, "@@@@@@@@@@@");
        inspect->appendInt(inspect, i);
        printf(inspect->str);
        inspect->destroy(inspect);
    }
};

void destroyGame(Game *this)
{
    // destroy the game
    free(this);
};