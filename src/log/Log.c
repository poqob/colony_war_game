#include "../../include/log/Log.h"

// Constructor of Log
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

// The most important method :D Log's main purpose is providing data about the colony to user-console.
// output shall be like if colony is alive then contains data about colony if not only contains "--" for every column.
String *logToString(Log *this)
{
    int count;
    String *temp;
    String *tostring = newString("");
    tostring->appendChar(tostring, &this->symbol);
    tostring->appendStr(tostring, newMultiplyString(" ", SPACING - 4));

    if (this->amIALive == true)
    {
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
    }
    else
    {
        tostring->appendChar(tostring, "--");

        // to calculate population's digits. by .len() method <--- i made it babyyyy....
        temp = newString("");
        temp->appendChar(temp, "--");
        temp->trim(temp);

        count = 2 + SPACING - temp->len; // spacing between population and food stock
        temp->destroy(temp);
        temp = newMultiplyString(" ", count);
        tostring->appendStr(tostring, temp);
        temp->destroy(temp);

        temp = newString("");
        temp->appendChar(temp, "--");

        temp->trim(temp);
        count = SPACING - temp->len; // spacing between food stock and victory
        temp->destroy(temp);
        temp = newMultiplyString(" ", count);

        tostring->appendChar(tostring, "--");
        temp->trim(temp);
        tostring->appendStr(tostring, temp);

        temp->destroy(temp);
        temp = newString("");
        temp->appendChar(temp, "--");
        temp->trim(temp);
        count = 8 - temp->len; // spacing between victory and loose
        temp->destroy(temp);
        temp = newMultiplyString(" ", count);

        tostring->appendChar(tostring, "--");
        tostring->trim(tostring);
        tostring->appendStr(tostring, temp);

        tostring->appendChar(tostring, "--");
        // tostring->trim(tostring);
    }

    this->str = tostring;

    // temp->destroy(temp); // ???????????

    return tostring;
}

// destructor
void logDestroy(Log *this)
{
    // destructure of  Log's str variable. (if Log's toString() method called and a result created on memory.)
    if (this->str != NULL)
        this->str->destroy(this->str);
    // destruction of Log structure
    free(this);
}