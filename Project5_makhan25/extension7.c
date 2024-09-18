/**
 * This file extends the polymorphic linked list implementation in C to include the function ll_delete,
 * which allows for the removal of a node at a specific 0-indexed position within a circular linked list.
 * This functionality is critical for dynamic data management, where nodes might need to be removed based on changing conditions,
 * enhancing the flexibility and usability of the linked list.
 *
 * The ll_delete function is designed to handle edge cases such as an empty list or single-node list, 
 * and ensures that memory is properly managed to prevent leaks by freeing nodes that are removed.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: April 10, 2024
 */

#include <stdlib.h>
#include "linkedlist.h"

/**
 * Creates a new, empty linked list.
 * 
 * Returns a pointer to the newly created linked list.
 */
LinkedList *ll_create() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    if (l == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }
    l->head = NULL;
    return l;
}

/**
 * Pushes a new node with the provided data to the front of the linked list.
 * 
 * @param l Pointer to the linked list
 * @param data Pointer to the data to store in the new node
 */
void ll_push(LinkedList *l, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;  // Return if memory allocation fails
    }
    newNode->data = data;
    newNode->next = l->head ? l->head : newNode;
    if (l->head != NULL) {
        Node *current = l->head;
        while (current->next != l->head) {
            current = current->next;
        }
        current->next = newNode;
    }
    l->head = newNode;
}

/**
 * Removes and returns the data from the node at the front of the linked list.
 * 
 * @param l Pointer to the linked list
 * Returns the data from the removed node, or NULL if the list is empty.
 */
void *ll_pop(LinkedList *l) {
    if (l->head == NULL) return NULL;
    
    Node *temp = l->head;
    void *data = temp->data;
    if (temp->next == l->head) {
        l->head = NULL;
    } else {
        Node *current = l->head;
        while (current->next != l->head) {
            current = current->next;
        }
        current->next = temp->next;
        l->head = temp->next;
    }
    free(temp);
    return data;
}

/**
 * Appends a new node with the provided data to the end of the linked list.
 * 
 * @param l Pointer to the linked list
 * @param data Pointer to the data to store in the new node
 */
void ll_append(LinkedList *l, void *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;  // Return if memory allocation fails
    }
    newNode->data = data;
    newNode->next = l->head ? l->head : newNode;
    if (l->head != NULL) {
        Node *current = l->head;
        while (current->next != l->head) {
            current = current->next;
        }
        current->next = newNode;
    } else {
        l->head = newNode;
    }
}

/**
 * Removes the node with the specified data from the linked list.
 * 
 * @param l Pointer to the linked list
 * @param target Pointer to the data to compare against
 * @param compfunc Pointer to the function used to compare data
 * Returns the data from the removed node, or NULL if the node is not found.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)) {
    Node *current = l->head;
    Node *prev = NULL;
    if (current == NULL) return NULL;

    do {
        if (compfunc(current->data, target)) {
            void *data = current->data;
            if (prev == NULL) {
                Node *last = l->head;
                while (last->next != l->head) {
                    last = last->next;
                }
                last->next = l->head->next;
                l->head = l->head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return data;
        }
        prev = current;
        current = current->next;
    } while (current != l->head);
    
    return NULL;
}

/**
 * Finds the node with the specified data.
 * 
 * @param l Pointer to the linked list
 * @param target Pointer to the data to compare against
 * @param compfunc Pointer to the function used to compare data
 * Returns the data from the found node, or NULL if the node is not found.
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *)) {
    Node *current = l->head;
    if (current == NULL) return NULL;

    do {
        if (compfunc(current->data, target)) {
            return current->data;
        }
        current = current->next;
    } while (current != l->head);

    return NULL;
}

/**
 * Calculates the size of the linked list.
 * 
 * @param l Pointer to the linked list
 * Returns the number of nodes in the linked list.
 */
int ll_size(LinkedList *l) {
    int size = 0;
    Node *current = l->head;
    if (current == NULL) return 0;

    do {
        size++;
        current = current->next;
    } while (current != l->head);

    return size;
}

/**
 * Clears the linked list, freeing memory for all nodes and setting the head to NULL.
 * 
 * @param l Pointer to the linked list
 * @param freefunc Pointer to the function used to free node data
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *)) {
    Node *current = l->head;
    Node *next;
    if (current != NULL) {
        do {
            next = current->next;
            freefunc(current->data);
            free(current);
            current = next;
        } while (current != l->head);
    }
    l->head = NULL;
}

/**
 * Applies a function to the data of each node in the linked list.
 * 
 * @param l Pointer to the linked list
 * @param mapfunc Pointer to the function applied to node data
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *)) {
    Node *current = l->head;
    if (current == NULL) return;

    do {
        mapfunc(current->data);
        current = current->next;
    } while (current != l->head);
}

/**
 * Deletes a node at a specified position in the linked list.
 * 
 * @param l Pointer to the linked list
 * @param position 0-indexed position of the node to delete
 */
void ll_delete(LinkedList *l, int position) {
    if (position < 0 || position >= ll_size(l)) {
        return; // If the position is out of bounds, do nothing
    }

    Node *current = l->head;
    Node *prev = NULL;
    for (int i = 0; i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) { // Deleting the head node
        Node *last = l->head;
        while (last->next != l->head) {
            last = last->next;
        }
        l->head = l->head->next;
        last->next = l->head;
    } else {
        prev->next = current->next;
    }

    free(current);
}
