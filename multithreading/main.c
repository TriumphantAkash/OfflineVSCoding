#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int ringBuffer[5];
int rp = 0;
int wp = 0;
pthread_mutex_t bufferLock;

void *producer(void * arg) {
    int num = 0;
    int counter = 0;

    while (counter < 100) {
        pthread_mutex_lock(&bufferLock);
        //produce
        num = rand() % 100;

        //feed buffer
        if ((wp + 1)%5 == rp) {
            printf("buffer full!\n");
            //full
        } else {
            ringBuffer[wp] = num;
            wp = (wp+1)%5;
            printf("fed %d to buffer\n", num);
        }
        pthread_mutex_unlock(&bufferLock);
        counter++;
    }
    return NULL;
}

void *consumer(void * arg) {
    int counter = 0;
    while (counter<100) {
        pthread_mutex_lock(&bufferLock);
        //consume
        if (wp == rp) {
            printf("buffer empty!\n");
            //empty
        } else {
            printf("read %d from buffer\n", ringBuffer[rp]);
            rp = (rp + 1)%5;
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

    if(pthread_create(&producerTid, NULL, producer, NULL)) {
        printf("error while creating producer thread\n");
    }

   // sleep(1);
    if(pthread_create(&consumerTid, NULL, consumer, NULL)) {
        printf("error while creating consumer thread\n");
    }

    pthread_join(producerTid, NULL);
    pthread_join(consumerTid, NULL);
    
    pthread_mutex_destroy(&bufferLock);
    return 0;
}