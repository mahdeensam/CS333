/**
 * Binary Search Tree (BST) Header File
 *
 * This header file contains the structure definitions and function declarations
 * for a binary search tree implementation in C.
 *
 * The BST is implemented as a generic data structure that can store any type of data.
 * It uses a comparison function to determine the ordering of elements in the tree.
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */

#ifndef BST_H
#define BST_H

// Define the structure for a node in the binary search tree
typedef struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
} Node;

// Define the structure for the binary search tree
typedef struct {
    Node *root;
    int (*compare)(void *, void *);
} BST;

// Function prototypes for the binary search tree operations
BST *bst_create(int (*compare)(void *, void *));
void bst_insert(BST *tree, void *data);
void *bst_find(BST *tree, void *data);
void bst_clear(BST *tree, void (*free_data)(void *));
int bst_size(BST *tree);

#endif
