#include "../../include/utils/String.h"

// add them to prevent compile time warnings(not error).
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
void *strcat(char *dest, const char *src);

String *newString(char *s)
{
    String *str = malloc(sizeof(String));
    str->len = strlen(s);
    str->str = malloc(str->len + 1);
    strcpy(str->str, s);
    str->destroy = &destroyString;
    str->getSize = &getStringSize;
    str->appendStr = &appendString;
    str->appendInt = &appendIntager;
    str->appendChar = &appendCharacterArray;
    return str;
}

void destroyString(String *str)
{
    free(str->str);
    free(str);
}

int getStringSize(String *str)
{
    return (str->len / sizeof(char)) + 1;
}

void appendString(String *this, String *str)
{
    this->len += strlen(str->str) + 1;         // update lenght of string
    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, str->str);               // add new characters.
}

void appendIntager(String *this, int val)
{
    char str[10];                              // intager ,Number of digits
    sprintf(str, "%d", val);                   // attempt int value to str as char array
    this->len += strlen(str) + 1;              // update lenght of string
    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, str);                    // add new characters.
}

void appendCharacterArray(String *this, char *val)
{
    this->len += strlen(val) + 1;              // update lenght of string
    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, val);                    // add new characters.
}
