/*
 * File: memory_allocation_experiment.c
 * Author: Mahdeen Ahmed Khan Sameer
 * Course: CS333
 * Professor: Max Bender
 * Task: Project 7 - Task 1
 * Purpose: This program measures and reports the average time taken to allocate
 *          memory for different sizes using malloc in C. The goal is to understand
 *          how memory allocation time scales with the size of the allocation.
 *          The program performs allocations for different sizes and repeats each allocation 
 *          multiple times to ensure accuracy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RUNS 100000  // Number of runs for each experiment

/*
 * Function: allocate_memory
 * Purpose: Allocates and immediately frees memory for a specified number of integers.
 * Parameters:
 *     size - the number of integers to allocate memory for
 */
void allocate_memory(int size) {
    int *ptr = (int *)malloc(size * sizeof(int));
    free(ptr);
}

/*
 * Function: calc_time
 * Purpose: Calculates the time difference in nanoseconds between two timespec structures.
 * Parameters:
 *     start - the starting time
 *     end - the ending time
 * Returns: The time difference in nanoseconds
 */
long long calc_time(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) * 1000000000LL + (end->tv_nsec - start->tv_nsec);
}

/*
 * Function: run_experiments
 * Purpose: Runs memory allocation experiments for a given number of runs and size,
 *          measuring the time taken to allocate memory in chunks and all at once.
 * Parameters:
 *     num_runs - the number of runs for each experiment
 *     size - the size of the memory allocation in terms of number of integers
 *     file - the file pointer to write the results
 */
void run_experiments(int num_runs, int size, FILE *file) {
    // Perform an initial allocation to account for any startup costs
    void* first_malloc = malloc(1);
    free(first_malloc);

    struct timespec start_time, end_time;
    long long time_chunks = 0, time_atonce = 0;
    long long time_chunks_squared = 0, time_atonce_squared = 0;

    for (int i = 0; i < RUNS; i++) {
        // Allocate memory in chunks
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        int chunk_size = size / 10;  // Allocate in chunks of 10% of total size
        for (int j = 0; j < 10; j++) {
            allocate_memory(chunk_size);
        }
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        long long chunk_duration = calc_time(&start_time, &end_time);
        time_chunks += chunk_duration;
        time_chunks_squared += chunk_duration * chunk_duration;

        // Allocate all bytes at once
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        allocate_memory(size);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        long long atonce_duration = calc_time(&start_time, &end_time);
        time_atonce += atonce_duration;
        time_atonce_squared += atonce_duration * atonce_duration;
    }

    double avg_chunks = (double)time_chunks / (RUNS - 1);
    double avg_atonce = (double)time_atonce / (RUNS - 1);
    double stddev_chunks = sqrt((time_chunks_squared - (double)(time_chunks * time_chunks) / (RUNS - 1)) / (RUNS - 2));
    double stddev_atonce = sqrt((time_atonce_squared - (double)(time_atonce * time_atonce) / (RUNS - 1)) / (RUNS - 2));

    // Output results to file
    fprintf(file, "%d %.2f %.2f %.2f %.2f\n", size, avg_chunks, stddev_chunks, avg_atonce, stddev_atonce);
    
    // Output results to terminal
    printf("Allocation size: %d integers\n", size);
    printf("Average time per call (chunks): %.2f ns, Stddev: %.2f ns\n", avg_chunks, stddev_chunks);
    printf("Average time per call (all at once): %.2f ns, Stddev: %.2f ns\n", avg_atonce, stddev_atonce);
}

int main() {
    FILE *file = fopen("results.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    // Perform an initial allocation to account for any startup costs
    void* first_malloc = malloc(1);
    free(first_malloc);

    // Run experiments for different allocation sizes
    run_experiments(RUNS, 100000, file);    // Small size
    run_experiments(RUNS, 1000000, file);   // Medium size
    run_experiments(RUNS, 10000000, file);  // Large size

    fclose(file);
    return 0;
}
