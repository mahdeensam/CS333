/**
 * @file BankExample.c
 * @author Max Bender
 * @date 2024-01-22
 *
 * A goofy example to demonstrate need for care when managing strings in C.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arg, char *argv[])
{
    /**
     * This creates a definition for the struct Account.
     *
     * Note that balance (an int) is saved after name in memory.
     */
    typedef struct Account
    {
        char name[10];
        int balance;
    } Account;

    printf("Please input your name for a new bank account: ");
    Account newAccount = {"", 0};

    /**
     * The following line reads input from the terminal.
     *
     * One could have simply done: scanf("%s", newAccount.name), but this would 
     * include the newline character at the end of the line. The [^\n] tells the
     * program to only read as much until a newline character is encountered. 
     */
    scanf("%[^\n]s", newAccount.name);
    unsigned char* namePtr = (unsigned char*)&newAccount.name;
    // printf("Memory contents: %s\n", namePtr);
    printf("Thank you %s, your new account has been initialized with balance %d.",
           newAccount.name, newAccount.balance);
}
