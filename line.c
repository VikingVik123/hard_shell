#include "main.h"

int handle_line_result(ssize_t line, char **lineptr, char **lineptr_cpy)
{
    if (line == -1) {
        free(*lineptr);
        *lineptr = NULL;
        return 0; /* Exit the shell*/
    }
    if (line == 1 && (*lineptr)[0] == '\n') {
        free(*lineptr);
        *lineptr = NULL;
        return 1; /*Continue the shell*/
    } else {
        *lineptr_cpy = _strdup(*lineptr);

        if (*lineptr_cpy == NULL) {
            perror("tsh: memory allocation error");
            free(*lineptr);
            *lineptr = NULL;
            return 0; /* Exit the shell*/
        }
    }
    return 1; /* Continue the shell*/
}
