/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Extension 1)
May 2023

Purpose:
This program extends the colorization task by allowing the user to specify the number of threads 
to be used for processing the image. The image is divided into segments, and each segment is 
processed by a separate thread to adjust the RGB values based on their original values. 
The program measures and prints the computation time taken to process the image and writes 
the processed image to a new file.

Usage:
To run this program, provide the image filename and the number of threads as command-line arguments:
    ./program_name <image filename> <num_threads>
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For timing
#include <pthread.h> // For pthreads
#include "ppmIO.h"

// Struct to hold thread arguments
typedef struct {
    Pixel *src;
    int rows;
    int cols;
    int thread_id;
    int num_threads;
} ThreadArgs;

// threadFunction to process a segment of the image
void *processSegment(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    Pixel *src = args->src;
    int rows = args->rows;
    int cols = args->cols;
    int thread_id = args->thread_id;
    int num_threads = args->num_threads;

    // Calculate start and end indices for this thread
    int start = (rows * cols * thread_id) / num_threads;
    int end = (rows * cols * (thread_id + 1)) / num_threads;

    // Process the image segment
    for (int i = start; i < end; i++) {
        src[i].r = src[i].r > 128 ? (220 + src[i].r) / 2 : (30 + src[i].r) / 2;
        src[i].g = src[i].g > 128 ? (220 + src[i].g) / 2 : (30 + src[i].g) / 2;
        src[i].b = src[i].b > 128 ? (220 + src[i].b) / 2 : (30 + src[i].b) / 2;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    Pixel *src;
    int rows, cols, colors;
    struct timeval start, end;
    double elapsedTime;

    // Check usage
    if (argc < 3) {
        printf("Usage: %s <image filename> <num_threads>\n", argv[0]);
        exit(-1);
    }

    // Read the number of threads from command-line argument
    int num_threads = atoi(argv[2]);

    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];

    // Read image and check for errors
    src = ppm_read(&rows, &cols, &colors, argv[1]);
    if (!src) {
        printf("Unable to read file %s\n", argv[1]);
        exit(-1);
    }

    // Start timing
    gettimeofday(&start, NULL);

    // Create threads and process image segments
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].src = src;
        thread_args[i].rows = rows;
        thread_args[i].cols = cols;
        thread_args[i].thread_id = i;
        thread_args[i].num_threads = num_threads;
        pthread_create(&threads[i], NULL, processSegment, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // End timing
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Write out the processed image
    ppm_write(src, rows, cols, colors, "bold_parallel.ppm");

    // Free memory
    free(src);

    printf("Computation time: %.6f seconds\n", elapsedTime);

    return 0;
}
