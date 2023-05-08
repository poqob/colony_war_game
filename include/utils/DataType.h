#if !defined(DATATYPE)
#define DATATYPE
#include "../colony/Colony.h"

#define COLONY_SIZE sizeof(Colony)
typedef enum
{
    CHAR = 1,
    INT = 4,
    _COLONY = COLONY_SIZE
} DataType;

#endif // DATATYPES
