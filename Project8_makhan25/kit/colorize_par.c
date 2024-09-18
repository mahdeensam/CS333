/*
Mahdeen Ahmed Khan Sameer
CS333
Professor Max Bender
Project 8 (Task 2: Colorize)
May 2023

Purpose:
This program processes an image using multiple threads to colorize it based on the brightness 
of the original pixels. The image is divided into segments, and each segment is processed by a 
separate thread to adjust the RGB values. The program reads a PPM image file, processes it, 
and writes the colorized image to a new file. The computation time for the processing is also 
measured and displayed.

Usage:
To run this program, provide the image filename as a command-line argument:
    ./program_name <image filename>
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For timing
#include <pthread.h> // For pthreads
#include "ppmIO.h"

#define NUM_THREADS 8 // Number of threads

// Struct to hold thread arguments
typedef struct {
    Pixel *src;
    int rows;
    int cols;
    int thread_id;
} ThreadArgs;

// Function to process a segment of the image
void *processSegment(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    Pixel *src = args->src;
    int rows = args->rows;
    int cols = args->cols;
    int thread_id = args->thread_id;

    // Calculate start and end indices for this thread
    int start = (rows * cols * thread_id) / NUM_THREADS;
    int end = (rows * cols * (thread_id + 1)) / NUM_THREADS;

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
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];

    // Check usage
    if (argc < 2) {
        printf("Usage: %s <image filename>\n", argv[0]);
        exit(-1);
    }

    // Read image and check for errors
    src = ppm_read(&rows, &cols, &colors, argv[1]);
    if (!src) {
        printf("Unable to read file %s\n", argv[1]);
        exit(-1);
    }

    // Start timing
    gettimeofday(&start, NULL);

    // Create threads and process image segments
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].src = src;
        thread_args[i].rows = rows;
        thread_args[i].cols = cols;
        thread_args[i].thread_id = i;
        pthread_create(&threads[i], NULL, processSegment, (void *)&thread_args[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
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
