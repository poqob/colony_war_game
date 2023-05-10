#if !defined(GAME)
#define GAME
#include "../colony/Colony.h"
#include "../utils/String.h"
#include "../utils/Bool.h"
#include "../utils/ArrayList.h"
#include "../log/Log.h"
#include "../utils/DebugPrinter.h"
#include <time.h>

typedef struct Game Game;

struct Game
{
    ArrayList *colonies;
    int totalWarCount;
    int tour;
    ArrayList *toursLogPack;
    void (*inspect)(Game *);
    void (*destroy)(Game *);
    void (*play)(Game *);
};

Game *newGame(ArrayList *populations);
void destroyGame(Game *game);
void gameInspect(Game *game);
void gamePlay(Game *game);

#endif // GAME
