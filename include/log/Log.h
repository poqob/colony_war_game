#if !defined(LOG)
#define LOG
#define SPACING 14
#include "../colony/Colony.h"

typedef struct Log Log;
struct Log
{
    // fields
    int foodStock;
    int population;
    boolean amIALive;
    char symbol;
    int victory;
    int loose;
    String *str;

    String *(*toString)(Log *);
    void (*destroy)(Log *);
};
Log *newLog(Colony *);
void logDestroy(Log *);
String *logToString(Log *);
#endif // LOG
