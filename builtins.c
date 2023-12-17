#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * end - function causes normal process termination and exit the program,
 * and write exit status on success
 * @cmd: normal process.
 * Return: On Success nothing returned. return 2 in failure
 * as status to error() function in case of invalid exit status
 */
void end(char **cmd)
{
	if (cmd[1] != NULL)
	{
		if (atoi(cmd[1]) < 0)
		{
			error(cmd[0], atoi(cmd[1]));
			return;
		}
		exit(atoi(cmd[1]));
	}
	else
		exit(EXIT_SUCCESS);
	free(cmd);
}
/**
 * env - function that Display environment variables.
 * @cmd: the env command.
 * Return: 0 àn success.
 */
void env(char **cmd)
{
	int i;
	char *env_var;
	char *vars[] = {"USER", "LANGUAGE", "SESSION", "COMPIZ_CONFIG_PROFILE",
		"SHLVL", "HOME", "C_IS", "DESKTOP_SESSION",
		"LOGNAME", "TERM", "PATH", "DISPLAY", NULL};

	for (i = 0; vars[i] != NULL; i++)
	{
		env_var = _getenv(vars[i]);
		if (env_var != NULL)
		{
			write(STDOUT_FILENO, vars[i], _strlen(vars[i]));
			write(STDOUT_FILENO, "=", 1);
			write(STDOUT_FILENO, env_var, _strlen(env_var));
			write(STDOUT_FILENO, "\n", 1);

		}
	}
	free(*cmd);
}
