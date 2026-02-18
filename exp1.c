#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    int fd;
    struct stat fileStat;

    printf("Parent process PID: %d\n", getpid());

    // Open a file
    fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    // Get file information using stat
    if (stat("test.txt", &fileStat) == -1) {
        perror("stat failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File size: %ld bytes\n", fileStat.st_size);

    // Create a new process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("\nChild Process\n");
        printf("Child PID: %d\n", getpid());

        close(fd); // Close file descriptor in child

        // Replace child with ls command
        execl("/bin/ls", "ls", "-l", NULL);

        // exec returns only on failure
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL); // Wait for child to finish
        printf("\nChild process completed\n");
        close(fd);
    }

    return 0;
}
