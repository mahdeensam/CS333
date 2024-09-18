/**
 * Hash Map Header File
 *
 * This header file defines the structures and functions for a hash map implementation in C.
 * The hash map is utilized to store word counts for word frequency counter programs.
 * It employs separate chaining to handle collisions.
 */

#ifndef HASHMAP_H
#define HASHMAP_H

// Maximum length of a word
#define MAX_WORD_LENGTH 100

// Size of the hash map table
#define TABLE_SIZE 10000

// Structure representing a word count entry in the hash map
typedef struct WordCount {
    char word[MAX_WORD_LENGTH]; // The word
    int count; // The count of occurrences
    struct WordCount *next; // Pointer to the next entry in case of collisions
} WordCount;

// Structure representing the hash map
typedef struct {
    WordCount **table; // Array of pointers to WordCount structures
} HashMap;

// Function to create a new hash map
HashMap *create_hashmap();

// Function to insert a word into the hash map
void insert_word(HashMap *map, const char *word);

// Function to clear the hash map and free memory
void clear_hashmap(HashMap *map);

#endif
