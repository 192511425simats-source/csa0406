#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed to create a child process.\n");
        return 1;
    } 
    else if (pid == 0) {
        // This block is executed by the child process
        printf("[Child Process]\n");
        printf("Current Child PID: %d\n", getpid());
        printf("Parent PID (PPID): %d\n\n", getppid());
    } 
    else {
        // This block is executed by the parent process
        // Wait for the child process to complete before printing
        wait(NULL); 
        
        printf("[Parent Process]\n");
        printf("Current Parent PID: %d\n", getpid());
        printf("Created Child PID: %d\n", pid);
    }

    return 0;
}
