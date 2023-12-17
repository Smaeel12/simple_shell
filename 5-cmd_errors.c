#include "shell.h"
#include <stdarg.h>
/**
 * print - func
 * @param_num: number
 * Return: 0
 */
int print(int param_num, ...)
{
	char *arg;
	int i;
	va_list params;

	va_start(params, param_num);
	for (i = 0; i < param_num; i++)
	{
		arg = va_arg(params, char *);
		write(STDERR_FILENO, arg, _strlen(arg));
		if (i < param_num - 1)
			write(STDERR_FILENO, ": ", 2);
	}
	va_end(params);
	write(STDERR_FILENO, "\n", 1);
	return (0);
}
/**
 * error - error func
 * @cmd: command
 * @value: exit value
 */
void error(char *cmd, int value)
{
	char *num_line_c = "1";
	char *value_c = "-98";

	if (value == 0)
		print(4, progname, num_line_c, cmd, "not found");
	else
		print(5, progname, num_line_c, cmd, "Illegal number", value_c);
}
