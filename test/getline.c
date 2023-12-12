#include "../shell.h"
#define LINE_BUFFER 5 
int I1_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *line;
	size_t bytes_read;
	int fd = STDIN_FILENO;
	int buffer_alloc = 0;
	
	line = malloc(LINE_BUFFER * sizeof(char));
	if (line == NULL || lineptr == NULL || n == NULL)
		return -1;

	bytes_read = read(fd, line, LINE_BUFFER);
	if (bytes_read < 0 )
		return (-1);

	printf("%li, %i\n", bytes_read,LINE_BUFFER);
	if (bytes_read > LINE_BUFFER);
	{
		buffer_alloc = bytes_read;
		buffer_alloc += LINE_BUFFER;
		line = realloc(line, buffer_alloc);
		if (line == NULL)
		{
			perror("realloc");
			free(line);
			return (-1);
		}
		printf("%li, %i\n", bytes_read,LINE_BUFFER);
		bytes_read = read(fd, line, buffer_alloc);
		*n += LINE_BUFFER;
	}
	line[bytes_read] = '\n';
	*lineptr = realloc(*lineptr, bytes_read);
	if (lineptr == NULL)
	{
		free(line);
		return (-1);
	}
	strcpy (*lineptr, line);

	*n += LINE_BUFFER;
	
	free(line);
	return(0);
}

int main(void)
{
	char *lineptr = NULL, *line = NULL;
	size_t n= 0, num= 0;
	int len= 0,l = 0;

	len = I1_getline(&lineptr, &n, stdin);
	printf("lineptr: %s\n", lineptr);
	printf("n(out): %ld\n", n);
	printf("len:  %i\n", len);
        len = getline(&line, &num, stdin);
        printf("lineptr: %s\n", line);
        printf("n(out): %ld\n", num);
        printf("len:  %i\n", l);
	/*
	while ( len != EOF || l != EOF)
	{
		write(1, "MYSHELL$ \n", 11);

		len = I1_getline(&lineptr, &n, stdin);
		l = getline(&line, &num, stdin);

		printf("________________\n");
		printf("%s\n", lineptr);
		printf("%ld\n", n);
		printf("%i\n", len);
		printf("________________\n");
		printf("%s\n", line);
		printf("%ld\n", num);
		printf("%i\n", l);
	}
	*/
	free(line);

	return 0;
}
