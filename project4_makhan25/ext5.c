/**
 * Comparison of QuickSort Comparator Functions in C
 * Mahdeen Ahmed Khan Sameer
 * Professor Max Bender
 * 03/23/2024
 * 
 * This C program demonstrates the comparison between two different comparator functions used with the qsort 
 * standard library function to sort an array of integers. The 'basicComparator' function takes a traditional 
 * approach to compare integers, while the 'efficientComparator' aims to reduce the number of operations by 
 * using conditional expressions for comparing integers. The program measures and compares the execution time 
 * of sorting one million integers using these two comparator functions, illustrating the impact of optimization 
 * in comparator functions on the sorting performance. This example emphasizes the significance of efficiency 
 * in algorithmic design and the practical benefits of optimizing code for better performance.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Optimized Comparator
int efficientComparator(const void *p, const void *q) {
    int a = *(int *)p;
    int b = *(int *)q;
    return (a % 2 == b % 2) ? (a % 2 == 0 ? b - a : a - b) : (a % 2 == 0 ? -1 : 1);
}

// Less-Optimized Comparator
int basicComparator(const void *p, const void *q) {
    int a = *(int *)p;
    int b = *(int *)q;
    if (a % 2 == 0 && b % 2 != 0) return -1;
    if (a % 2 != 0 && b % 2 == 0) return 1;
    if (a % 2 == 0) return b - a;  // both even
    return a - b;  // both odd
}

int main() {
    int size = 1000000;
    int *ary1 = malloc(size * sizeof(int));
    int *ary2 = malloc(size * sizeof(int));

    // Filling arrays with identical random numbers
    for (int i = 0; i < size; i++) {
        int val = rand() % 10000;
        ary1[i] = val;
        ary2[i] = val;
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    qsort(ary1, size, sizeof(int), basicComparator);
    end = clock();
    time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Basic qsort took %f seconds to sort %d numbers.\n", time_taken, size);

    start = clock();
    qsort(ary2, size, sizeof(int), efficientComparator);
    end = clock();
    time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Efficient qsort took %f seconds to sort %d numbers.\n", time_taken, size);

    free(ary1);
    free(ary2);
    return 0;
}

/* 
Output:

Basic qsort took 0.099652 seconds to sort 1000000 numbers.
Efficient qsort took 0.090278 seconds to sort 1000000 numbers.

As evident, the efficient quick sort is slightly faster.
*/
