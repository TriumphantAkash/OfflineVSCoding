#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int ringBuffer[BUFFER_SIZE];
int rp = 0;  // read pointer
int wp = 0;  // write pointer
pthread_mutex_t bufferLock;

// Semaphores for producer and consumer synchronization
sem_t semProd;  // Semaphore for producer (buffer not full)
sem_t semCons;  // Semaphore for consumer (buffer not empty)

void *producer(void * arg) {
    int num = 0;
    int counter = 0;
    while (counter < 100) {
        // Produce a number
        num = rand() % 100;

        // Wait for space in the buffer (consumer will signal this)
        sem_wait(&semCons);

        pthread_mutex_lock(&bufferLock);
        // Add to buffer
        ringBuffer[wp] = num;
        wp = (wp + 1) % BUFFER_SIZE;
        printf("[PROD] Fed %d to buffer\n", num);
        pthread_mutex_unlock(&bufferLock);

        // Signal the consumer that there's something to consume
        sem_post(&semProd);

        counter++;
    }
    return NULL;
}

void *consumer(void * arg) {
    int counter = 0;
    while (counter < 100) {
        // Wait for something to consume (producer will signal this)
        sem_wait(&semProd);

        pthread_mutex_lock(&bufferLock);
        // Consume from buffer
        int num = ringBuffer[rp];
        rp = (rp + 1) % BUFFER_SIZE;
        printf("[CONS] Read %d from buffer\n", num);
        pthread_mutex_unlock(&bufferLock);

        // Signal the producer that there's space in the buffer
        sem_post(&semCons);

        counter++;
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t producerTid, consumerTid;

    // Initialize mutex lock
    pthread_mutex_init(&bufferLock, NULL);

    // Initialize semaphores
    sem_init(&semProd, 0, 0);  // Start with consumer semaphore empty (0)
    sem_init(&semCons, 0, BUFFER_SIZE);  // Start with producer semaphore full (BUFFER_SIZE)

    // Create producer and consumer threads
    if (pthread_create(&producerTid, NULL, producer, NULL)) {
        printf("Error creating producer thread\n");
    }

    if (pthread_create(&consumerTid, NULL, consumer, NULL)) {
        printf("Error creating consumer thread\n");
    }

    // Wait for threads to finish
    pthread_join(producerTid, NULL);
    pthread_join(consumerTid, NULL);

    // Destroy mutex and semaphores
    pthread_mutex_destroy(&bufferLock);
    sem_destroy(&semProd);
    sem_destroy(&semCons);

    return 0;
}
