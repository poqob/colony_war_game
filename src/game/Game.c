#include "../../include/game/Game.h"

// constructor of the Game struct
Game *newGame(GameManager *gameManager)
{

    Game *this = (Game *)malloc(sizeof(Game));
    this->gm = gameManager;
    this->destroy = &destroyGame;
    this->inspect = &gameInspect;
    this->play = &gamePlay;
    return this;
};

// gamePlay() method calculates all possible combat counts and sends colonies to Game's GameManager structure.
// in a while loop gamePlay plays every tour.
// Every turn, the GameManager pits the colonies against each other, manages their growth, and controls the flow of data.
void gamePlay(Game *game)
{
    // calculating possible war count for first tour.
    int warCount = game->gm->calculatePossibleWarCountPerRound(game->gm->players);
    // controlling if there is or not exist any combat to determine alive colony is more then one.
    boolean isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;
    // The "while" loop that counts turns depending on the condition "isThereMoreThanOneColonyAlive".
    while (isThereMoreThanOneColonyALive == true)
    {

        game->gm->totalWarCount += warCount;
        game->gm->tour++; // increase tour count

        game->gm->toursLogPack->append(game->gm->toursLogPack, game->gm->logger(game->gm->players)); // LOOGING colonies for each turn.
        game->gm->battle(game->gm);                                                                  // colony combats organized in GameManager::battle(), colony combats
        game->gm->growOrganizer(game->gm->players);                                                  // Basically, it calls the grow() method of each colony, which also includes the produce() method.
        warCount = game->gm->calculatePossibleWarCountPerRound(game->gm->players);                   // calculating possible war count for next tour.
        isThereMoreThanOneColonyALive = (warCount != 0) ? true : false;                              // to determine alive colony is more then one.
    }
    game->gm->toursLogPack->append(game->gm->toursLogPack, game->gm->logger(game->gm->players)); // LOOGING colonies for last turn.
};

// GameInspect shows detailed information about colonies. it was a develop time method.
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
    }
};

// destructor.
/*
NOTE:
I found it appropriate to perform destruction at the point where
GameManager is assigned to the Game structure because it is created outside of Game.
*/
void destroyGame(Game *this)
{
    // destroy the game
    free(this);
};