/**
 * Mahdeen Ahmed Khan Sameer
 * 02/22/24
 * EX3
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    char name[10];
    int balance;
} Account;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <Name>\n", argv[0]);
        return 1; // Exit if no name is provided
    }

    Account newAccount = {"", 0};

    // We ensure that the name fits into the struct's name field, truncating if necessary
    strncpy(newAccount.name, argv[1], sizeof(newAccount.name) - 1);
    newAccount.name[sizeof(newAccount.name) - 1] = '\0'; // We ensure null-termination

    printf("Thank you %s, your new account has been initialized with balance %d.\n",
           newAccount.name, newAccount.balance);

    return 0;
}
