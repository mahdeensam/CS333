/**
 * Extension 5: More robust Word Counter that is able to handle 
 * invalid command-line inputs and invalid files
 * 
 * This program reads a text file and counts the occurrences of each word.
 * It uses a linked list to store the words and their counts.
 * The program prints the top 20 words with the highest counts in descending order.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Usage: ./extension5 <filename>
 *
 * Mahdeen Ahmed Khan Sameer
 * 25 April 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h"

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Comparison function for word counts
int compare_word_count(void *a, void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word) == 0;
}

// Comparison function for descending order sorting of word counts
int compare_count_desc(void *a, void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc2->count - wc1->count;
}

// Process the given file and update word counts
void process_file(LinkedList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
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

        // Skip empty words
        if (len == 0) {
            continue;
        }

        // Check if the word already exists in the linked list
        WordCount *wc = (WordCount *)ll_find(list, word, compare_word_count);
        if (wc != NULL) {
            wc->count++;
        } else {
            wc = (WordCount *)malloc(sizeof(WordCount));
            if (wc == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                fclose(file);
                return;
            }
            strcpy(wc->word, word);
            wc->count = 1;
            ll_append(list, wc);
        }
    }

    fclose(file);
}

// Print the top words with highest counts
void print_top_words(LinkedList *list, int top_count) {
    // Sort the linked list based on word count in descending order
    int swapped;
    Node *current;
    Node *prev = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        current = list->head;

        while (current->next != prev) {
            WordCount *wc1 = (WordCount *)current->data;
            WordCount *wc2 = (WordCount *)current->next->data;

            if (compare_count_desc(wc1, wc2) > 0) {
                void *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        prev = current;
    } while (swapped);

    // Print the top words
    current = list->head;
    int count = 0;
    while (current != NULL && count < top_count) {
        WordCount *wc = (WordCount *)current->data;
        printf("%-15s %d\n", wc->word, wc->count);
        current = current->next;
        count++;
    }
}

int main(int argc, char *argv[]) {
    // Check for valid command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    if (strlen(filename) == 0) {
        fprintf(stderr, "Invalid filename\n");
        return 1;
    }

    // Create a linked list to store word counts
    LinkedList *list = ll_create();
    if (list == NULL) {
        fprintf(stderr, "Failed to create linked list\n");
        return 1;
    }

    // Process the file and print top words
    process_file(list, filename);
    print_top_words(list, 20);

    // Clear the linked list and free memory
    ll_clear(list, free);
    free(list);

    return 0;
}
