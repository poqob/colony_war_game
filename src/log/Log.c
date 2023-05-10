#include "../../include/log/Log.h"

Log *newLog(Colony *colony)
{
    Log *this = (Log *)malloc(sizeof(Log)); // allocate
    this->amIALive = colony->amIALive;
    this->foodStock = colony->foodStock;
    this->loose = colony->loose;
    this->population = colony->population;
    this->symbol = colony->symbol;
    this->victory = colony->victory;
    this->destroy = &logDestroy;
    this->toString = &logToString;
    return this;
}

String *logToString(Log *this)
{
    String *tostring = newString("");
    tostring->appendChar(tostring, &this->symbol);
    tostring->appendChar(tostring, "\t\t");
    tostring->appendInt(tostring, this->population);
    tostring->appendChar(tostring, "\t\t");
    tostring->appendInt(tostring, this->foodStock);
    tostring->appendChar(tostring, "\t\t");
    tostring->appendInt(tostring, this->victory);
    tostring->appendChar(tostring, "\t\t");
    tostring->appendInt(tostring, this->loose);
    return tostring;
}

void logDestroy(Log *this)
{
    free(this);
}