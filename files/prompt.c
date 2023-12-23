#include "shell.h"
/** prompt - function that Display a prompt and wait for the user to type a command.
 * Return: pointer to characters read in success.
 */
char *prompt(void)
{
	char *lineptr;
	size_t n = 0;
	int len;

	write(STDIN_FILENO, "#cisfun$ ", 9);
	len = getline(&lineptr, &n, stdin);
	if (len != 0 && lineptr != NULL && len != EOF)
	{
		lineptr[len - 1] = '\0';
		excutcmd(lineptr);
	}
	return (lineptr);
}
