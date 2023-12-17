#ifndef SHELL_H
#define SHELL_H
/*---MODE---*/
void interactive_mode(void);
void non_interactive_mode(void);

/*---MACROS---*/
char *progname;
int num_line;
extern char **environ;
#define MAX_NUM 10
#define MAX_LENGHT 256
#define BUFFER_SIZE 1024

/*---LIBRARIES---*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*---PROTOTYPES---*/
char *read_stdin(void);
char *read_stream(void);
char **tokeniz(char *line);
int excutcmd(char **cmd);
char *_strdup(char *s);
int _strlen(const char *s);
int _strncmp(const char *str1, const char *str2, int n);
char *_getenv(const char *name);
void _itoa(int num, char *str);
char *_strcat(char *dest, char *src);
void end(char **cmd);
char *_strcpy(char *dest, char *src);
void env(char **cmd);
char *_strtok(char *str, char *delim);
void error(char *cmd, int value);

/*---STRUCTRES---*/
/**
 * struct built - structure for builtins.
 * @name: name of the builtin.
 * @f: function prototype.
 */
typedef struct built
{
	char *name;
	void (*f)(char **);
} built_in;

#endif
