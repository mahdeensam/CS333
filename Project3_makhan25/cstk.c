/**
 * cstk.c file that contains the implementation of the basic functions declared 
 * in the cstk.h file.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/09/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "cstk.h"

Stack *stk_create(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(capacity * sizeof(int));
    stack->top = stack->data;
    stack->capacity = capacity;
    return stack;
}

int stk_empty(Stack *stack) {
    return stack->top == stack->data;
}

int stk_full(Stack *stack) {
    return stack->top - stack->data == stack->capacity;
}

void stk_push(Stack *stack, int value) {
    if (stk_full(stack)) {
        printf("Warning: Stack is full. Cannot push element.\n");
    } else {
        *(stack->top) = value;
        stack->top++;
    }
}

int stk_peek(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Warning: Stack is empty. Returning 0.\n");
        return 0;
    }
    return *(stack->top - 1);
}

int stk_pop(Stack *stack) {
    if (stk_empty(stack)) {
        printf("Warning: Stack is empty. Returning 0.\n");
        return 0;
    }
    stack->top--;
    return *(stack->top);
}

void stk_display(Stack *stack, int reverse) {
    if (reverse) {
        for (int *i = stack->top - 1; i >= stack->data; i--) {
            printf("%d ", *i);
        }
    } else {
        for (int *i = stack->data; i < stack->top; i++) {
            printf("%d ", *i);
        }
    }
    printf("\n");
}

void stk_destroy(Stack *stack) {
    free(stack->data);
    free(stack);
}

Stack *stk_copy(Stack *stack) {
    Stack *new_stack = stk_create(stack->capacity);
    for (int *i = stack->data; i < stack->top; i++) {
        stk_push(new_stack, *i);
    }
    return new_stack;
}