/**
 * This file implements a polymorphic linked list in C that is capable of storing any data type.
 * The list's operations are designed to be generic, allowing for various data-specific manipulations
 * via function pointers. This implementation is especially focused on ensuring proper memory management 
 * to prevent memory leaks and to provide basic list functionalities such as add, remove, and search.
 *
 * Functions Defined:
 * - ll_create: Initializes a new empty linked list.
 * - ll_push: Adds a new node with provided data to the front of the list.
 * - ll_pop: Removes and returns the data from the node at the front of the list.
 * - ll_append: Adds a new node with provided data to the end of the list.
 * - ll_remove: Removes a node with matching data based on a provided comparison function.
 * - ll_delete: Removes a node at a specified position.
 * - ll_find: Searches for a node with the given data using a comparison function.
 * - ll_size: Returns the number of nodes in the list.
 * - ll_clear: Clears the list, freeing all associated memory.
 * - ll_map: Applies a function to the data in each node.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

#include <stdlib.h>
#include "linkedlist.h"

/* Creates and initializes a new linked list */
LinkedList *ll_create() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

/* Adds a node to the front of the list with the specified data */
void ll_push(LinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Handle malloc failure
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

/* Removes and returns the element at the front of the list */
void *ll_pop(LinkedList *list) {
    if (list->head == NULL) {
        return NULL; // No element to pop
    }
    Node *node = list->head;
    void *data = node->data;
    list->head = node->next;
    free(node);
    return data;
}

/* Adds a node to the end of the list with the specified data */
void ll_append(LinkedList *list, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return; // Handle malloc failure
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

/* Removes the node with the specified data using a comparison function */
void *ll_remove(LinkedList *list, void *target, int (*compfunc)(void *, void *)) {
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (compfunc(current->data, target) == 0) {
            void *data = current->data;
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return data;
        }
        previous = current;
        current = current->next;
    }
    return NULL; // No matching node found
}

/* Searches for the node with the specified data */
void *ll_find(LinkedList *list, void *target, int (*compfunc)(void *, void *)) {
    Node *current = list->head;
    while (current != NULL) {
        if (compfunc(current->data, target) == 0) {
            return current->data;
        }
        current = current->next;
    }
    return NULL; // No matching node found
}

/* Returns the number of nodes in the list */
int ll_size(LinkedList *list) {
    int count = 0;
    Node *current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/* Clears the list and frees all associated memory */
void ll_clear(LinkedList *list, void (*freefunc)(void *)) {
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        freefunc(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
}

/* Applies the provided function to the data in each node */
void ll_map(LinkedList *list, void (*func)(void *)) {
    Node *current = list->head;
    while (current != NULL) {
        func(current->data);
        current = current->next;
    }
}

/* Deletes the node at the specified position */
void ll_delete(LinkedList *list, int position) {
    if (position < 0 || position >= ll_size(list)) {
        return; // Position out of bounds
    }

    Node *current = list->head;
    Node *previous = NULL;

    for (int i = 0; i < position; i++) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        list->head = current->next; // Head node is being removed
    } else {
        previous->next = current->next;
    }

    free(current);
}
