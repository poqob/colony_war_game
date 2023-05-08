#include "../../include/utils/String.h"
#include <string.h>

// add them to prevent compile time warnings(not error).
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);

String *newString(char *s)
{
    String *str = malloc(sizeof(String));
    str->len = strlen(s);
    str->str = malloc(str->len + 1);
    strcpy(str->str, s);
    str->destroy = &destroyString;
    str->getSize = &getStringSize;
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