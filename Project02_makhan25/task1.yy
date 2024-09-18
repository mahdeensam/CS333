/**
 * Program to perform a Caesar cipher rotation of 13 on alphabetic characters.
 * This implementation reads from standard input and outputs to standard output.
 *
 * Compilation:
 *   flex task1.yy
 *   gcc -o task1 lex.yy.c
 *
 * Usage:
 *   echo "input_string" | ./task1
 *
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

%%

[a-z] {
  int c = yytext[0];
  c = (c - 'a' + 13) % 26 + 'a';
  printf("%c", c);
}

[A-Z] {
  int c = yytext[0]; 
  c = (c - 'A' + 13) % 26 + 'A';
  printf("%c", c);
}

. {
  printf("%s", yytext);
}

%%

int main(int argc, char** argv) {
  yylex();
  return 0;
}
