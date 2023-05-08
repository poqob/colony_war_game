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
    void (*report)(Game *);
    void (*destroy)(Game *);
    void (*play)(Game *);
};

Game *newGame(ArrayList *populations);
void destroyGame(Game *game);
void gameReport(Game *game);
void gamePlay(Game *game);

#endif // GAME
