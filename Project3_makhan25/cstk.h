/**
 * cstk.h file that contains the necessary sturctures and the declarations 
 * of the basic functions of a stack.
 * 
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/09/2024
 */

typedef struct Stack {
    int *data;    // this is a pointer to the start of the data for the stack
    int *top;     // this will point to the next place to insert in the stack
    int capacity; // this is the maximal size of the stack
} Stack;

Stack *stk_create(int capacity);
int stk_empty(Stack *stack);
int stk_full(Stack *stack);
void stk_push(Stack *stack, int value);
int stk_peek(Stack *stack);
int stk_pop(Stack *stack);
void stk_display(Stack *stack, int reverse);
void stk_destroy(Stack *stack);
Stack *stk_copy(Stack *stack);
void stk_resize(Stack *stack);  // Extension 8
int stk_size(Stack *stack);     // Extension 8
int stk_capacity(Stack *stack); // Extension 8
void stk_clear(Stack *stack);   // Extension 8