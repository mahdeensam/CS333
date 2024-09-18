/**
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 * EX4
 */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Division by Zero Error */
void division_by_zero() {
    int divisor = 0;
    int result = 10 / divisor; // Division by zero error
    printf("%d\n", result); // This line may not execute
}

/* Null Pointer Dereference */
void null_pointer_dereference() {
    int *ptr = NULL;
    int val = *ptr; // Dereferencing null pointer error
    printf("%d\n", val); // This line may not execute
}

/* Invalid Pointer Access (Dangling Pointer) */
void invalid_pointer_access() {
    int *ptr = malloc(sizeof(int));
    free(ptr); // Pointer is now dangling
    *ptr = 10; // Invalid memory access error
    // No output here, undefined behavior
}

/* Stack Overflow (Caused by infinite recursion) */
void stack_overflow() {
    stack_overflow(); // Infinite recursion causing stack overflow
    // No output here, as program will likely crash before returning
}

/* Heap Overflow (Caused by unchecked dynamic memory allocation) */
void heap_overflow() {
    while(1) {
        malloc(INT_MAX); // Continuously allocating large blocks of memory
        // No output here, as this will consume memory until allocation fails or program crashes
    }
}

/* Main function */
int main() {
    // Uncomment the function call that you want to test.
    // Be aware that running these functions will likely crash your program.
    // These examples are for educational purposes only.

    //division_by_zero();
    //null_pointer_dereference();
    //invalid_pointer_access();
    //stack_overflow();
    //heap_overflow();

    return 0;
}
