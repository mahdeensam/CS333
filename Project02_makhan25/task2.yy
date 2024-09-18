/**
 * This program counts the number of rows, characters, and occurrences of each vowel
 * in a string provided through standard input. It is case-insensitive to vowels and
 * includes a count of 'a', 'e', 'i', 'o', and 'u'.
 *
 * Compilation:
 *   flex task2.yy                 - Generates the scanner from the flex file.
 *   gcc -o task2 lex.yy.c -ll        - Compiles the C code and creates an executable named task2.
 *
 * Usage:
 *   echo "input_string" | ./task2 - Pipes a string into the program and executes it.
 *
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

// Define section for declarations and variables
%{
int rows = 0;     // Counter for the number of rows
int chars = 0;    // Counter for the number of characters
int a_count = 0;  // Counter for the vowel 'a'
int e_count = 0;  // Counter for the vowel 'e'
int i_count = 0;  // Counter for the vowel 'i'
int o_count = 0;  // Counter for the vowel 'o'
int u_count = 0;  // Counter for the vowel 'u'
%}

// Rules section
%%

// Rule for lowercase and uppercase 'a' and 'A'
[aA] {a_count++; chars++;}

// Rule for lowercase and uppercase 'e' and 'E'
[eE] {e_count++; chars++;}

// Rule for lowercase and uppercase 'i' and 'I'
[iI] {i_count++; chars++;} 

// Rule for lowercase and uppercase 'o' and 'O'
[oO] {o_count++; chars++;}

// Rule for lowercase and uppercase 'u' and 'U'
[uU] {u_count++; chars++;}

// Rule for new lines, increment row counter
\n {rows++;}

// Rule for spaces, do nothing
[[:space:]]+ {}

// Rule for any other character, increment character counter
. {chars++;}

%%

// User code section
int main(int argc, char **argv) {
  // Execute the lexer
  yylex();

  // Output the results
  printf("Rows: %d\n", rows);
  printf("Characters: %d\n", chars);
  printf("Vowels:\n");
  printf("  A: %d\n", a_count);
  printf("  E: %d\n", e_count);
  printf("  I: %d\n", i_count);
  printf("  O: %d\n", o_count);
  printf("  U: %d\n", u_count);

  // Exit the program
  return 0;
}
