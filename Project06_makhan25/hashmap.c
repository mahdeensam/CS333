/**
 * Hash Map Implementation
 *
 * This file contains the implementation of the hash map functions
 * declared in the hashmap.h header file.
 *
 * The hash map is used to store word counts for the word frequency counter program.
 * It uses separate chaining to handle collisions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

// Hash function to generate an index from the given key
unsigned int hash(const char *key) {
    unsigned int hashval = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashval = key[i] + (hashval << 5) - hashval; // Jenkins hash algorithm
    }
    return hashval % TABLE_SIZE;
}

// Function to create a new hash map
HashMap *create_hashmap() {
    HashMap *map = (HashMap *)malloc(sizeof(HashMap)); // Allocate memory for the hash map
    map->table = (WordCount **)calloc(TABLE_SIZE, sizeof(WordCount *)); // Initialize table with NULL pointers
    return map;
}

// Function to insert a word into the hash map
void insert_word(HashMap *map, const char *word) {
    unsigned int index = hash(word); // Calculate the index for the given word
    WordCount *wc = map->table[index]; // Get the head of the linked list at the calculated index

    // Traverse the linked list to find the word
    while (wc != NULL) {
        if (strcmp(wc->word, word) == 0) { // If the word already exists, increment its count
            wc->count++;
            return;
        }
        wc = (WordCount *)wc->next; // Move to the next node
    }

    // If the word does not exist, create a new node and insert it at the beginning of the linked list
    wc = (WordCount *)malloc(sizeof(WordCount));
    strcpy(wc->word, word);
    wc->count = 1;
    wc->next = map->table[index];
    map->table[index] = wc;
}

// Function to clear the hash map and free memory
void clear_hashmap(HashMap *map) {
    // Iterate through each bucket in the hash map
    for (int i = 0; i < TABLE_SIZE; i++) {
        WordCount *wc = map->table[i];
        // Iterate through each node in the linked list and free memory
        while (wc != NULL) {
            WordCount *temp = wc;
            wc = (WordCount *)wc->next;
            free(temp);
        }
    }
    free(map->table); // Free the memory allocated for the table
    free(map); // Free the memory allocated for the hash map structure
}
