#include "../../include/utils/DebugPrinter.h"

DebugPrinter *newDebugPrinter()
{
    DebugPrinter *this = (DebugPrinter *)malloc(sizeof(DebugPrinter));
    this->destroy = &destroyDebugPrinter;
    this->print = &printDebugPrinter;
    this->println = &printlnDebugPrinter;
    return this;
}
// dynamic print
void printDebugPrinter(void *exprassion, DataType dataType)
{
    Colony *colony;
    Log *log;
    switch (dataType)
    {
    case CHAR:
        printf("%s", ((char *)exprassion));
        break;
    case INT:
        printf("%d", ((int *)exprassion));
        break;
    case PTR:
        printf("void");
        break;
    case BOOL:
        printf("%d", ((int *)exprassion));
        break;
    case _COLONY:

        colony = ((Colony *)exprassion);
        printf("%s", colony->toString(colony)->str);
        break;
    case _STRING:
        printf("%s", ((String *)exprassion)->str);
        break;
    case _LOG:
        log = ((Log *)exprassion);
        printf("%s", log->toString(log)->str);
        break;
    default:
        printf("UNSPORTED DATA TYPE");
        break;
    }
}

// dynamic print line
void printlnDebugPrinter(void *exprassion, DataType dataType)
{
    Colony *colony;
    Log *log;
    switch (dataType)
    {
    case CHAR:
        printf("%s\n", ((char *)exprassion));
        break;
    case INT:
        printf("%d\n", ((int *)exprassion));
        break;

    case PTR:
        printf("void\n");
        break;
    case BOOL:
        printf("%d\n", ((int *)exprassion));
        break;
    case _COLONY:

        colony = ((Colony *)exprassion);
        printf("%s\n", colony->toString(colony)->str);
        break;
    case _STRING:
        printf("%s\n", ((String *)exprassion)->str);
        break;
    case _LOG:
        log = ((Log *)exprassion);
        printf("%s\n", log->toString(log)->str);
        break;

    default:
        printf("UNSPORTED DATA TYPE");
        break;
    }
}

void destroyDebugPrinter(DebugPrinter *this)
{
    free(this);
}