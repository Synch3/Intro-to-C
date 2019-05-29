#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int length = string_length(y);
    printf("length: %d\n", length);

    for (int i = 0; i <= length; i++)
    {
        x[i] = y[i];
        printf("%s\n", x);
    }
    printf("%s\n", x);
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    int length = strlen(str);
    char *pointer = NULL;
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            pointer = &str[i];
        }
    }
    return pointer;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    while(*haystack != '\0'){
        if(*haystack == *needle){
            char *pointer = haystack;
            while(*haystack == *needle && *needle != '\0'){
                haystack = haystack + 1;
                needle = needle + 1;
            }
            if(*needle == '\0'){
                return pointer;
            }
        }
        haystack = haystack + 1;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
