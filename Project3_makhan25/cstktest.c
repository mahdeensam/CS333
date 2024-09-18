/**
 * @file cstktest.c
 * @author mbender & srtaylor
 * @date 2024-02-05
 *
 * Exercises the functionality of cstk
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "cstk.h"

int main(int argc, char **argv) {
    /**
     * Test stack initialization
     */
    {
        Stack *stack1 = stk_create(10);
        Stack *stack2 = stk_create(10);

        if (stack1 == NULL || stack2 == NULL) {
            printf("Error in stk_create: unable to initialize stack");
            return 0;
        }

        if (stack1 == stack2) {
            printf(
                "Error in stk_create: two stacks created but are pointing to "
                "the same memory.");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
    }

    /**
     * Test stk_empty
     */
    {
        Stack *stack1 = stk_create(10);
        Stack *stack2 = stk_create(5);
        stk_push(stack2, 0);

        if (!stk_empty(stack1)) {
            printf("Error in stk_empty: not recognizing empty stack");
            return 0;
        }

        if (stk_empty(stack2)) {
            printf("Error in stk_empty: not recognizing a non-empty stack");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
    }

    /**
     * Test stk_full
     */
    {
        Stack *stack1 = stk_create(1);
        Stack *stack2 = stk_create(1);
        stk_push(stack2, 0);

        if (stk_full(stack1)) {
            printf("Error in stk_full: not recognizing a non-full stack");
            return 0;
        }

        if (!stk_full(stack2)) {
            printf("Error in stk_full: not recognizing a full stack");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
    }

    /**
     * Test stk_push
     */
    {
        Stack *stack1 = stk_create(1);
        Stack *stack2 = stk_create(1);
        stk_push(stack1, 0);
        stk_push(stack2, 1);

        if (*(stack1->top - 1) != 0 || *(stack2->top - 1) != 1) {
            printf(
                "Error in stk_push: value not inserted correctly or top not "
                "updated correctly");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
    }

    /**
     * Test stk_peek
     */
    {
        Stack *stack1 = stk_create(1);
        Stack *stack2 = stk_create(1);
        Stack *stack3 = stk_create(10);
        stk_push(stack1, 0);
        stk_push(stack2, 1);
        for (int i = 0; i < 6; i++) {
            stk_push(stack3, i);
        }

        if (stk_peek(stack1) != 0 || stk_peek(stack2) != 1 ||
            stk_peek(stack3) != 5) {
            printf("Error in stk_peek: incorrect value returned");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
        stk_destroy(stack3);
    }

    /**
     * Test stk_pop
     */
    {
        Stack *stack1 = stk_create(1);
        stk_push(stack1, 0);
        int val1 = stk_pop(stack1);

        Stack *stack2 = stk_create(3);
        stk_push(stack2, 1);
        stk_push(stack2, 2);
        int val2 = stk_pop(stack2);

        Stack *stack3 = stk_create(10);
        for (int i = 0; i < 6; i++) {
            stk_push(stack3, i);
        }
        int val3 = stk_pop(stack3);

        if (val1 != 0 || val2 != 2 || val3 != 5) {
            printf("Error in stk_peek: incorrect value returned");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
        stk_destroy(stack3);
    }

    /**
     * Test stk_copy
     */
    {
        Stack *stack1 = stk_create(10);
        for (int i = 0; i < 10; i++) {
            stk_push(stack1, i);
        }

        Stack *stack2 = stk_copy(stack1);

        while (!stk_empty(stack1)) {
            int val1 = stk_pop(stack1);
            int val2 = stk_pop(stack2);

            if (val1 != val2) {
                printf("Error in stk_copy: different order of contents");
                return 0;
            }
        }
        if (!stk_empty(stack2)) {
            printf("Error in stk_copy: extra content in duplicate stack");
            return 0;
        }

        stk_destroy(stack1);
        stk_destroy(stack2);
    }

    printf("All non-display tests passed!\n");
    Stack *stack = stk_create(10);
    for (int i = 0; i < 10; i++) stk_push(stack, i);
    printf("You should now see the numbers from 0 to 9: \n");
    stk_display(stack, 0);
    printf("Now you should see the numbers from 9 to 0: \n");
    stk_display(stack, 1);

    /**
     * What follows is a test to visually confirm whether stk_destroy
     * is correctly implemented. After uncommenting the lines below,
     * open your task manager (Windows) or Activity Monitor (Mac) and observe
     * that your memory usage doesn't increase while the program runs.
     */
    while(1)
    {
    	Stack* stack = stk_create(10);
    	for(int i = 0; i < 10; i++) stk_push(stack, i);
    	// Please comment out the line below and watch  memory usage explode!
    	stk_destroy(stack);
    }
}