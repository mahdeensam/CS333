/**
 * This file contains the improved implementation of a generic linked list in C, 
 * ensuring memory leak-free execution. The program includes comprehensive tests 
 * for both integer and string data types within linked lists. Each function is 
 * designed to handle memory correctly, thus preventing memory leaks.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// Function prototypes for utility and test functions
void printInt(void* i);
void printString(void* s);
int compInt(void* i, void* j);
int compString(void* s1, void* s2);
void testIntList(LinkedList* l);
void testStringList(LinkedList* l);

int main() {
    // Create a new linked list
    LinkedList* l = ll_create();
    if (l == NULL) {
        fprintf(stderr, "Failed to create linked list.\n");
        return 1;
    }

    // Run tests for integer data type operations
    testIntList(l);
    // Run tests for string data type operations
    testStringList(l);

    // Clear the list and free its memory
    ll_clear(l, free);
    free(l);

    return 0;
}

void testIntList(LinkedList* l) {
    printf("Testing with integers:\n");

    // Append elements to the list
    for (int i = 0; i < 5; i++) {
        int* a = malloc(sizeof(int));
        if (a == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }
        *a = i;
        ll_append(l, a);
    }
    printf("List after appending elements: ");
    ll_map(l, printInt);
    printf("\n");

    // Remove an element from the list
    int* target = malloc(sizeof(int));
    if (target == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    *target = 3;
    int* removed = ll_remove(l, target, compInt);
    free(target);
    if (removed != NULL) {
        printf("Removed element: %d\n", *removed);
        free(removed);
    } else {
        printf("Element to remove not found.\n");
    }
    printf("List after removing an element: ");
    ll_map(l, printInt);
    printf("\n");

    // Clear the list
    ll_clear(l, free);
    printf("List after clearing all elements: ");
    ll_map(l, printInt);
    printf("\n");
}

void testStringList(LinkedList* l) {
    printf("Testing with strings:\n");

    // Push strings onto the list
    char* strs[] = {"Hello", "World", "OpenAI"};
    for (int i = 0; i < 3; i++) {
        char* str = strdup(strs[i]);
        if (str == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }
        ll_push(l, str);
    }
    printf("List after pushing strings: ");
    ll_map(l, printString);
    printf("\n");

    // Remove a string from the list
    char* strTarget = strdup("World");
    if (strTarget == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    char* strRemoved = ll_remove(l, strTarget, compString);
    free(strTarget);
    if (strRemoved != NULL) {
        printf("Removed string: %s\n", strRemoved);
        free(strRemoved);
    } else {
        printf("String to remove not found.\n");
    }
    printf("List after removing a string: ");
    ll_map(l, printString);
    printf("\n");

    // Clear the list
    ll_clear(l, free);
    printf("List after clearing all strings: ");
    ll_map(l, printString);
    printf("\n");
}

// Function to print an integer
void printInt(void* i) {
    printf("%d ", *(int*)i);
}

// Function to print a string
void printString(void* s) {
    printf("%s ", (char*)s);
}

// Comparison function for integers
int compInt(void* i, void* j) {
    return *(int*)i == *(int*)j;
}

// Comparison function for strings
int compString(void* s1, void* s2) {
    return strcmp((char*)s1, (char*)s2) == 0;
}
