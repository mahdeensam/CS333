/**
 * Lexer designed to tokenize a source file, identifying elements such as:
 * - Integers and floating-point numbers
 * - Keywords (e.g., if, else, while, for)
 * - Identifiers like variable names
 * - Assignment and comparison operators
 * - Brackets, parentheses, and various other operators
 * 
 * Unrecognized sequences will be ignored. This lexer assumes that the input source
 * file doesn't contain any complex tokens such as strings or character literals.
 * 
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

/** Compile with:
 *     flex task4.yy
 *     gcc lex.yy.c -o task4
 * Run:
 *     ./task4 file.txt
 * Replace 'task4sample.txt' with the path to the source file to be tokenized.
 */

%{
// Include standard I/O to use printf function
#include <stdio.h>
%}

// Flex option to avoid the need of the yywrap function
%option noyywrap

// Definitions of digit and letter for ease of use in rules
DIGIT [0-9]
LETTER [a-zA-Z]

%%

// Rules section begins here

// Keyword rules
"if" { printf("Keyword-if\n"); }
"else" { printf("Keyword-else\n"); }
"while" { printf("Keyword-while\n"); }
"for" { printf("Keyword-for\n"); }
"int" { printf("Keyword-int\n"); }
"float" { printf("Keyword-float\n"); }

// Identifier rule: a letter followed by any number of letters or digits
{LETTER}({LETTER}|{DIGIT})* { printf("Identifier-%s\n", yytext); }  

// Assignment operator rule
"=" { printf("Assignment\n"); }

// Comparison operator rules
"==" { printf("Comparison-==\n"); }
"<" { printf("Comparison-<\n"); }
">" { printf("Comparison->\n"); }  
"<=" { printf("Comparison-<=\n"); }
">=" { printf("Comparison->=\n"); }

// Arithmetic operator rules
"+" { printf("Operator-+\n"); }
"-" { printf("Operator-\n"); }
"*" { printf("Operator-*\n"); }
"/" { printf("Operator-/\n"); }

// Bracket and parenthesis rules
"{" { printf("Open-bracket\n"); }
"}" { printf("Close-bracket\n"); }
"(" { printf("Open-paren\n"); } 
")" { printf("Close-paren\n"); }

// Numeric rules for integer and floating-point numbers
{DIGIT}+ { printf("Integer-%s\n", yytext); } 
{DIGIT}+\.{DIGIT}+ { printf("Float-%s\n", yytext); }

// Rule to ignore single line comments
"//".* ; 

// Rule to ignore whitespace (spaces, tabs, newlines)
[ \t\n]+ 

// Rule to ignore any other single character; can be expanded for error handling
. {}

%%

// Main function: entry point of the program
int main(int argc, char** argv) {

  // Check for correct command-line usage
  if(argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  // Open the input file in read mode
  FILE* fp = fopen(argv[1], "r");
  
  // If the file can't be opened, notify the user and exit
  if(!fp) {
    printf("Could not open file %s\n", argv[1]);
    return 1;
  }

  // Assign the opened file as input to the lexer
  yyin = fp;
  
  // Begin tokenizing process
  yylex();

  // Close the input file
  fclose(fp);

  return 0;
}
