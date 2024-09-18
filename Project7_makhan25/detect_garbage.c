/*
 * File: detect_garbage.c
 * Author: Mahdeen Ahmed Khan Sameer
 * Course: CS333
 * Task: Project 7
 * Purpose: This program demonstrates a mark-and-sweep garbage collection algorithm
 *          in C. It identifies reachable and garbage heap chunks using depth-first search.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10
#define MAX_HEAP_SIZE 10

// A chunk on the heap could refer to other chunks on the heap
// The "marked" field is for use by the mark and sweep algorithm and
// isn't part of the data the code accesses.
typedef struct _HeapChunk {
    int num_references;
    int marked;
    struct _HeapChunk **references;
} HeapChunk;

// A variable on the stack. Can have a value that is a reference to the heap,
// or it could have a different value.
// We indicate its value is on the heap by having the reference be non-null.
typedef struct {
    char *name;
    HeapChunk *reference;
} Var;

// Program state has stack and heap separately, both stored as arrays for simplicity.
typedef struct {
    Var *stack;            // Array of all current variables
    int num_vars_on_stack; // Number of variables on the stack

    // Array of all allocated HeapChunks (array of pointers)
    HeapChunk **heap;
    int num_heap_chunks;   // Number of heap chunks
} ProgramState;

/*
 * Function: createProgramState
 * Purpose: Creates and initializes a new program state.
 * Returns: A pointer to the newly created ProgramState.
 */
ProgramState *createProgramState() {
    ProgramState *state = (ProgramState *)malloc(sizeof(ProgramState));
    state->stack = (Var *)malloc(sizeof(Var) * MAX_STACK_SIZE);
    state->heap = (HeapChunk **)malloc(sizeof(HeapChunk *) * MAX_HEAP_SIZE);
    state->num_heap_chunks = 0;
    state->num_vars_on_stack = 0;
    return state;
}

/*
 * Function: HeapMalloc
 * Purpose: Allocates a chunk on the heap and adds it to the list of allocated chunks.
 * Parameters: state - the current program state
 * Returns: A pointer to the newly allocated HeapChunk.
 */
HeapChunk *HeapMalloc(ProgramState *state) {
    HeapChunk *chunk = (HeapChunk *)malloc(sizeof(HeapChunk));
    chunk->num_references = 0;
    chunk->references = NULL;
    state->heap[state->num_heap_chunks] = chunk;
    state->num_heap_chunks++;
    return chunk;
}

/*
 * Function: setVar
 * Purpose: Updates the stack by either adding a new variable or updating the value of an existing variable.
 * Parameters:
 *     state - the current program state
 *     var_name - the name of the variable
 *     chunk - the HeapChunk reference to be assigned to the variable
 */
void setVar(ProgramState *state, char *var_name, HeapChunk *chunk) {
    int found = 0;
    for (int i = 0; i < state->num_vars_on_stack; i++) {
        if (strcmp(state->stack[i].name, var_name) == 0) {
            found = 1;
            state->stack[i].reference = chunk;
        }
    }
    if (!found) {
        state->stack[state->num_vars_on_stack].name = strdup(var_name);
        state->stack[state->num_vars_on_stack].reference = chunk;
        state->num_vars_on_stack++;
    }
}

/*
 * Function: addReference
 * Purpose: Adds a reference from one heap chunk to another.
 * Parameters:
 *     chunk_source - the source HeapChunk
 *     chunk_target - the target HeapChunk to be referenced
 */
void addReference(HeapChunk *chunk_source, HeapChunk *chunk_target) {
    if (chunk_source->num_references++ == 0) {
        chunk_source->references = malloc(sizeof(HeapChunk *));
    } else {
        chunk_source->references =
            realloc(chunk_source->references,
                       chunk_source->num_references * sizeof(HeapChunk *));
    }
    chunk_source->references[chunk_source->num_references - 1] = chunk_target;
}

/*
 * Function: markChunkDFS
 * Purpose: Helper function for depth-first search (DFS) traversal to mark reachable chunks.
 * Parameters:
 *     state - the current program state
 *     chunk - the current HeapChunk being marked
 */
void markChunkDFS(ProgramState *state, HeapChunk *chunk) {
    if (chunk == NULL || chunk->marked == 1) {
        return; // Base case: Already visited or NULL
    }

    // Mark the chunk as visited
    chunk->marked = 1;

    // Traverse through all references of the chunk recursively
    for (int i = 0; i < chunk->num_references; i++) {
        markChunkDFS(state, chunk->references[i]);
    }
}

/*
 * Function: markAndSweep
 * Purpose: Implements the mark-and-sweep algorithm to identify garbage chunks.
 * Parameters: state - the current program state
 */
void markAndSweep(ProgramState *state) {
    // Step 1: Reset marking
    for (int i = 0; i < state->num_heap_chunks; i++) {
        state->heap[i]->marked = 0;
    }

    // Step 2: Marking reachable chunks using DFS traversal
    for (int i = 0; i < state->num_vars_on_stack; i++) {
        markChunkDFS(state, state->stack[i].reference);
    }

    // Step 3: Reporting garbage chunks
    for (int i = 0; i < state->num_heap_chunks; i++) {
        HeapChunk *chunk = state->heap[i];
        if (chunk->marked == 0) {
            printf("Garbage: HeapChunk %p\n", (void *)chunk);
        } else {
            printf("Reachable: HeapChunk %p\n", (void *)chunk);
        }
    }
}

/*
 * Function: main
 * Purpose: Entry point of the program, sets up the program state and runs the mark-and-sweep algorithm.
 */
int main() {
    // Create the initial state
    ProgramState *state = createProgramState();

    // Simulate heap allocations and create reference cycles
    HeapChunk *aChunk = HeapMalloc(state);
    setVar(state, "a", aChunk);  // a = malloc()
    HeapChunk *bChunk = HeapMalloc(state);
    setVar(state, "b", bChunk);  // b = malloc()
    HeapChunk *cChunk = HeapMalloc(state);
    setVar(state, "c", cChunk);  // c = malloc()

    // Simulate more complex heap allocations
    HeapChunk *dChunk = HeapMalloc(state);
    HeapChunk *eChunk = HeapMalloc(state);
    HeapChunk *fChunk = HeapMalloc(state);
    HeapChunk *gChunk = HeapMalloc(state);

    // Create reference cycle
    addReference(dChunk, eChunk);
    addReference(eChunk, fChunk);
    addReference(fChunk, gChunk);
    addReference(gChunk, dChunk);

    // Run mark-and-sweep to identify garbage
    markAndSweep(state);

    // Free the allocated program state (not shown here for simplicity)
    // freeProgramState(state); // Implement this if needed

    return 0;
}
