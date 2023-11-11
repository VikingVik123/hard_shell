#include "main.h"
/**
 * main - Entry point
 * @env: environ variable
 * return: 0
 */

int main(int ac, char **av, char **environ)
{
	char *lineptr = NULL;
	char *lineptr_cpy = NULL;
	const char *delim = "\n ";
	size_t n = 0;
	char *token = 0;	
	ssize_t line = 0;
	int num_token = 0;
	int i = 0;
	int j = 0;
	char **argv = NULL;
	char *prompt;
	(void)ac;
	(void)av;
	

	prompt ="";

	while (1)
	{
		num_token = 0;
		argv = NULL;
		if (isatty(STDIN_FILENO))
		{
			_puts(prompt);
		}
		line = _getline(&lineptr, &n, stdin);
		
		if (line == -1)
		{
            		free(lineptr);
            		lineptr = NULL;
            		break;
		}
		if (lineptr[0] == '\t' || lineptr[0] == '\n')
        	{
            		continue;
        	}


		else if (line > 1)
		{
			lineptr_cpy = _strdup(lineptr);

			if (lineptr_cpy == NULL)
			{
				perror("tsh: memory allocation error");
				free(lineptr);
				lineptr = NULL;
				break;
			}
			_strcpy(lineptr_cpy, lineptr);
			token = _strtok(lineptr, delim);

			while (token != NULL)
			{
				num_token++;
				token = _strtok(NULL, delim);
			}
			if (num_token == 0)
        		{
            				
            			continue;
        		}

			

			argv = malloc(sizeof(char *) * (num_token + 1));

			if (argv == NULL)
			{
				perror("tsh: memory allocation error");
				free(lineptr_cpy);
				free(lineptr);
				
			}

			token = _strtok(lineptr_cpy, delim);

			for (i = 0; token != NULL; i++)
			{
				argv[i] = malloc(sizeof(char) * _strlen(token) + 1);

				if (argv[i] == NULL)
				{
					perror("tsh: memory allocation error");
					
					for (j = 0; j < i; j++)
					{
						free(argv[j]);
					}
					free(argv);
					free(lineptr_cpy);
					free(lineptr);
					exit(2);
				}

				_strcpy(argv[i], token);
				token = _strtok(NULL, delim);
			}
			argv[i] = NULL;

			if (num_token > 0 && argv != NULL && argv[0] != NULL) /* Check if the command is not NULL */
			{
				if (_strcmp(argv[0], "printenv") == 0)
				{
					_environ(environ); /* Pass env to your print_environment function */
				}

				if (_strcmp(argv[0], "clear") == 0)
				{
					system("clear");
				}

				if (_strcmp(argv[0], "exit") == 0)
				{
					for (j = 0; j < num_token; j++)
					{
						free(argv[j]);
					}
					free(argv);
					free(lineptr_cpy);
					free(lineptr);
					exit(0);
				}

				_fork(argv, environ);
			}
			else
			{
				/* Handle empty command here, if needed */
				
				for (j = 0; j < num_token; j++)
				{
					free(argv[j]);
				}
				free(argv);
			}

			free(lineptr_cpy);
		}
		for (i = 0; i < num_token; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	free(lineptr);
	return (0);
}
