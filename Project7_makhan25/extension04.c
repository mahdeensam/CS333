/*
 * Memory haiku:
 * Allocate and free,
 * Pointer dance in memory,
 * Keep leaks far from me.
 */

#include <stdio.h>
#include <stdlib.h>

void example_usage() {
    // Allocate memory for an array of 10 integers
    int *array = (int *)malloc(10 * sizeof(int));
    
    // Check if allocation was successful
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    // Initialize and print the array
    for (int i = 0; i < 10; i++) {
        array[i] = i * 10;
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    // Free the allocated memory
    free(array);
}

int main() {
    example_usage();
    return 0;
}


