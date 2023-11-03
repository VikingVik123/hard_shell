#include "main.h"

/**
 * _getline - Custom getline function to read a line of input
 * @lineptr: A pointer to a pointer to store the input line
 * @n: A pointer to a size_t variable to track allocated memory
 * @stream: The input stream (e.g., stdin)
 *
 * Return: The number of characters read, or -1 on error or EOF.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    ssize_t number_of_characters_read;

    number_of_characters_read = getline(lineptr, n, stream);

    if (number_of_characters_read == -1) {
        free(*lineptr);
        *lineptr = NULL;
    } else if (number_of_characters_read == 1 && (*lineptr)[0] == '\n') {
        free(*lineptr);
        *lineptr = NULL;
    } else {
        if ((*lineptr)[number_of_characters_read - 1] == '\n') {
            (*lineptr)[number_of_characters_read - 1] = '\0';
        }
    }

    return number_of_characters_read;
}
