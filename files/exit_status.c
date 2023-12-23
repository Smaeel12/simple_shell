#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void)
{
	char **arg = NULL;
	int x;
	int id = fork();

	if (id == 0)
		x = execve("lmmm", arg, NULL);

	if (x==0) 
		printf("command succeeded\n");
	else if (WIFSIGNALED(x)) 
		printf("command terminated with signal %d\n", WTERMSIG(x));
	else if (WIFEXITED(x)) 
		printf("command exited %d\n", WEXITSTATUS(x));
}
