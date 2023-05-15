#include "../../include/utils/String.h"

// i added them to prevent compile time warnings(not error).
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
void *strcat(char *dest, const char *src);

// constructor
String *newString(char *s)
{
    String *this = malloc(sizeof(String));
    this->len = strlen(s);
    this->str = malloc(this->len + 1);
    strcpy(this->str, s);
    this->destroy = &destroyString;
    this->getSize = &getStringSize;
    this->appendStr = &appendString;
    this->appendInt = &appendIntager;
    this->appendChar = &appendCharacterArray;
    this->trim = &trimString;
    return this;
}

// destructor
void destroyString(String *str)
{
    free(str->str);
    free(str);
}

// to obtain size of string
int getStringSize(String *str)
{
    return (str->len / sizeof(char)) + 1;
}

// string append function to a string
void appendString(String *this, String *str)
{
    this->len += strlen(str->str) + 1;         // update lenght of string
    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, str->str);               // add new characters.
}

// intager append to a string function
// Use trim. Normally, str's length is 10 characters, even though val's length is not.
void appendIntager(String *this, int val)
{
    char str[10];                 // intager ,Number of digits
    sprintf(str, "%d", val);      // attempt int value to str as char array
    this->len += strlen(str) + 1; // update lenght of string

    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, str);                    // add new characters.
}

// char* append to a String exprassion function
void appendCharacterArray(String *this, char *val)
{
    this->len += strlen(val) + 1;              // update lenght of string
    this->str = realloc(this->str, this->len); // realloc memory because we gonna add new characters to our array
    strcat(this->str, val);                    // add new characters.
}

// trim method
String *trimString(String *this)
{
    int newlen = 0;
    char *roam;
    char *str = this->str;
    char *end;

    // Trim leading whitespace
    while (isspace(*str))
    {
        str++;
    }

    if (*str == '\0')
    { // String is all whitespace
        return this;
    }

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end))
    {
        end--;
    }
    *(end + 1) = '\0';

    // calculate new len
    for (roam = str; roam < end; roam++)
        newlen++;

    this->len = newlen + 1;
    this->str = realloc(this->str, *end);

    return this;
}

// create multipled string.
/*
String* test= newMultiplyString("zort", 3);
assert(test->str=="zortzortzort"); true
*/
String *newMultiplyString(char *chararr, int count)
{
    String *multiple;
    int len = (strlen(chararr) * count) + 1;
    char *result = (char *)malloc(len);
    result[0] = '\0'; // Initialize result string

    for (int i = 0; i < count; i++)
    {
        strcat(result, chararr);
    }

    result[len - 1] = '\0'; // Place null-terminator at correct index
    multiple = newString(result);
    multiple->trim(multiple); // Call trim on the String object's char array
    return multiple;
}
