/**
 * This program demonstrates the handling of the SIGINT signal (Ctrl-C).
 * It sets up a signal handler for SIGINT and enters an infinite loop.
 * When the user presses Ctrl-C, the program prints "Interrupted!" and exits.
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function for SIGINT
void sigint_handler(int signum) {
    printf("Interrupted!\n");
    _exit(0); // Exit the program immediately
}

int main() {
    // Set up signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl-C to interrupt...\n");

    while (1) {
        // Infinite loop to keep the program running
    }

    return 0;
}
