#include "shell.h"
/**
 * read_stdin - read a line from the stdin.
 * Return: pointer points to the line.
 */
char *read_stdin(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	int len;

	len = getline(&lineptr, &n, stdin);
	if (len == EOF)
	{
		/* in case of “end of file” condition (Ctrl+D)*/
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_SUCCESS);
	}
	if (len == -1)
	{
		perror("getline failed");
		exit(EXIT_FAILURE);
	}

	if (line_check(lineptr) == 1)
	{
		free(lineptr);
		/* in case of empty line (nothing been entred)*/
		return (NULL);
	}

	return (lineptr);
}
