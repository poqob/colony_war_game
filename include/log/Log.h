#if !defined(LOG)
#define LOG

#include "../colony/Colony.h"

/*The Log structure is created to keep track of the current status of colonies at the end of each turn.
 Providing a colony as a parameter to its constructor function is sufficient for recording purposes.*/

#define SPACING 14
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
