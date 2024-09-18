/**
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 * EX2
 */

#include <stdio.h>

int main() {
    float f = 1.0f; // Starting with 1 for float
    while(1 + f != f) { // Loop until adding one makes no difference
        f *= 2; // Double the value of f to reach the limit faster
    }
    printf("Smallest float where 1 + f == f: %f\n", f);
    
    double d = 1.0; // Starting with 1 for double
    while(1 + d != d) { // Loop until adding one makes no difference
        d *= 2; // Double the value of d to reach the limit faster
    }
    printf("Smallest double where 1 + d == d: %g\n", d);

    return 0;
}
