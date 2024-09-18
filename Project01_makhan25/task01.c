/**
 * Task 1: Memory Access
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 *
 * This program demonstrates how different basic data types are stored in memory.
 * It declares variables of each basic type, assigns them values, and uses an unsigned char pointer
 * to inspect their memory representation byte by byte.
 */

#include <stdio.h>
#include <stdlib.h>
        
/* This main function declares variables of basic data types, assigns them values,
   and then iterates through their memory representation to display it in hexadecimal format.
   It aims to illustrate the underlying memory layout of these data types.
*/ 
int main() {
  // Initializing variables of various basic types with specific values
  char c = 'Z'; // Use a different char to see how it's stored
  short s = -1025; // A negative number to see two's complement representation
  int i = -123456789; // A larger negative number for int type
  long l = 9876543210; // A positive long for contrast
  float f = -123.456; // A negative float to observe its storage
  double d = 98765.4321; // A positive double for comparison

  unsigned char *ptr; // Pointer to inspect the memory
  
  // Inspecting char memory representation
  ptr = (unsigned char*) &c;
  printf("Memory representation of char 'c':\n");
  for(int i = 0; i < sizeof(char); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Displaying each byte in hexadecimal
  }



for (int i=0; i < sizeof(char); i++) {
    printf("%d: %02X\n", i, ptr[i]);
  }
  // Inspecting short memory representation
  ptr = (unsigned char*) &s;
  printf("\nMemory representation of short 's':\n");
  for(int i = 0; i < sizeof(short); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Hexadecimal output shows endianess and two's complement for negative values
  }

  // Inspecting int memory representation
  ptr = (unsigned char*) &i;
  printf("\nMemory representation of int 'i':\n");
  for(int i = 0; i < sizeof(int); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Observing how a larger negative number is stored
  }

  // Inspecting long memory representation
  ptr = (unsigned char*) &l;
  printf("\nMemory representation of long 'l':\n");
  for(int i = 0; i < sizeof(long); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Long storage, especially interesting for larger numbers
  }

  // Inspecting float memory representation
  ptr = (unsigned char*) &f;
  printf("\nMemory representation of float 'f':\n");
  for(int i = 0; i < sizeof(float); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Floats show IEEE 754 format representation
  }

  // Inspecting double memory representation
  ptr = (unsigned char*) &d;
  printf("\nMemory representation of double 'd':\n");
  for(int i = 0; i < sizeof(double); i++) {
    printf("%d: %02X\n", i, ptr[i]); // Doubles, with their precision, offer a detailed look at IEEE 754 format
  }

  return 0;
}
