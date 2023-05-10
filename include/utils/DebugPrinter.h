#if !defined(DEBUG_PRINTER)
#define DEBUG_PRINTER
#include "../log/Log.h"
#include "DataType.h"
typedef struct DebugPrinter DebugPrinter;

struct DebugPrinter
{
    void (*print)(void *, DataType);
    void (*println)(void *, DataType);
    void (*destroy)(DebugPrinter *);
};
DebugPrinter *newDebugPrinter();
void printDebugPrinter(void *, DataType);
void printlnDebugPrinter(void *, DataType);
void destroyDebugPrinter(DebugPrinter *);

#endif // DEBUG_PRINTER
