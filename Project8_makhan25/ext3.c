/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Extension 3)
May 2023

Purpose:
This program demonstrates the use of semaphores to control access to a shared counter among multiple threads. 
Each thread increments the counter three times, and the semaphore ensures that only a limited number of 
threads can access the counter simultaneously. The program prints the value of the counter after each increment 
performed by the threads.

Usage:
Simply run the program without any command-line arguments:
    ./program_name
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define MAX_COUNT 20

// Shared counter
int counter = 0;

// Semaphore to control access to the shared counter
sem_t semaphore;

// Thread function
void *threadFunction(void *arg) {
    int thread_id = *(int *)arg;

    // Increment the shared counter three times
    for (int i = 0; i < 3; i++) {
        sem_wait(&semaphore); // Acquire the semaphore
        counter++;
        printf("Thread %d: Counter value after increment %d: %d\n", thread_id, i + 1, counter);
        sem_post(&semaphore); // Release the semaphore
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize semaphore with initial value 2
    sem_init(&semaphore, 0, 2);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, threadFunction, (void *)&thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}
