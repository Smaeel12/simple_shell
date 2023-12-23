#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

char* find_executable(const char* command, char* path) {
    char* dir = strtok(path, ":");
    while (dir != NULL) {
        char* executable = (char*)malloc(strlen(dir) + strlen(command) + 2);
        sprintf(executable, "%s/%s", dir, command);

        if (access(executable, X_OK) == 0) {
            return executable;
        }

        free(executable);
        dir = strtok(NULL, ":");
    }

    return NULL;
}

int main() {
    char *const argv[] = { "ls", "-l", NULL };
    char *const envp[] = { NULL };

    char* path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not set.\n");
        return 1;
    }

    char* ls_executable = find_executable("ls", path);
    if (ls_executable != NULL) {
        execve(ls_executable, argv, envp);

        // The code below this line is only executed if execve fails
        perror("execve");  // Print an error message
        free(ls_executable); // Free the dynamically allocated memory
        return 1;
    } else {
        printf("ls executable not found in PATH.\n");
        return 1;
    }
}
