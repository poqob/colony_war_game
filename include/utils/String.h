#if !defined(STRING)
#define STRING
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct String String;
struct String
{
    char *str;
    int len;
    void (*destroy)(String *this);
    int (*getSize)(String *this);
    void (*appendStr)(String *this, String *string);
    void (*appendInt)(String *this, int val);
};

String *newString(char *s);
void destroyString(String *str);
int getStringSize(String *str);
void appendString(String *this, String *str);
void appendIntager(String *this, int val);
#endif // STRING
