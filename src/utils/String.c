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
    this->len += strlen(str->str);
    strcat(this->str, str->str);
}

void appendIntager(String *this, int val)
{
    char str[10]; // intager ,Number of digits
    sprintf(str, "%d", val);
    this->len += strlen(str);
    strcat(this->str, str);
}

void appendCharacterArray(String *this, char *val)
{
    this->len += strlen(val);
    strcat(this->str, val);
}
