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
    String *temp;
    String *tostring = newString("");
    tostring->appendChar(tostring, &this->symbol);
    tostring->appendStr(tostring, newMultiplyString(" ", SPACING - 4));
    tostring->appendInt(tostring, this->population);

    // to calculate population's digits. by .len() method <--- i made it babyyyy....
    temp = newString("");
    temp->appendInt(temp, this->population);
    temp->trim(temp);

    int s = 3 + SPACING - temp->len; // spacing between population and food stock
    tostring->appendStr(tostring, newMultiplyString(" ", s));

    temp->destroy(temp);
    temp = newString("");
    temp->appendInt(temp, this->foodStock);
    temp->trim(temp);
    s = SPACING - temp->len; // spacing between food stock and victory

    tostring->appendInt(tostring, this->foodStock);
    tostring->appendStr(tostring, newMultiplyString(" ", s));

    temp->destroy(temp);
    temp = newString("");
    temp->appendInt(temp, this->victory);
    temp->trim(temp);
    s = 8 - temp->len; // spacing between victory and loose

    tostring->appendInt(tostring, this->victory);
    tostring->appendStr(tostring, newMultiplyString(" ", s));

    temp->destroy(temp); // temp DESTROYYYYEDDDD

    tostring->appendInt(tostring, this->loose);
    this->str = tostring;
    tostring->trim(tostring);
    return tostring;
}

void logDestroy(Log *this)
{
    if (this->str != NULL)
    {
        this->str->destroy(this->str);
    }

    free(this);
}