/**
 * This header file defines the structures and function prototypes for a generic linked list in C.
 * The list is designed to be flexible and polymorphic, capable of storing any type of data through
 * void pointers. This implementation includes various functionalities typically required by linked lists,
 * including element insertion, deletion, and application of functions over elements.
 *
 * Definitions:
 * - Node: A structure which holds the data pointer and a pointer to the next node.
 * - LinkedList: A structure which contains a head pointer to the first node of the list.
 *
 * The file provides prototypes for operations such as:
 * - Creation of a new linked list
 * - Adding an element to the front of the list (push)
 * - Removing and returning the front element of the list (pop)
 * - Adding an element to the end of the list (append)
 * - Removing a specific element based on a comparison function (remove)
 * - Counting the number of elements in the list (size)
 * - Emptying the list and freeing up memory (clear)
 * - Applying a function to each element in the list (map)
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

// Node structure
typedef struct Node {
    void *data;            // Pointer to the data stored in the node
    struct Node *next;     // Pointer to the next node
} Node;

// LinkedList structure
typedef struct {
    Node *head;            // Pointer to the first node in the list
} LinkedList;

// Function prototypes for linked list operations

/**
 * Creates and returns a new, empty linked list.
 * 
 * @return A pointer to the newly created linked list.
 */
LinkedList *ll_create();

/**
 * Adds a new node containing 'data' to the front of the linked list.
 * 
 * @param l A pointer to the linked list.
 * @param data A void pointer to the data to be stored in the new node.
 */
void ll_push(LinkedList *l, void *data);

/**
 * Removes the front node from the linked list and returns its data.
 * 
 * @param l A pointer to the linked list.
 * @return A void pointer to the data of the removed node.
 */
void *ll_pop(LinkedList *l);

/**
 * Adds a new node containing 'data' to the end of the linked list.
 * 
 * @param l A pointer to the linked list.
 * @param data A void pointer to the data to be stored in the new node.
 */
void ll_append(LinkedList *l, void *data);

/**
 * Removes a node from the linked list based on a comparison function. The first node
 * for which the comparison function returns 0 is removed.
 * 
 * @param l A pointer to the linked list.
 * @param target A void pointer to the data that will be compared against each node's data.
 * @param compfunc A pointer to the comparison function, which takes two void pointers to the data and returns an int.
 * @return A void pointer to the data of the removed node if found, otherwise NULL.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * Finds and returns the first node's data in the linked list that matches the 'target' data based on the
 * provided comparison function.
 * 
 * @param l A pointer to the linked list.
 * @param target A void pointer to the data to find.
 * @param compfunc A pointer to the comparison function, which takes two void pointers to the data and returns an int.
 * @return A void pointer to the found data, otherwise NULL.
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * Returns the number of nodes in the linked list.
 * 
 * @param l A pointer to the linked list.
 * @return An integer representing the number of nodes in the list.
 */
int ll_size(LinkedList *l);

/**
 * Clears the linked list, freeing memory for all nodes and setting the list's head to NULL.
 * 
 * @param l A pointer to the linked list.
 * @param freefunc A pointer to a function that frees the node's data.
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *));

/**
 * Applies a specified function to the data in each node of the linked list.
 * 
 * @param l A pointer to the linked list.
 * @param mapfunc A function pointer that takes a void pointer to the data and returns void.
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *));

#endif /* LINKEDLIST_H */
