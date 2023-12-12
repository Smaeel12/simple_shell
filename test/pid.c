#include "../shell.h"
#define MAX_PATH_LENGTH 256

void _itoa(int num, char *str)
{
        int i, j;
        char tmp;

        for (i = 0; num != 0; i++)
        {
                str[i] = '0' + (num % 10);
                num /= 10;
        }
        for (j = 0; j < i / 2; j++)
        {
                tmp = str[j];
                str[j] = str[i - j - 1];
                str[i - j - 1] = tmp;
        }
        str[i] = '\0';
}
void printProgramName()
{
        char procpath[100];
        char pid[10];
        _itoa(getpid(), pid);

        strcat(procpath, "/proc/");
        strcat(procpath, pid);
        strcat(procpath, "/cmdline");

	int fp = open(procpath, O_RDONLY);
	if (fp != -1)
	{
		char progname[1024];
		int nb = read(fp, progname, sizeof(progname));
		if (nb != -1)
		{
			printf("%s\n", progname);
		}
	}
}
int main() {
    printProgramName();
    return 0;
}
/*
int main(void)
{
	pid_t pid;
	pid = getpid();
	printf("%i", pid);
}*/
