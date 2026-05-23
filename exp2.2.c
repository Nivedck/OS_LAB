#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* args){
    printf("Hello From New Thread!\n");
    printf("TID: %lu \n",pthread_self());
    sleep(10);
    printf("Exiting From New Thread!....\n");
    pthread_exit(NULL);
}

void main(){

    pthread_t tid;

    printf("Main Thread Started!\n");

    pthread_create(&tid,NULL,thread_function,NULL);

    pthread_join(tid,NULL);

    printf("Main Thread Exiting!!....\n");

    exit(0);

}