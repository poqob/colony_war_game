#if !defined(GAMEMANAGER)
#define GAMEMANAGER

#include "../colony/Colony.h"
#include "../utils/String.h"
#include "../utils/Bool.h"
#include "../utils/ArrayList.h"
#include "../log/Log.h"
#include "../utils/DebugPrinter.h"
#include <time.h>
typedef struct GameManager GameManager;
struct GameManager
{
    // fields
    ArrayList *SelectedSymbols;
    ArrayList *players;
    ArrayList *toursLogPack;
    ArrayList *populations;
    int totalWarCount;
    int tour;

    // methods
    ArrayList *(*createPlayers)(GameManager *);
    void (*destroy)(GameManager *);
    ArrayList *(*logger)(ArrayList *);
    int (*calculatePossibleWarCountPerRound)(ArrayList *); // players
    void (*growOrganizer)(ArrayList *);                    // players
    int (*generateRandomSymbols)(ArrayList *);             // this selected symbols arraylist
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
int generateRandomSymbolsGm(ArrayList *);             // this selected symbols arraylist
void battleGm(GameManager *);                         // this
void versusGm(Colony *, Colony *);

#endif // GAMEMANAGER
