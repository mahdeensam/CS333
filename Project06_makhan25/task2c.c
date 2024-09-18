/**
 * This program demonstrates the handling of the SIGSEGV signal (segmentation fault).
 * It sets up a signal handler for SIGSEGV and intentionally dereferences a null pointer.
 * When the segmentation fault occurs, the program prints "Segmentation fault occurred!" and exits.
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function for SIGSEGV
void sigsegv_handler(int signum) {
    printf("Segmentation fault occurred!\n");
    _exit(1); // Exit the program with a non-zero status
}

int main() {
    // Set up signal handler for SIGSEGV
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 10; // Dereferencing a null pointer

    return 0;
}
