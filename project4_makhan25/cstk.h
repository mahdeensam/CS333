#ifndef CSTKHEADER
#define CSTKHEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    void **data;
    void **top;
    int capacity;
} Stack;

/**
 * @brief Returns a reference to an allocated Stack.
 *
 * @param capacity the maximal number of items in the Stack.
 * @return a reference to the newly created Stack.
 */
Stack *stk_create(int capacity);

/**
 * @brief Frees all space allocated for the Stack.
 *
 * Does not deallocate the space given to the items referenced by the Stack.
 *
 * @param stack a reference to the Stack to be freed.
 */
void stk_destroy(Stack *stack);

/**
 * @brief Returns the number of items in the given Stack.
 *
 * @param stack the Stack to be inspected.
 * @return the number of items in the given Stack.
 */
int stk_size(Stack *stack);

/**
 * @brief Adds the given item to the top of the given Stack.
 *
 * @param stack the stack to add the given item to.
 * @param item the item to add to the given stack.
 */
void stk_push(Stack *stack, void *item);

/**
 * @brief Returns a reference to the item on top of the stack.
 *
 * @param stack the Stack to peek at.
 * @return a reference to the item on top of the stack.
 */
void *stk_peek(Stack *stack);

/**
 * @brief Removes the top item of the stack and returns a reference to it.
 *
 * @param stack the Stack to pop from.
 * @return the item removed from the Stack.
 */
void *stk_pop(Stack *stack);

/**
 * @brief Returns a reference to a String representing the contents of the
 * Stack. Uses the given toString function to compute string representations of
 * individual items, putting a ", " in between each sequential item.
 *
 * @param stack the Stack to represent via a String.
 * @param toString a function that reads individual items of the stack and
 * returns string representations.
 * @return a String representing the contents of the Stack.
 */
char *stk_toString(Stack *stack, char *(*toString)(void *));

#endif