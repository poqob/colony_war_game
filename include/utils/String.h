#if !defined(STRING)
#define STRING
#include <stdlib.h>
#include <string.h>

typedef struct String String;
struct String
{
    char *str;
    int len;
    void (*destroy)(String *this);
    int (*getSize)(String *this);
    void (*append)(String *this, String *string);
};

String *newString(char *s);
void destroyString(String *str);
int getStringSize(String *str);
void appendString(String *this, String *str);
#endif // STRING
