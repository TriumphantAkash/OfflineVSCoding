#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

int ringBuffer[5];
int rp = 0;
int wp = 0;
pthread_mutex_t bufferLock;

//need 2 semaphores

//1) producer semaphore to handle buffer empty condition (set by producer, wait by consumer)
sem_t semProd;
//2) consumer semaphore to handle buffer full condition (set by consumer, wait by producer)
sem_t semCons;

void *producer(void * arg) {
    int num = 0;
    int counter = 0;
    while (counter < 100) {
        //produce
        num = rand() % 100;

        pthread_mutex_lock(&bufferLock);
        //feed buffer
        if ((wp + 1)%5 == rp) {
            printf("buffer full!\n");
            //wait on consume semaphore
            int x = sem_wait(&semCons);
            if(x){
                printf("sem_wait error\n");
            }
        } else {
            ringBuffer[wp] = num;
            wp = (wp+1)%5;
            printf("fed %d to buffer\n", num);
            //set produce semaphore
            int y = sem_post(&semProd);
            if(y) {
                printf("sem_post error\n");
            }
        }
        pthread_mutex_unlock(&bufferLock);
        counter++;
    }
    return NULL;
}

void *consumer(void * arg) {
    int counter = 0;
    while (counter < 100) {
    pthread_mutex_lock(&bufferLock);
    //consume
    if (wp == rp) {
        printf("buffer empty!\n");
        //wait on produce semaphore
        int x = sem_wait(&semProd);
        if(x) {
        printf("sem_wait error\n");
        }
    } else {
        printf("read %d from buffer\n", ringBuffer[rp]);
        rp = (rp + 1)%5;
        //set consume semaphore
        int y = sem_post(&semCons);
        if(y) {
            printf("sem_post error\n");
        }
    }
    pthread_mutex_unlock(&bufferLock);
    counter++;
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t producerTid, consumerTid;
    
    //initialize mutex lock
    pthread_mutex_init(&bufferLock, NULL);

    //initialize semaphores
    int x = sem_init(&semProd, 0, 0);
    int y = sem_init(&semCons, 0, 0);

    if(pthread_create(&producerTid, NULL, producer, NULL)) {
        printf("error while creating producer thread\n");
    }

   // sleep(1);
    if(pthread_create(&consumerTid, NULL, consumer, NULL)) {
        printf("error while creating consumer thread\n");
    }

    pthread_join(producerTid, NULL);
    pthread_join(consumerTid, NULL);
    
    //destroy mutex and semaphores
    pthread_mutex_destroy(&bufferLock);
    sem_destroy(&semProd);
    sem_destroy(&semCons);
    return 0;
}