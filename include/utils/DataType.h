#if !defined(DATATYPE)
#define DATATYPE
#include "../colony/Colony.h"
#include "Bool.h"

#define COLONY_SIZE sizeof(Colony)
#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)

typedef enum
{
    CHAR = CHAR_SIZE,
    INT = INT_SIZE,
    _COLONY = COLONY_SIZE,
    BOOL = COLONY_SIZE + 1,
    _STRING = BOOL + 1,
    _LOG = _STRING + 1,
} DataType;
extern char *DataTypeStrings[];
#endif // DATATYPES
