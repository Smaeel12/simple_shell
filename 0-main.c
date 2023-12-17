#include "shell.h"
/**
 * main - run the program.
 * @ac: count.
 * @av: vector.
 * Return: 0 always.
 */
int main(int ac, char **av)
{
	(void) ac;

	progname = av[0];
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (0);
}
