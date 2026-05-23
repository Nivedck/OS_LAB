#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  pid_t pid;

  printf("Parent Process Started \n");
  printf("Parent PID: %d",getpid());
}
