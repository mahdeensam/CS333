/**
 * Task 4: Exploring Struct Memory Layout
 *
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 *
 * This program is designed to demonstrate the memory layout of a struct in C.
 * It defines a struct with a char, a short, and an int, then assigns values to
 * each field. Using an unsigned char pointer, it inspects and prints the byte-by-byte
 * memory representation of the struct. This exploration helps in understanding how
 * different data types within a struct are aligned in memory and may reveal padding
 * added by the compiler for alignment purposes.
 */

#include <stdio.h>
#include <stdlib.h>

struct NewStruct {
  char c;  // Char occupies 1 byte
  short s; // Short typically occupies 2 bytes
  int i;   // Int typically occupies 4 bytes
};

int main() {
  struct NewStruct ns = {'A', 257, 123456789}; // Initializing struct with specific values
  unsigned char* ptr = (unsigned char*)&ns;

  // Initializing struct members to provide a more illustrative memory layout
  ns.c = 'Z';  // ASCII value for 'Z'
  ns.s = -1025; // Demonstrates two's complement in a short
  ns.i = -123456789; // Shows how a negative number is stored in an int

  // Use ptr to inspect memory layout of struct NewStruct
  printf("Memory layout of struct NewStruct:\n");
  for(int i = 0; i < sizeof(struct NewStruct); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Printing each byte of the struct in hexadecimal
  }

  return 0;
}
