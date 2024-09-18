/**
 * Test code for Stack 
 *
 * Ying Li
 * 08/01/2016
 */

#include "cstk.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	Stack *s = stk_create(20);
	
	int i;

	printf("Address of s: %p\n", (void *)&s);
    printf("Address of s->top: %p\n", (void *)&(s->top));
    printf("Address of s->capacity: %p\n", (void *)&(s->capacity));
    printf("Address of s->data: %p\n", (void *)s->data);
	printf("Address of i: %p\n", &i);

	for(i = 0; i < 10; i++) {
		stk_push(s, i+1);
	} 
    // Mark 1 (first memory picture)
	
	printf("The original list: ");
	stk_display(s, 0);
	
	printf("The reversed list: ");
	stk_display(s, 1);
	
	stk_destroy(s);

	printf("Address of s: %p\n", (void *)&s);
    printf("Address of s->top: %p\n", (void *)&(s->top));
    printf("Address of s->capacity: %p\n", (void *)&(s->capacity));
    printf("Address of s->data: %p\n", (void *)s->data);
	printf("Address of i: %p\n", &i);
	
    // Mark 2 (first memory picture)
	
	return 0;
}
