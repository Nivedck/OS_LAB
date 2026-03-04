#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define EAT_COUNT 3  

sem_t chopstick[N];
pthread_t philos[N];

void *philosopher(void *num){
    
    int id = *(int *)num;
    for(int i = 0; i < EAT_COUNT; i++)
    {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);
        sem_wait(&chopstick[id]);                  // Left chopstick
        sem_wait(&chopstick[(id + 1) % N]);        // Right chopstick
        printf("Philosopher %d is Eating (%d)\n", id, i+1);
        sleep(2);
        sem_post(&chopstick[id]);                  // Release left
        sem_post(&chopstick[(id + 1) % N]);        // Release right
    }
    printf("Philosopher %d has finished eating.\n", id);
    pthread_exit(NULL);
}


int main(){
    int i;
    int phil_num[N];
    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);
    for (i = 0; i < N; i++)
    {
        phil_num[i] = i;
        pthread_create(&philos[i], NULL, philosopher, &phil_num[i]);
    }
    for (i = 0; i < N; i++)
        pthread_join(philos[i], NULL);
    printf("\nAll philosophers have finished eating.\n");
    return 0;
}
