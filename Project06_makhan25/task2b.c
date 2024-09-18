/**
 * This program demonstrates the handling of the SIGFPE signal (floating-point exception).
 * It sets up a signal handler for SIGFPE and intentionally performs a division by zero.
 * When the floating-point exception occurs, the program prints "Floating-point exception occurred!".
 * The program can choose to continue execution or exit after handling the exception.
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler function for SIGFPE
void sigfpe_handler(int signum) {
    printf("Floating-point exception occurred!\n");
    _exit(0); // Exit the program immediately
}

int main() {
    // Set up signal handler for SIGFPE
    signal(SIGFPE, sigfpe_handler);

    int x = 1;
    int y = 0;
    double result = x / y; // Division by zero

    printf("Result: %f\n", result); // This line will not be reached due to the signal handler

    return 0;
}
