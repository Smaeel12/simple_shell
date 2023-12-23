#include "../shell.h"
#include <errno.h>
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
int main(void)
{
    char procpath[100]; 
    char pid[10];
    _itoa(getpid(), pid);
    strcat(procpath, "/proc/");
    strcat(procpath, pid);
    strcat(procpath, "/cmdline");
    printf("str: %s\n", procpath);

    char procPath[100];
    snprintf(procPath, 100, "/proc/%d/cmdline", getpid());
    printf("str: %s\n", procPath);
}
