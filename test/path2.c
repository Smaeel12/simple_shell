#include "../shell.h"
int main(void)
{
        char *env;
        env = getenv("PATH");
  	     printf("%s", env);
        return (0);

}
