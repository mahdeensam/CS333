/**
 * @file linkedlist.c
 * @brief Implementation of a polymorphic linked list in C.
 * @details This file contains the implementation of a linked list capable of storing any data type.
 *          Operations such as creating, pushing, popping, appending, removing, and clearing the list
 *          are provided. Additionally, the list can be mapped with a custom function.
 *          Memory management is handled to prevent memory leaks.
 */

#include <stdlib.h>
#include "linkedlist.h"

/**
 * @brief Creates a new linked list.
 * @return A pointer to the newly created linked list.
 */
LinkedList *ll_create() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

/**
 * @brief Adds a new node with provided data to the front of the list.
 * @param l Pointer to the linked list.
 * @param data Pointer to the data to be added.
 */
void ll_push(LinkedList *l, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = l->head;
    l->head = newNode;
}

/**
 * @brief Removes and returns the data from the node at the front of the list.
 * @param l Pointer to the linked list.
 * @return Pointer to the data removed from the front of the list.
 */
void *ll_pop(LinkedList *l) {
    if (l->head == NULL)
        return NULL;

    Node *temp = l->head;
    void *data = temp->data;
    l->head = l->head->next;
    free(temp);
    return data;
}

/**
 * @brief Adds a new node with provided data to the end of the list.
 * @param l Pointer to the linked list.
 * @param data Pointer to the data to be added.
 */
void ll_append(LinkedList *l, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (l->head == NULL) {
        l->head = newNode;
    } else {
        Node *current = l->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

/**
 * @brief Removes the node with matching data based on a provided comparison function.
 * @param l Pointer to the linked list.
 * @param target Pointer to the data to be removed.
 * @param compfunc Pointer to the comparison function.
 * @return Pointer to the data removed from the list.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)) {
    Node *current = l->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (compfunc(current->data, target)) {
            void *data = current->data;
            if (prev == NULL)
                l->head = current->next;
            else
                prev->next = current->next;
            free(current);
            return data;
        }
        prev = current;
        current = current->next;
    }

    return NULL;
}

/**
 * @brief Finds the node with matching data based on a provided comparison function.
 * @param l Pointer to the linked list.
 * @param target Pointer to the data to be found.
 * @param compfunc Pointer to the comparison function.
 * @return Pointer to the data found in the list.
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *)) {
    Node *current = l->head;

    while (current != NULL) {
        if (compfunc(current->data, target))
            return current->data;
        current = current->next;
    }

    return NULL;
}

/**
 * @brief Returns the number of nodes in the list.
 * @param l Pointer to the linked list.
 * @return Number of nodes in the list.
 */
int ll_size(LinkedList *l) {
    int size = 0;
    Node *current = l->head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

/**
 * @brief Removes all nodes from the list and releases the allocated memory using the provided free function.
 * @param l Pointer to the linked list.
 * @param freefunc Pointer to the function used to free the memory of node data.
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *)) {
    Node *current = l->head;
    Node *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        freefunc(temp->data);
        free(temp);
    }

    l->head = NULL;
}

/**
 * @brief Applies a function to the data in each node of the list.
 * @param l Pointer to the linked list.
 * @param mapfunc Pointer to the function to be applied to each node's data.
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *)) {
    Node *current = l->head;

    while (current != NULL) {
        mapfunc(current->data);
        current = current->next;
    }
}

/**
 * @brief Deletes the node at the specified position in the list.
 * @param l Pointer to the linked list.
 * @param position Position of the node to be deleted (0-indexed).
 */
void ll_delete(LinkedList *l, int position) {
    if (position < 0 || position >= ll_size(l)) {
        // Invalid position
        return;
    }

    if (position == 0) {
        // Removing the head node
        Node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        return;
    }

    Node *current = l->head;
    Node *prev = NULL;
    int i = 0;

    while (current != NULL && i < position) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
}
