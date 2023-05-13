#if !defined(GAMEMANAGER)
#define GAMEMANAGER
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../colony/Colony.h"
#include "../utils/String.h"
#include "../utils/Bool.h"
#include "../utils/ArrayList.h"
#include "../log/Log.h"
#include "../utils/DebugPrinter.h"
#define MAX_SYMBOL_COUNT 40
typedef struct GameManager GameManager;
struct GameManager
{
    // fields
    ArrayList *SelectedSymbols;
    ArrayList *players;
    ArrayList *toursLogPack;
    ArrayList *populations;
    int *allSymbols;
    int totalWarCount;
    int tour;

    // methods
    ArrayList *(*createPlayers)(GameManager *);
    ArrayList *(*logger)(ArrayList *);
    void (*destroy)(GameManager *);
    int (*calculatePossibleWarCountPerRound)(ArrayList *); // players
    void (*growOrganizer)(ArrayList *);                    // players
    void *(*generateRandomSymbols)(GameManager *);         // this selected symbols arraylist
    void (*battle)(GameManager *);                         // this
    void (*versus)(Colony *, Colony *);
};
// functions
GameManager *newGameManager(ArrayList *);             // populations
void growOrganizerGm(ArrayList *);                    // players
ArrayList *createPlayersGm(GameManager *);            // game manager
void destroyGameManager(GameManager *);               // this game manager
ArrayList *loggerGm(ArrayList *);                     // players
int calculatePossibleWarCountPerRoundGm(ArrayList *); // players
void *generateRandomSymbolsGm(GameManager *);         // this selected symbols arraylist
void battleGm(GameManager *);                         // this
void versusGm(Colony *, Colony *);

#endif // GAMEMANAGER
