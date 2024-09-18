/**
 * Extension 8: Enhancing stack functionality to handle overflow errors and dynamic resizing.
 * Additional functions are added to the stack library for better usability and robustness.
 * 
 * Author: Mahdeen Ahmed Khan Sameer
 * Professor: Max Bender
 * Date: 03/09/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "cstk.h"

// Function to create a new stack with specified capacity
Stack *stk_create(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(capacity * sizeof(int)); // Allocate memory for stack data
    stack->top = stack->data; // Initialize top pointer to the start of the data array
    stack->capacity = capacity; // Set the capacity of the stack
    return stack;
}

// Function to check if the stack is empty
int stk_empty(Stack *stack) {
    return stack->top == stack->data; // If top equals data, stack is empty
}

// Function to check if the stack is full
int stk_full(Stack *stack) {
    return stack->top - stack->data == stack->capacity; // If top - data equals capacity, stack is full
}

// Function to resize the stack dynamically when it's full
void stk_resize(Stack *stack) {
    int new_capacity = stack->capacity * 2; // Double the current capacity
    int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int)); // Reallocate memory for the stack data
    if (new_data == NULL) {
        printf("Error: Failed to resize stack.\n"); // Print error message if resizing fails
        return;
    }
    stack->top = new_data + (stack->top - stack->data); // Update top pointer after resizing
    stack->data = new_data; // Update data pointer
    stack->capacity = new_capacity; // Update capacity
}

// Function to push a value onto the stack
void stk_push(Stack *stack, int value) {
    if (stk_full(stack)) { // Check if the stack is full
        stk_resize(stack); // Resize the stack if it's full
    }
    *(stack->top) = value; // Place the value at the top of the stack
    stack->top++; // Move the top pointer to the next position
}

// Function to retrieve the top element of the stack without removing it
int stk_peek(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Warning: Stack is empty. Returning 0.\n"); // Print warning message if stack is empty
        return 0;
    }
    return *(stack->top - 1); // Return the value at the top of the stack
}

// Function to pop the top element from the stack
int stk_pop(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Warning: Stack is empty. Returning 0.\n"); // Print warning message if stack is empty
        return 0;
    }
    stack->top--; // Move the top pointer to the previous position
    return *(stack->top); // Return the value removed from the top of the stack
}

// Function to display the elements of the stack
void stk_display(Stack *stack, int reverse) {
    if (reverse) { // Display in reverse order if reverse flag is set
        for (int *i = stack->top - 1; i >= stack->data; i--) {
            printf("%d ", *i); // Print each element
        }
    } else { // Display in normal order
        for (int *i = stack->data; i < stack->top; i++) {
            printf("%d ", *i); // Print each element
        }
    }
    printf("\n"); // Move to the next line after printing
}

// Function to destroy the stack and free memory
void stk_destroy(Stack *stack) {
    free(stack->data); // Free memory allocated for stack data
    free(stack); // Free memory allocated for stack structure
}

// Function to create a copy of the stack
Stack *stk_copy(Stack *stack) {
    Stack *new_stack = stk_create(stack->capacity); // Create a new stack with the same capacity
    for (int *i = stack->data; i < stack->top; i++) {
        stk_push(new_stack, *i); // Push each element from the original stack to the new stack
    }
    return new_stack; // Return the copy of the stack
}

// Function to get the current size of the stack
int stk_size(Stack *stack) {
    return stack->top - stack->data; // Calculate the size of the stack
}

// Function to get the capacity of the stack
int stk_capacity(Stack *stack) {
    return stack->capacity; // Return the capacity of the stack
}

// Function to clear the stack
void stk_clear(Stack *stack) {
    stack->top = stack->data; // Reset the top pointer to the beginning of the stack
}
