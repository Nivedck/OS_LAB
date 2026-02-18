#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    printf("Parent Process Started! \n");
    printf("PID : %d \n",getpid());
    
    pid=fork();

    if(pid<0){
        printf("Failed to create Child Process , Exiting...\n");
        exit(0);
    }

    if(pid==0){
        printf("Child Process Started! \n");
        printf("Child Process ID: %d \n",getpid());
        printf("Parent PID: %d \n",getppid());
        printf("Child Process Exiting...\n");
        exit(0);
    }
    else{
        wait(NULL);
        printf("Parent Process Resumed! \n");
        printf("Terminating Parent Process....\n");
        exit(0);
    }

    return 0;
}