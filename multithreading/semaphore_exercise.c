#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
enum threadNumber {
    NONE,
    T1,
    T2
};

sem_t semaphore;

void *threadFunc(void* arg) {
    sem_wait(&semaphore);
    printf("acquired semaphore in thread %d\n", *(enum threadNumber *)arg);
    //mimicing work
    sleep(2);
    printf("releasing semaphore in thread %d\n", *(enum threadNumber *)arg);
    sem_post(&semaphore);
    return NULL;
}

int main() {
    pthread_t t1;
    pthread_t t2;
    
    sem_init(&semaphore, 0, 1);
    
    enum threadNumber tNo1 = T1;
    pthread_create(&t1, NULL, threadFunc, &tNo1);
    
    enum threadNumber tNo2 = T2;
    pthread_create(&t2, NULL, threadFunc, &tNo2);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&semaphore);
    return 0;
}