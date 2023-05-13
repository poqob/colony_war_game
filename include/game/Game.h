#if !defined(GAME)
#define GAME
#include "../colony/Colony.h"
#include "../utils/String.h"
#include "../utils/Bool.h"
#include "../utils/ArrayList.h"
#include "../log/Log.h"
#include <time.h>
#include "GameManager.h"

typedef struct Game Game;

struct Game
{
    GameManager *gm;
    void (*inspect)(Game *);
    void (*destroy)(Game *);
    void (*play)(Game *);
};

Game *newGame(GameManager *);
void destroyGame(Game *game);
void gameInspect(Game *game);
void gamePlay(Game *game);

#endif // GAME
