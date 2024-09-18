/*
 * File: extension06.c
 * Author: Mahdeen Ahmed Khan Sameer
 * Course: CS333
 * Task: Project 7
 * Purpose: This program demonstrates the use of Valgrind to test C data structures for memory leaks.
 *          It includes a simple example function that allocates and frees memory to ensure no memory leaks.
 */

#include <stdio.h>
#include <stdlib.h>

// Example function that allocates and frees memory
void example_function() {
    int *array = (int *)malloc(10 * sizeof(int));  // Allocate memory for an array of 10 integers
    
    // Check if allocation was successful
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    // Initialize the array with values
    for (int i = 0; i < 10; i++) {
        array[i] = i * 10;
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    // Free the allocated memory
    free(array);
}

int main() {
    example_function();
    return 0;
}
