#if !defined(GAME)
#define GAME
#include "../colony/Colony.h"
#include "../utils/String.h"
#include "../utils/Bool.h"
#include "../utils/ArrayList.h"

typedef struct Game Game;

struct Game
{
    ArrayList *colonies;
    void (*createColonies)(ArrayList *, Game *);
    void (*turn)(ArrayList *);
    void (*report)(ArrayList *);
    void (*destroy)(Game *);
};

Game *newGame(ArrayList *populations);
void createPlayers(ArrayList *populations, Game *this);
void destroyGame(Game *game);
void gameTurn(ArrayList *colonies);
void gameReport(ArrayList *colonies);

#endif // GAME
