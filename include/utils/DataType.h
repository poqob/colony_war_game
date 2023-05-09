#if !defined(DATATYPE)
#define DATATYPE
#include "../colony/Colony.h"

#define COLONY_SIZE sizeof(Colony)
#define CHAR_SIZE sizeof(char)
#define INT_SIZE sizeof(int)
typedef enum
{
    CHAR = CHAR_SIZE,
    INT = INT_SIZE,
    _COLONY = COLONY_SIZE
} DataType;
extern char *DataTypeStrings[];
#endif // DATATYPES
