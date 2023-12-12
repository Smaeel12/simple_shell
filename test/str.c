#include <stdio.h>
#include <string.h>
void _strcat(char *dest, char *src)
{       
        int i = 0;
        int r = strlen(dest);
        
        while (*(src + i) != '\0')
        {
                *(dest + (r + i)) = *(src + i);
                i++;
        }
} 
int main(void)
{
	char *str = "hola";
	_strcat(str, "como");
	printf("%s", str);
	return (0);
}
