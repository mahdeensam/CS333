/**
 * Extension 4: Word Frequency Counter with Hash Map
 *
 * This program reads a text file and counts the occurrences of each word.
 * It uses a hash map to store the words and their counts.
 * The program prints the top 20 words with the highest counts in descending order.
 *
 * The word counter is case-insensitive and ignores punctuation characters.
 *
 * Usage: ./extension4 <filename>
 *
 * Mahdeen Ahmed Khan Sameer
 * 25 April 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashmap.h"

#define MAX_WORD_LENGTH 100

void process_file(HashMap *map, const char *filename) {
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

        // Insert word into the hash map
        insert_word(map, word);
    }

    fclose(file);
}

int compare_count_desc(const void *a, const void *b) {
    const WordCount *wc1 = *(const WordCount **)a;
    const WordCount *wc2 = *(const WordCount **)b;
    return wc2->count - wc1->count;
}

void print_top_words(HashMap *map, int top_count) {
    WordCount **word_counts = (WordCount **)malloc(TABLE_SIZE * sizeof(WordCount *));
    int count = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        WordCount *wc = map->table[i];
        while (wc != NULL) {
            word_counts[count++] = wc;
            wc = (WordCount *)wc->next;
        }
    }

    // Sort the word counts array based on count in descending order
    qsort(word_counts, count, sizeof(WordCount *), compare_count_desc);

    // Print the top words
    printf("Top %d words:\n", top_count);
    for (int i = 0; i < top_count && i < count; i++) {
        printf("%-15s %d\n", word_counts[i]->word, word_counts[i]->count);
    }

    free(word_counts);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    HashMap *map = create_hashmap();
    process_file(map, argv[1]);
    print_top_words(map, 20);

    // Clear the hash map and free memory
    clear_hashmap(map);

    return 0;
}
