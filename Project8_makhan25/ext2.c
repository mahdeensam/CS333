/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Extension 2)
May 2023

Purpose:
This program performs matrix multiplication using multiple threads. The matrices A and B are 
initialized with random values, and the result is stored in matrix C. The rows of matrix C are 
divided among the threads to parallelize the computation. The program measures and prints the 
computation time taken for the matrix multiplication.

Usage:
Simply run the program without any command-line arguments:
    ./program_name
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h> // For timing

#define SIZE 1000
#define NUM_THREADS 10

// Matrix dimensions
#define M SIZE
#define N SIZE
#define P SIZE

// Matrices
int A[M][N];
int B[N][P];
int C[M][P];

// Thread arguments
typedef struct {
    int start_row;
    int end_row;
} ThreadArgs;

// Function to perform matrix multiplication for a given range of rows
void *matrix_multiply(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    for (int i = args->start_row; i < args->end_row; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    int chunk_size = M / NUM_THREADS;
    struct timeval start, end;
    double elapsedTime;

    // Set seed value based on current time
    srand(time(NULL));

    // Initialize matrices A and B
    printf("Matrix A Initialized\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
        }
    }
    
    printf("\nMatrix B Initialized\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = rand() % 10;
        }
    }

    // Start timing
    gettimeofday(&start, NULL);

    // Create threads for matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].start_row = i * chunk_size;
        thread_args[i].end_row = (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, matrix_multiply, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // End timing
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Output the result matrix C
    // printf("\nResult matrix C:\n");
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < P; j++) {
    //         printf("%d ", C[i][j]);
    //     }
    //     printf("\n");
    // }

    // Output total time taken
    printf("\nDone! Total computation time: %.6f seconds\n", elapsedTime);

    return 0;
}
