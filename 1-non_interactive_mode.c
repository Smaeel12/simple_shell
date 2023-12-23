#include "shell.h"
/**
 * non_interactive_mode - the program in the non interactive mode.
 */
void non_interactive_mode(void)
{
	char *line;
	char **cmds;
	int exec_status;

	num_line = 1;
	while (1)
	{
		line = read_stdin();
		if (line != NULL)
		{
			cmds = tokeniz(line);
			exec_status = excutcmd(cmds);
			if (exec_status == 1)
				error(cmds[0], 0, 127);
			free(line);
			free(cmds);
		}
	}
}
