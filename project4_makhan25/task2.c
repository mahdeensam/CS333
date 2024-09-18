/**
 * Factorial Calculation with Function Pointers in C
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This C program demonstrates the calculation of the factorial of a number, utilizing function pointers
 * for dynamic function invocation. It includes a 'factorial' function that computes the factorial of an
 * integer using recursion. The main function demonstrates how to use command-line arguments to input
 * numbers, and how to assign the 'factorial' function to a function pointer for execution. This approach
 * exemplifies the use of function pointers in C for callback functions and passing functions as arguments
 * to other functions. The program is a practical demonstration of types and functions in C, highlighting
 * the use of command-line arguments and dynamic function calls.
 */



#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(const int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main(int argc, char **argv) {
    // Check if a command-line argument is provided
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    
    // Convert the command-line argument to an integer
    int N = atoi(argv[1]);
    
    // Pointer to a function taking an integer argument and returning an integer
    int (*calc)(const int);
    
    // Assign the factorial function to calc
    calc = factorial;
    
    // Use calc to execute the factorial function
    int result = calc(N);
    
    // Print out the return value
    printf("Factorial of %d is: %d\n", N, result);
    
    return 0;
}


// How to run/test:
// gcc -o factorial factorial.c
// ./factorial 12
// ./factorial 13
// ./factorial 14
// ./factorial 15
