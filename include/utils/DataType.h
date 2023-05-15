#if !defined(DATATYPE)
#define DATATYPE
#include "../colony/Colony.h"
#include "Bool.h"
#include "../log/Log.h"

// Enum of some data types supported by ArrayList in the project.

typedef enum
{
    CHAR,
    INT,
    PTR,
    _LOG,
    _ARRAYLIST,
    _COLONY,
    BOOL,
    _STRING,
    _GAME
} DataType;
extern char *DataTypeStrings[];
#endif // DATATYPES
