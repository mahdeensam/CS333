/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

/* the comparator funciton used in qsort */
int comparator (const void *p, const void *q) {
	int x = *(const int *)p;
    int y = *(const int *)q;
    
    // If both numbers are even, sort them in descending order
    if (x % 2 == 0 && y % 2 == 0) {
        return (y - x); // Descending order
    }
    // If both numbers are odd, sort them in ascending order
    else if (x % 2 != 0 && y % 2 != 0) {
        return (x - y); // Ascending order
    }
    // If one number is even and the other is odd, place the even number first
    else {
        return (x % 2 == 0) ? -1 : 1;
    }
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}