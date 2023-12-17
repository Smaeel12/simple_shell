#include "shell.h"
/**
 * signal_handler - function that terminal signals.
 * @signal_num: signal number.
 */
void signal_handler(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "$ ", 2);
	printf("signal handler");
	fflush(stdout);
}
/**
 * interactive_mode - the program in interactive mode.
 */
void interactive_mode(void)
{
	char *line;
	char **cmds;

	signal(SIGINT, signal_handler);
	num_line = 1;
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = read_stdin();
		if (line != NULL)
		{
			cmds = tokeniz(line);
			excutcmd(cmds);
			free(line);
			free(cmds);
		}
		num_line++;
	}
	free(line);
}
