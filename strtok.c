#include "main.h"

/**
 * _strtok - Custom strtok function
 * @str: String to tokenize
 * @delim: Delimiter characters
 * Return: Pointer to the next token
 */
char *_strtok(char *str, const char *delim)
{
    static char *last_token = NULL;  /* Keeps track of the last token */
    char *start;
    if (str != NULL)
        last_token = str;

    if (last_token == NULL || *last_token == '\0')
        return NULL;

    /* Skip leading delimiters */
    while (*last_token != '\0' && strchr(delim, *last_token) != NULL)
        last_token++;

    if (*last_token == '\0')
    {
        last_token = NULL;
        return NULL;
    }

    start = last_token;
    while (*last_token != '\0' && strchr(delim, *last_token) == NULL)
        last_token++;

    if (*last_token != '\0')
        *last_token++ = '\0';  /* Null-terminate the token */

    return start;
}
