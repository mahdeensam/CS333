/**
 * Task 3: Memory Leak Exploration and Prevention
 *
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 *
 * This program serves as an educational tool to demonstrate the effects of memory allocation
 * and deallocation in a continuous loop. Initially, it will allocate a small amount of memory
 * repeatedly without freeing it, causing a memory leak that can be observed using system tools
 * like 'top' on Linux or 'Activity Monitor' on macOS. Following this, the program is modified
 * to include a free statement within the loop to correctly deallocate the memory, preventing
 * the memory leak and stabilizing the program's memory usage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Include for sleep function

int main() {
    while (1) {
        // Allocate memory of size 1000 bytes
        int *ptr = (int*)malloc(1000);

        if (ptr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
        }

        // Simulate doing some work with the allocated memory
        // This sleep call is to slow down the loop, making the memory allocation process observable
        //sleep(1);

        // Correctly free the allocated memory to prevent a memory leak
        //free(ptr);
    }

    // This return statement is unreachable but included for completeness
    return 0;
}
