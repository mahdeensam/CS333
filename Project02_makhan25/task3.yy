/**
 * This program processes an HTML file by removing comments and adding newlines after
 * certain HTML tags (<p>, <h1> to <h6>, and <li>). It is designed to process the entire
 * content in memory, hence it's recommended to use it with HTML files of manageable size.
 * 
 * Authors: Mahdeen Ahmed Khan Sameer
 * Professor: Maximillian Bender
 * Date: 02/30/2024
 */

/**Compile:
 *    flex task3.yy
 *    gcc -o task3 lex.yy.c
 * Usage:
 *    ./task3 file.html
 */


%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%x COMMENT
SPACE       [ \t]
NEWLINE     [\n]
WS          {SPACE}+
EOL         {NEWLINE}+
TAG         <[^>]*>
S_COMMENT   <!--[^-]*-[^-]*-->
M_COMMENT_START <!--
M_COMMENT_END   -->

%%

<INITIAL>{TAG}                  { if (strncmp(yytext, "<p>", 3) == 0 || strncmp(yytext, "<h", 2) == 0 || strncmp(yytext, "<li>", 4) == 0) { putchar('\n'); } }
<INITIAL>{S_COMMENT}            { /* Skip */ }
<INITIAL>{WS}+                  { putchar(' '); }
<INITIAL>{EOL}+                 { putchar('\n'); }
<INITIAL>{M_COMMENT_START}      { BEGIN(COMMENT); }

<COMMENT>{M_COMMENT_END}        { BEGIN(INITIAL); }
<COMMENT>.|\n                   { /* Skip everything in multi-line comment */ }

<INITIAL>.|\n                   { ECHO; }

%%

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(size + 1);
    if (buffer == NULL) {
        printf("Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, size, file);
    fclose(file);
    buffer[size] = '\0';

    // Assign buffer to Flex's input
    YY_BUFFER_STATE new_buffer = yy_scan_string(buffer);

    // Run the lexer
    yylex();

    // Clean up
    yy_delete_buffer(new_buffer);
    free(buffer);

    return 0;
}

int yywrap() {
    return 1;
}


