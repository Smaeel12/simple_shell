#include "shell.h"
/**
 * line_check - function that check for spaces.
 * @line: read line.
 * Return: 0 foound a character, 1 Null line.
 */
int line_check(char *line)
{
	int i;

	for (i = 0; line[i] != '\n'; i++)
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			return (0);
		}
	}
	return (1);
}
