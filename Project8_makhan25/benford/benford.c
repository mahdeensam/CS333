/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 
Task 1: Benford
May 2023

Purpose:
This program performs a Benford's Law analysis on a dataset. The dataset is read from a binary file, 
and the program uses multiple threads to count the occurrences of each leading digit in the data. 
Different threading strategies are implemented to observe and compare their performance:

1. Using a single global mutex to protect the update of a global counter array.
2. Using an array of mutexes, one for each digit, to protect the updates.
3. Using local counters in each thread and then updating the global counter array with a single mutex.
4. Using local counters in each thread and then updating the global counter array with an array of mutexes.
5. Using local counters for each thread and copying the counts to a global array organized by thread.
6. Using local counters for each thread and copying the counts to a global array organized by digit.

The program prints the counts of each leading digit and the time taken to perform the analysis.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include "my_timing.h"

#define NUM_THREADS 8

// Global variables
int global_counts[10] = {0,0,0,0,0,0,0,0,0,0};
int N = 0;
double *data;
pthread_mutex_t mutex; // FOR PART 1 AND 3
pthread_mutex_t mutexes[10]; // Array of mutex locks, one for each digit (FOR PART 2 AND 4)
int gc_thread[NUM_THREADS][10] = {0};  // PART 5
int gc_digit[10][NUM_THREADS] = {0}; // PART 6


// Load data from a binary file
int loadData(char *filename) {
    FILE *fp;
    
    if(filename != NULL && strlen(filename))
        fp = fopen(filename, "r");
    else
        return -1;
    
    if (!fp)
        return -1;
    
    fread(&N, sizeof(int), 1, fp);
    data = (double*)malloc(sizeof(double) * N);
    fread(data, sizeof(double), N, fp);
    fclose(fp);
    
    return 1; // success
}

// Return the leading Digit of n
int leadingDigit( double n ) {
    // This is not a particularly efficient approach.
    if (fabs(n) == 1.0)
        return 1;
    else if (fabs(n) == 0.0)
        return 0;
    else if (fabs(n) < 1.0) {
        // multiply it by 10 until you get a number that is at least 1.
        // Then chop off the fractional part. All that remains is the first digit.
        double tmp = fabs(n);
        while (tmp < 1.0) {
            tmp *= 10.0;
        }
        return (int)floor( tmp );
    }
    else {
        // Divide it by 10 until you get a number smaller than 10.
        // That number will be the first digit of the original number.
        long long unsigned in = (long long unsigned) floor(fabs(n));
        while (in > 9) {
            in /= 10;
        }
        return in;
    }
} // end leadingDigit

// Thread function
void *threadFunction(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        pthread_mutex_lock(&mutex);
        global_counts[d]++;
        pthread_mutex_unlock(&mutex);
    }
    
    pthread_exit(NULL);
}

// Thread function
void *threadFunction2(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        pthread_mutex_lock(&mutexes[d]); // Lock the mutex corresponding to the digit
        global_counts[d]++;
        pthread_mutex_unlock(&mutexes[d]); // Unlock the mutex after updating the counter
    }
    
    pthread_exit(NULL);
}

// Thread function
void *threadFunction3(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    int local_counts[10] = {0}; // Local counter array for each thread

    // Loop through the assigned section of data
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        local_counts[d]++;
    }
    
    // Protect the update of the global array with a mutex
    pthread_mutex_lock(&mutex);
    // Add the local counts to the global counts
    for (int i = 0; i < 10; i++) {
        global_counts[i] += local_counts[i];
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

// Thread function
void *threadFunction4(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    int local_counts[10] = {0}; // Local counter array for each thread

    // Loop through the assigned section of data
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        local_counts[d]++;
    }

    for (int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutexes[i]); // Lock the mutex corresponding to the digit
        global_counts[i] += local_counts[i]; // Update global count for the digit
        pthread_mutex_unlock(&mutexes[i]); // Unlock the mutex after updating the counter
    }
    
    pthread_exit(NULL);
}

// Thread function
void *threadFunction5(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    
    // Local counter array for the thread
    int local_counts[10] = {0};
    
    // Loop through the assigned section of data
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        local_counts[d]++;
    }
    
    // Copy the local counts to the global counter array for the thread
    for (int i = 0; i < 10; i++) {
        gc_thread[thread_id][i] = local_counts[i];
    }
    
    pthread_exit(NULL);
}

// Thread function
void *threadFunction6(void *arg) {
    long thread_id = (long)arg;
    int start = (N * thread_id) / NUM_THREADS;
    int end = (N * (thread_id + 1)) / NUM_THREADS;
    
    // Local counter array for the thread
    int local_counts[10] = {0};
    
    // Loop through the assigned section of data
    for (int i = start; i < end; i++) {
        int d = leadingDigit(data[i]);
        local_counts[d]++;
    }
    
    // Copy the local counts to the global counter array for the thread
    for (int i = 0; i < 10; i++) {
        gc_digit[i][thread_id] = local_counts[i];
    }
    
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    double t1, t2;
    int i;
    pthread_t threads[NUM_THREADS];
    
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);
    
    // Load the data
    int succ = loadData("medium.bin");
    if (!succ) { return -1; }
    
    // Start the timer after we have loaded the data
    t1 = get_time_sec();
    
    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, threadFunction3, (void *)i);
    }
    
    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // FOR PART 5 ONLY
    // Sum the counts for each digit
    // for (int i = 0; i < NUM_THREADS; i++) {

    // // FOR PART 6 ONLY
    // // Sum the counts for each digit
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < NUM_THREADS; j++) {
    //         global_counts[i] += gc_digit[i][j];
    //     }
    // }
    
    // End the timer
    t2 = get_time_sec();
    
    // Print counts
    for (i = 1; i < 10; i++) {
        printf("There are %d %d's\n", global_counts[i], i);
    }
    
    printf("It took %f seconds for the whole thing to run\n", t2 - t1);
    
    // Destroy mutex
    pthread_mutex_destroy(&mutex);
    
    // Free allocated memory
    free(data);
    
    return 0;
}
