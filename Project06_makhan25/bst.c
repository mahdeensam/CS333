/**
 * Binary Search Tree (BST) Implementation
 *
 * This file contains the implementation of the binary search tree functions
 * declared in the bst.h header file.
 *
 * The BST is implemented as a generic data structure that can store any type of data.
 * It uses a comparison function to determine the ordering of elements in the tree.
 *
 * Mahdeen Ahmed Khan Sameer
 * 21 April 2024
 */

#include <stdlib.h>
#include "bst.h"

// Create a new binary search tree
BST *bst_create(int (*compare)(void *, void *)) {
    BST *tree = (BST *)malloc(sizeof(BST));
    tree->root = NULL;
    tree->compare = compare;
    return tree;
}

// Insert a new node with data into the binary search tree
void bst_insert(BST *tree, void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        Node *current = tree->root;
        while (1) {
            if (tree->compare(data, current->data) < 0) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                }
                current = current->right;
            }
        }
    }
}

// Find a node with data in the binary search tree
void *bst_find(BST *tree, void *data) {
    Node *current = tree->root;
    while (current != NULL) {
        int cmp_result = tree->compare(data, current->data);
        if (cmp_result == 0) {
            return current->data;
        } else if (cmp_result < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

// Helper function to recursively clear the binary search tree
void bst_clear_helper(Node *node, void (*free_data)(void *)) {
    if (node != NULL) {
        bst_clear_helper(node->left, free_data);
        bst_clear_helper(node->right, free_data);
        free_data(node->data);
        free(node);
    }
}

// Helper function to recursively calculate the size of the binary search tree
int bst_size_helper(Node *node) {
    if (node == NULL)
        return 0;
    return 1 + bst_size_helper(node->left) + bst_size_helper(node->right);
}

// Calculate the size of the binary search tree
int bst_size(BST *tree) {
    return bst_size_helper(tree->root);
}

// Clear the binary search tree and free memory
void bst_clear(BST *tree, void (*free_data)(void *)) {
    bst_clear_helper(tree->root, free_data);
    free(tree);
}
