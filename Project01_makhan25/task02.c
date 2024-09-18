/**
 * Task 2: Stack Representation
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 *
 * This program is designed to provide a visualization of how values are stored on the stack in memory.
 * By declaring several variables of basic data types and then an unsigned char pointer that points to its own address,
 * we can iterate over a segment of the stack memory and print out the contents byte by byte.
 * This exercise helps in understanding the contiguous memory allocation on the stack and
 * how variables are accessed in memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables of various basic types
    char c = 'Z'; // Char variable for demonstration
    short s = -1025; // Short variable, showing two's complement for negative numbers
    int i = -123456789; // Int variable with a large negative number
    // An unsigned char pointer that points to its own address
    unsigned char *ptr = (unsigned char*)&ptr;

    // Loop to print out the first 100 bytes from the pointer's address onwards
    for(int i = 0; i < 100; i++) {
        printf("Index %d: %02X\n", i, ptr[i]);
        // Adding a newline character to ensure that output is flushed to the screen after each print
    }

    return 0;
}
