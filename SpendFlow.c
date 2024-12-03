#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GUI.h"
#include "GUI_inputs.h"

void help() {
    printf("SpendFlow helps users track their expenses and budget effectively.\n");
    printf("Users can input financial transactions, categorize them\n");
    printf("(e.g., food, entertainment, bills), and set spending limits for specific categories.\n");
    printf("Options include: --help to display this guide\n");
    printf("\t\t   add a new transaction\n");
    printf("\t\t   view to see all budgets\n");
    printf("\t\t   set-budget to establish category budgets\n");
    printf("\t\t   exit to quit the app.\n");
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0 ) {
            help();
            exit(0);
        }
    }
    int running = 1;
    char currentUser[200] = "";
    long int accountBalance = -1;
    
    welcome();
    signIn_or_Up(currentUser);
    while (running) {
        action(currentUser,accountBalance);
    }
    return EXIT_SUCCESS;
}