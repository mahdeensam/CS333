/*
        Bruce Maxwell
        Fall 2012
        CS 333

        Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// function that prints an integer
void printInt(void* i) {
    int* a = (int*)i;
    printf("value: %d\n", *a);
}

// function that squares an integer
void squareInt(void* i) {
    int* a = (int*)i;
    *a = (*a) * (*a);
}

// function that compares two integers and returns 1 if they are equal
int compInt(void* i, void* j) {
    int* a = (int*)i;
    int* b = (int*)j;
    return (*a == *b);
}

// function that prints a string
void printString(void* s) {
    char* str = (char*)s;
    printf("value: %s\n", str);
}

// function that compares two strings and returns 1 if they are equal
int compString(void* s1, void* s2) {
    char* str1 = (char*)s1;
    char* str2 = (char*)s2;
    return (strcmp(str1, str2) == 0);
}

// test function for the various linked list functions
int main(int argc, char* argv[]) {
    LinkedList* l;
    int* a;
    int* target;
    int i;

    // create a list
    l = ll_create();

    // push data on the list
    for (i = 0; i < 20; i += 2) {
        a = malloc(sizeof(int));
        *a = i;
        ll_push(l, a);
    }

    // printing the list and testing map
    printf("After initialization\n");
    ll_map(l, printInt);
    ll_map(l, squareInt);
    printf("\nAfter squaring\n");
    ll_map(l, printInt);

    // testing removing data
    target = malloc(sizeof(int));
    *target = 16;
    a = ll_remove(l, target, compInt);
    if (a != NULL)
        printf("\nremoved: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target);

    *target = 11;
    a = ll_find(l, target, compInt);
    if (a != NULL)
        printf("\nFound: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target);

    a = ll_remove(l, target, compInt);
    if (a != NULL)
        printf("\nremoved: %d\n", *a);
    else
        printf("\nNo instance of %d\n", *target);

    printf("\nAfter removals\n");
    ll_map(l, printInt);

    // testing appending data
    ll_append(l, target);
    printf("\nAfter append\n");
    ll_map(l, printInt);

    // test clearing
    ll_clear(l, free);
    printf("\nAfter clear\n");
    ll_map(l, printInt);

    // rebuild and test append and pop
    for (i = 0; i < 5; i++) {
        a = malloc(sizeof(int));
        *a = i;
        ll_append(l, a);
    }
    printf("\nAfter appending\n");
    ll_map(l, printInt);

    a = ll_pop(l);
    printf("\npopped: %d\n", *a);
    free(a);

    a = ll_pop(l);
    printf("popped: %d\n", *a);
    free(a);

    printf("\nAfter popping\n");
    ll_map(l, printInt);
    printf("\nList size: %d\n", ll_size(l));

    // clear the integer list
    ll_clear(l, free);

    // test with strings
    char* str1 = strdup("Hello");
    char* str2 = strdup("World");
    char* str3 = strdup("CS333 Project 5");
    char* strTarget = strdup("World");

    ll_push(l, str1);
    ll_push(l, str2);
    ll_push(l, str3);

    printf("\nString list after initialization\n");
    ll_map(l, printString);

    char* foundStr = ll_find(l, strTarget, compString);
    if (foundStr != NULL)
        printf("\nFound: %s\n", foundStr);
    else
        printf("\nNo instance of %s\n", strTarget);

    char* removedStr = ll_remove(l, strTarget, compString);
    if (removedStr != NULL)
        printf("\nRemoved: %s\n", removedStr);
    else
        printf("\nNo instance of %s\n", strTarget);

    printf("\nString list after removal\n");
    ll_map(l, printString);

    // clear the string list
    ll_clear(l, free);

    return (0);
}

// Output:
// After initialization
// value: 18
// value: 16
// value: 14
// value: 12
// value: 10
// value: 8
// value: 6
// value: 4
// value: 2
// value: 0

// After squaring
// value: 324
// value: 256
// value: 196
// value: 144
// value: 100
// value: 64
// value: 36
// value: 16
// value: 4
// value: 0

// removed: 16

// No instance of 11

// No instance of 11

// After removals
// value: 324
// value: 256
// value: 196
// value: 144
// value: 100
// value: 64
// value: 36
// value: 4
// value: 0

// After append
// value: 324
// value: 256
// value: 196
// value: 144
// value: 100
// value: 64
// value: 36
// value: 4
// value: 0
// value: 11

// After clear

// After appending
// value: 0
// value: 1
// value: 2
// value: 3
// value: 4

// popped: 0
// popped: 1

// After popping
// value: 2
// value: 3
// value: 4

// List size: 3

// String list after initialization
// value: CS333 Project 5
// value: World
// value: Hello

// Found: World

// Removed: World

// String list after removal
// value: CS333 Project 5
// value: Hello