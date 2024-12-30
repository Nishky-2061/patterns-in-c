#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 100

void list_files(const char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        // Skip the current (.) and parent (..) directory entries
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void count_entries(const char *dirname) {
    struct dirent *entry;
    DIR *dp = opendir(dirname);
    int count = 0;

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        count++;
    }
    closedir(dp);

    printf("Number of entries: %d\n", count);
}

void execute_command(char *command) {
    char *argv[MAX_ARGS];
    char *token = strtok(command, " \n");
    int argc = 0;

    while (token != NULL && argc < MAX_ARGS - 1) {
        argv[argc++] = token;
        token = strtok(NULL, " \n");
    }
    argv[argc] = NULL;

    if (argc > 0) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (strcmp(argv[0], "list") == 0) {
                if (argc == 1) {
                    // No directory specified, use current directory
                    list_files(".");
                } else if (argc == 3 && strcmp(argv[1], "n") == 0) {
                    count_entries(argv[2]);
                } else {
                    fprintf(stderr, "Usage: list [n dirname]\n");
                }
                exit(0);
            } else {
                fprintf(stderr, "Command not found: %s\n", argv[0]);
                exit(1);
            }
        } else if (pid > 0) {
            // Parent process
            wait(NULL); // Wait for child to finish
        } else {
            perror("Fork failed");
        }
    }
}

int main() {
    char command[MAX_CMD_LENGTH];

    while (1) {
        printf("myshell$ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // Exit on EOF
        }

        // Exit command
        if (strcmp(command, "exit\n") == 0) {
            break;
        }

        execute_command(command);
    }

    return 0;
}