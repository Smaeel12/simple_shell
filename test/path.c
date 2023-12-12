#include "../shell.h"
int _strlen(const char *s)
{
	int len = 0;
	while(s[len] != 0)
		len++;
	return (len);
}
int _strncmp(const char *str1, const char *str2, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
char *_getenv(const char *name)
{
	char **env;
	int len = _strlen(name);
	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0)
			return(&(*env)[len + 1]);
	}
	return (NULL);
}
int main(void)
{
	char *env;
	char *line;
	env = _getenv("PATH");
	line = strtok(env, ":");
	while (line != NULL)
	{
		printf("%s\n", line);
		line = strtok(NULL, ":");
	}
	return (0);

}
