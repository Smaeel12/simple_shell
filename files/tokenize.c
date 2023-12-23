#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *tokens;
  char *line = "split this into parts";
  char *delimiters = " ";
  
  tokens = strtok(line, delimiters);
  if (tokens == NULL)
	  return(1);
  printf("1: %s\n",tokens);

  for (int i = 0; line[i] != '\0'; i++)
  {
    tokens = strtok(NULL, delimiters);
    if (tokens== NULL)
	    break;
    printf("	 --> %s\n", tokens);
  }
  return 0;
}
