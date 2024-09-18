/**
 * This program reads a text file and counts the occurrences of each word.
 * It utilizes a linked list to store words and their counts.
 * The program prints the top 20 words with the highest counts in descending order,
 * along with a histogram representation.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Author: Mahdeen Ahmed Khan Sameer
 * Date: 21 April 2024
 * Course: CS333 - Programming Languages
 * Instructor: Professor Max Bender
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "linkedlist.h" // Include the header file for linked list functionality

#define MAX_WORD_LENGTH 100 // Maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
int compare_word_count(void *a, void *b);
int compare_count_desc(void *a, void *b);
void process_file(LinkedList *list, const char *filename);
void print_top_words(LinkedList *list, int top_count);
void print_histogram(LinkedList *list, int top_count);
void save_results_to_file(LinkedList *list, const char *filename);
void process_multiple_files(LinkedList *list, int argc, char *argv[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    LinkedList *list = ll_create(); // Create a linked list to store WordCount objects
    process_file(list, argv[1]); // Process the input file
    print_top_words(list, 20); // Print the top 20 words with their counts
    print_histogram(list, 20); // Print a histogram representation of the top 20 words

    // Clear the linked list and free memory
    ll_clear(list, free);
    free(list);

    return 0;
}

/**
 * Compares two WordCount objects based on their word strings.
 * Used for searching the linked list for a specific word.
 */
int compare_word_count(void *a, void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word) == 0;
}

/**
 * Compares two WordCount objects based on their counts in descending order.
 * Used for sorting the linked list by count.
 */
int compare_count_desc(void *a, void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc2->count - wc1->count;
}

/**
 * Processes a text file, counts the occurrences of each word, and updates the linked list.
 */
void process_file(LinkedList *list, const char *filename) {
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

        // Check if the word already exists in the linked list
        WordCount *wc = (WordCount *)ll_find(list, word, compare_word_count);
        if (wc != NULL) {
            wc->count++;
        } else {
            wc = (WordCount *)malloc(sizeof(WordCount));
            strcpy(wc->word, word);
            wc->count = 1;
            ll_append(list, wc); // Add the new word count object to the linked list
        }
    }

    fclose(file);
}

/**
 * Prints the top 'top_count' words with their counts in descending order.
 */
void print_top_words(LinkedList *list, int top_count) {
    // Sort the linked list based on word count in descending order
    // using bubble sort algorithm
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

/**
 * Prints a histogram representation of the top 'top_count' words.
 */
void print_histogram(LinkedList *list, int top_count) {
    Node *current = list->head;
    int count = 0;

    while (current != NULL && count < top_count) {
        WordCount *wc = (WordCount *)current->data;
        printf("%-15s ", wc->word);
        for (int i = 0; i < wc->count; i++) {
            printf("*");
        }
        printf("\n");
        current = current->next;
        count++;
    }
}

/**
 * Saves the results (top words with their counts) to a file.
 */
void save_results_to_file(LinkedList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filename);
        return;
    }

    Node *current = list->head;
    while (current != NULL) {
        WordCount *wc = (WordCount *)current->data;
        fprintf(file, "%-15s %d\n", wc->word, wc->count);
        current = current->next;
    }

    fclose(file);
}

/**
 * Processes multiple files and updates the word count list.
 */
void process_multiple_files(LinkedList *list, int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        process_file(list, argv[i]);
    }
}
