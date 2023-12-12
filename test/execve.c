#include "../shell.h"

char* find_executable(const char* command) {
    char* path = getenv("PATH");
    if (path == NULL) {
        return NULL;
    }

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

int _excutcmd(char **cmd) {
    char* ls_executable = find_executable(cmd[0]);
    pid_t pid;
    int status;

    pid = fork();

    /* child process */
    if (pid == 0) {
        if (ls_executable != NULL) {
            execve(ls_executable, cmd, environ);
            perror("execve");
        } else {
            printf("Command not found.\n");
        }
        exit(1);
    }
    /* error forking */
    else if (pid < 0) {
        perror("fork: ");
        return -1;
    }
    /* parent process */
    else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    free(excutable);
    return 0;
}

int main(void) {
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t len;
    char *token;
    char *tokens[2];

    while (1) {
        printf("#cisfun$ ");
        len = getline(&lineptr, &n, stdin);
        token = strtok(lineptr, " \n");
        tokens[0] = token;
        tokens[1] = NULL;
        int result = _excutcmd(tokens);
        if (result == -1) {
            break;
        }
    }

    free(lineptr);
    return 0;
}

