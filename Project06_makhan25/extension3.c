/**
 * Extension 3: Word Frequency Counter with BST
 *
 * This program reads a text file and counts the occurrences of each word.
 * It uses a binary search tree (BST) to store the words and their counts.
 * The program prints the top 20 words with the highest counts in descending order.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Usage: ./extension3 <filename>
 *
 * Mahdeen Ahmed Khan Sameer
 * 22 April 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Comparison function for word count
int compare_word_count(void *a, void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

// Comparison function for sorting word counts in descending order
int compare_count_desc(const void *a, const void *b) {
    const WordCount *wc1 = *(const WordCount **)a;
    const WordCount *wc2 = *(const WordCount **)b;
    return wc2->count - wc1->count;
}

// Process the file and update word counts in the BST
void process_file(BST *tree, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Remove punctuation characters
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            word[--len] = '\0';
        }

        // Check if the word already exists in the BST
        WordCount *wc = (WordCount *)bst_find(tree, word);
        if (wc != NULL) {
            wc->count++;
        } else {
            wc = (WordCount *)malloc(sizeof(WordCount));
            strcpy(wc->word, word);
            wc->count = 1;
            bst_insert(tree, wc);
        }
    }

    fclose(file);
}

// Perform an inorder traversal of the BST to populate an array of word counts
void bst_inorder_traversal(Node *node, WordCount **word_counts, int *count) {
    if (node != NULL) {
        bst_inorder_traversal(node->left, word_counts, count);
        word_counts[*count] = (WordCount *)node->data;
        (*count)++;
        bst_inorder_traversal(node->right, word_counts, count);
    }
}

// Print the top words with the highest counts
void print_top_words(BST *tree, int top_count) {
    int num_words = bst_size(tree);
    WordCount **word_counts = (WordCount **)malloc(num_words * sizeof(WordCount *));
    int count = 0;

    bst_inorder_traversal(tree->root, word_counts, &count);

    // Sort the word counts array based on count in descending order
    qsort(word_counts, num_words, sizeof(WordCount *), compare_count_desc);

    // Print the top words
    printf("Top %d words:\n", top_count);
    for (int i = 0; i < top_count && i < num_words; i++) {
        printf("%-15s %d\n", word_counts[i]->word, word_counts[i]->count);
    }

    free(word_counts);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Create a new BST
    BST *tree = bst_create((int (*)(void *, void *))compare_word_count);
    process_file(tree, argv[1]);
    print_top_words(tree, 20);
    
    // Clear the BST and free memory
    bst_clear(tree, free);

    return 0;
}
