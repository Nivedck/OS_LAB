#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  pid_t pid;

  printf("Parent Process Started \n");
  printf("Parent PID: %d\n",getpid());

  pid=fork();

  if(pid<0){
    printf("Process creation failed!\n");
    exit(1);
  }

  if(pid==0){
    printf("Child process is running..\n");
    printf("Child PID: %d\n",getpid());
    printf("Parent PID: %d\n",getppid());
    printf("Child Process terminating..\n");
    exit(0);
  }
  else{
    wait(NULL);
    printf("Parent process resumed \n");
    printf("Exiting..");
    exit(0);

}
