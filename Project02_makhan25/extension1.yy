/**
 * This program implements the Vigenère cipher, a method of encrypting alphabetic text 
 * by using a form of polyalphabetic substitution. It reads text from a file 
 * and performs encryption or decryption based on the provided keyword and mode.
 * 
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

/** Compilation instructions:
 *    Compile with Flex to generate the C file: flex extension1.yy
 *    Compile the generated C file with GCC: gcc -o extension1 lex.yy.c
 * Usage:
 *    To encrypt a file: ./extension1 <keyword> e sample_text.txt
 *    To decrypt a file: ./extension1 <keyword> d sample_text.txt
 * Replace <keyword> with your chosen keyword for encryption or decryption.
 */


%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *subst = "abcdefghijklmnopqrstuvwxyz";
char *keyword;  
char mode;
int i = 0;
%}

%option noyywrap

%%

[a-zA-Z] {
  int idx = strchr(subst, tolower(yytext[0])) - subst;
  
  if(mode == 'e') {
  idx = (idx + keyword[i++ % strlen(keyword)] - 'a') % 26;
} else if (mode == 'd') {
  idx = (idx - (keyword[i++ % strlen(keyword)] - 'a') + 26) % 26;
}

  printf("%c", idx+'a'); 
}

. {
  printf("%s", yytext);
}

%%

int main(int argc, char** argv) {

  if(argc != 4) {
    printf("Usage: %s <keyword> <e|d> <inputfile>\n", argv[0]);
    return 1;
  }

  keyword = argv[1];
  mode = argv[2][0];

  i = 0; // initialize index

  FILE* fp = fopen(argv[3], "r");
  if(!fp) {
    printf("Could not open file %s\n", argv[3]);
    return 1; 
  }

  yyin = fp;

  yylex();

  fclose(fp);

  return 0;
}