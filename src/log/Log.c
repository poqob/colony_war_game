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
    int count;
    String *temp;
    String *tostring = newString("");
    tostring->appendChar(tostring, &this->symbol);
    tostring->appendStr(tostring, newMultiplyString(" ", SPACING - 4));
    tostring->appendInt(tostring, this->population);

    // to calculate population's digits. by .len() method <--- i made it babyyyy....
    temp = newString("");
    temp->appendInt(temp, this->population);
    temp->trim(temp);

    count = 2 + SPACING - temp->len; // spacing between population and food stock
    temp->destroy(temp);
    temp = newMultiplyString(" ", count);
    tostring->appendStr(tostring, temp);
    temp->destroy(temp);

    temp = newString("");
    temp->appendInt(temp, this->foodStock);
    temp->trim(temp);
    count = SPACING - temp->len; // spacing between food stock and victory
    temp->destroy(temp);
    temp = newMultiplyString(" ", count);

    tostring->appendInt(tostring, this->foodStock);
    temp->trim(temp);
    tostring->appendStr(tostring, temp);

    temp->destroy(temp);
    temp = newString("");
    temp->appendInt(temp, this->victory);
    temp->trim(temp);
    count = 8 - temp->len; // spacing between victory and loose
    temp->destroy(temp);
    temp = newMultiplyString(" ", count);

    tostring->appendInt(tostring, this->victory);
    tostring->trim(tostring);
    tostring->appendStr(tostring, temp);

    tostring->appendInt(tostring, this->loose);
    // tostring->trim(tostring);
    this->str = tostring;

    // temp->destroy(temp); // ???????????

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