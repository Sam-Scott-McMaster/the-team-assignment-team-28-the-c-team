/* (Muhammad Talha Atif), (atifm8), (December 5, 2024)
*
* Main method for SpendFlow application, main app loop is located here
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GUI.h"
#include "GUI_inputs.h"

/* help
*
* prints help flag for SpendFlow
*/
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

/* main
*
* accepts arguments to check for --help flag
* returns EXIT_SUCCESS
* Stores currently logged in user and their balance
* keeps running until the user exits the program in 
* one of the methods called from main 
* (user must select the exit option when prompted)
*/
int main(int argc, char* argv[]) {
    if (argc > 1) { 
        //Checks if argument --help is given from user
        if (strcmp(argv[1], "--help") == 0 ) {
            help();
            exit(0);
        }
    }

    //currentUser, updated by other methods
    char currentUser[200] = "";
    //accountBalance for current user, set to -1 initially
    double accountBalance = -1;
    
    //Prints welcome menu in terminal
    welcome();
    //Lets user sign in or up, updating currentUser name
    signIn_or_Up(currentUser);
    while (1) {
        //Continues prompting user for next action until they exit
        action(currentUser,&accountBalance);
    }
    //Exits
    return EXIT_SUCCESS;
}