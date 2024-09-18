/**
 * @file linkedlist.h
 * @brief Header file containing definitions and prototypes for a generic linked list in C.
 * @details This file provides the structure definitions for the Node and LinkedList structures.
 *          It also includes prototypes for various linked list operations such as creation,
 *          push, pop, append, remove, size, clear, and map.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @brief Node structure representing a node in the linked list.
 */
typedef struct Node {
    void *data;         /**< Pointer to the data stored in the node. */
    struct Node *next;  /**< Pointer to the next node in the list. */
} Node;

/**
 * @brief LinkedList structure representing the linked list.
 */
typedef struct {
    Node *head;  /**< Pointer to the head (first node) of the list. */
} LinkedList;

/**
 * @brief Creates a new linked list.
 * @return Pointer to the newly created linked list.
 */
LinkedList *ll_create();

/**
 * @brief Adds a new node with provided data to the front of the list.
 * @param l Pointer to the linked list.
 * @param data Pointer to the data to be added.
 */
void ll_push(LinkedList *l, void *data);

/**
 * @brief Removes and returns the data from the node at the front of the list.
 * @param l Pointer to the linked list.
 * @return Pointer to the data removed from the front of the list.
 */
void *ll_pop(LinkedList *l);

/**
 * @brief Adds a new node with provided data to the end of the list.
 * @param l Pointer to the linked list.
 * @param data Pointer to the data to be added.
 */
void ll_append(LinkedList *l, void *data);

/**
 * @brief Removes the node with matching data based on a provided comparison function.
 * @param l Pointer to the linked list.
 * @param target Pointer to the data to be removed.
 * @param compfunc Pointer to the comparison function.
 * @return Pointer to the data removed from the list.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * @brief Finds the node with matching data based on a provided comparison function.
 * @param l Pointer to the linked list.
 * @param target Pointer to the data to be found.
 * @param compfunc Pointer to the comparison function.
 * @return Pointer to the data found in the list.
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * @brief Returns the number of nodes in the list.
 * @param l Pointer to the linked list.
 * @return Number of nodes in the list.
 */
int ll_size(LinkedList *l);

/**
 * @brief Removes all nodes from the list and releases the allocated memory using the provided free function.
 * @param l Pointer to the linked list.
 * @param freefunc Pointer to the function used to free the memory of node data.
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *));

/**
 * @brief Applies a function to the data in each node of the list.
 * @param l Pointer to the linked list.
 * @param mapfunc Pointer to the function to be applied to each node's data.
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *));

#endif /* LINKEDLIST_H */
