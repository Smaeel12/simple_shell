#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

void printProgramName() {
    char procPath[MAX_PATH_LENGTH];
    snprintf(procPath, MAX_PATH_LENGTH, "/proc/%d/cmdline", getpid());

    int fd = open(procPath, O_RDONLY);
    if (fd != -1) {
        char programName[MAX_PATH_LENGTH];
        ssize_t bytesRead = read(fd, programName, sizeof(programName) - 1);
        close(fd);

        if (bytesRead != -1) {
            programName[bytesRead] = '\0';

            // Extract program name from the path
            char *programNamePtr = programName;
            while (*programNamePtr) {
                if (*programNamePtr == '/') {
                    // Move programNamePtr to the next character after '/'
                    programNamePtr++;
                    break;
                }
                programNamePtr++;
            }

            // Copy the program name to a separate buffer
            char extractedName[MAX_PATH_LENGTH];
            strcpy(extractedName, programNamePtr);

            printf("Program Name: %s\n", extractedName);
        }
    }
}

int main() {
    printProgramName();
    return 0;
}

