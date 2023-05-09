#if !defined(STRING)
#define STRING
#include <stdlib.h>
typedef struct String String;
struct String
{
    char *str;
    int len;
    void (*destroy)(String *string);
    int (*getSize)(String *string);
    void (*append)(String *string);
};

String *newString(char *s);
void destroyString(String *str);
int getStringSize(String *str);
void appendString(String *this, String *str);
#endif // STRING
