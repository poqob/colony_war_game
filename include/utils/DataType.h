#if !defined(DATATYPE)
#define DATATYPE
#include "../colony/Colony.h"
#include "Bool.h"
#include "../log/Log.h"

#define COLONY_SIZE sizeof(Colony)
#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)
#define LOG_SIZE sizeof(Log)

typedef enum
{
    CHAR = CHAR_SIZE,
    INT = INT_SIZE,
    _LOG = LOG_SIZE,
    _ARRAYLIST = 64,
    _COLONY = COLONY_SIZE,
    BOOL = COLONY_SIZE + 1,
    _STRING = BOOL + 1,
} DataType;
extern char *DataTypeStrings[];
#endif // DATATYPES
