/**
 * This program calculates the frequency of specified letters in a text file. 
 * It reads the file through standard input and outputs the count for each 
 * requested letter.
 * 
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

/** Compile with:
 *    flex extension3.yy
 *    gcc -o extension3 lex.yy.c
 * Usage:
 *    Pipe the content of a file into the program with specified letters: 
 *    ./extension3 <letters> < sample_text.txt
 * Example:
 *    ./extension3 aeiou < sample_text.txt
 * The above example will report the frequency of the vowels a, e, i, o, u.
 */

%{
#include <stdio.h>
int counts[128] = {0}; // array to store counts for ASCII chars
%}

%%

[a-zA-Z] { 
  counts[yytext[0]]++;
}

\n {}

. {}

%%

int main(int argc, char **argv) {

  if(argc < 2) {
    printf("Usage: %s <letters>\n", argv[0]);
    return 1;
  }

  // Set counts for command line letters to 0
  for(int i = 1; i < argc; i++) {
    counts[argv[i][0]] = 0; 
  }

  yylex();

  // Print counts
  for(int i = 1; i < argc; i++) {
    printf("%c: %d\n", argv[i][0], counts[argv[i][0]]);
  }

  return 0;
}

int yywrap() {
  return 1;
}