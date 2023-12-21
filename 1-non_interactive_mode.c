#include "shell.h"
/**
 * non_interactive_mode - the program in the non interactive mode.
 */
void non_interactive_mode(void)
{
	char *line;
	char **cmds;

	num_line = 1;
	while (1)
	{
		line = read_stdin();
		if (line != NULL)
		{
			cmds = tokeniz(line);
			excutcmd(cmds);
			free(line);
			free(cmds);
		}
	}
}
