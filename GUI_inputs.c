/* (Muhammad Talha Atif), (atifm8), (December 5, 2024)
*
* File contains all handling and function calling based
* on user inputs after a GUI menu is printed
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//Includes all methods created by group
#include "GUI.h"
#include "GUI_inputs.h"
#include "users.h"
#include "budget_calculation.h"
#include "transaction_helpers.h"
#include "sortHistory.h"

/* action
* takes in username and user balance
* is method called to accept input from homepage,
* displays next terminal menu and calls next user input
* function
* includes clean input handling for invalid inputs
*/
void action(char* user, double* balance) {
    homePage(user, balance); //Prints homepage
    printf("\n\n");
    int input;
    int inputCheck;
    int c; //int to erase current input
    while(1) { 
        inputCheck = scanf("%d", &input); //Takes input
        //Checks if input is a valid options
        if (inputCheck && input < 4 && input > 0 || input == 1738) {
            if (input == 1) {
                loading();
                transactionMenu(user);
                transaction(user,balance);
                return;
            }
            else if (input == 2) {
                loading();
                budgetMenu(user);
                budget(user,balance);
                return;
            }
            else if (input == 3) {
                exit(0);
            }
        }
        //Erases input and asks for new input
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid, try again: ");
            //Erases current input to avoid loop
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

/* budget
* handles user input for budget menu, calling appropriate methods
* also has help option
*/
void budget(char* user,double* balance) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        //Checks if input is valid
        if (inputCheck && input < 5 && input > 0) {
            if (input == 1) {
                addBudget(user);
                action(user,balance);
            }
            else if (input == 2) {
                viewBudget(user);
                action(user,balance);
            }
            else if (input == 3) {
                action(user,balance);
            }
            else if (input == 4) {
                printf("The writeBudget() function allows users to define a budget for specific spending categories.\n");
                printf("Users input their target spending limit, and the app tracks their progress.\n");
                exit(0);

            }
        }
        //Otherwise performs clean user input handling
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            //Erases current input
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

/* transaction
* takes in username and user balance
* handles invalid user input same way as previous functions
*/
void transaction(char* user, double* balance) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 6 && input > 0) {
            if (input == 1) {
                addTransaction(user, balance);
                action(user,balance);
            }
            else if (input == 2) {
                //Calls methods to print sorted transactions
                sortHistory("dataBase.txt", "sortedTrans.txt");
                printFileToTerminal("sortedTrans.txt");
                action(user,balance);
            }
            else if (input == 3) {
                setBalance(user,balance);
                action(user,balance);
            }
            else if (input == 4) {
                action(user,balance);
            }
            //Help method
            else if (input == 5) {
                printf("The addTransaction() function lets users input details for a new financial transaction.\n");
                printf("Users specify the date, category (e.g., food, entertainment), amount, and optional notes.\n");
                printf("This data is automatically saved and categorized, enabling easy tracking.\n\n");
                exit(0);
            }
        }
        else {
            //Clean invalid input handling
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

/* loading
* prints out dyanmic "animated" loading animation
* in order to immerse user in app experince
*/
void  loading() {
    for (int i = 1; i < 11; i++) {
        printf("\r");
        printf("Loading %d%%", i*10);
        for (int j = 0; j<i; j++) {
            printf("█████");
        }
        fflush(stdout);
        usleep(50000);
    }
    printf("\033[2K");
    printf("\n");
}

/* signIn_or_Up
* handles input for initial start-up for application
* forcing user to either create an account or sign in
* also allows user to exit app
*/
void signIn_or_Up(char* user) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0 || input == 4) {
            if (input == 1) {
                loading();
                checkUser(user);
                return;
            }
            else if (input == 2) {
                loading();
                addUser(user);
                return;
            }
            else if (input == 3) {
                exit(0);
            }
            else if (input == 4) { //Provides user help method
                printf("The signin/up() function allows users to either sign in to their existing SpendFlow account or create a new account.\n");
                printf("Prompted to enter 1, 2, or 3 to either sign in, sign up, or exit.\n");
                printf("Signing in retrieves the user’s saved data, including past transactions and budgets.\n");
                printf("When signing up, users provide a username and basic details, which are stored locally.\n\n");
                exit(0);
            }
        }
        else {
            //Clean and simple invalid input handling
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

/* viewBudget
* simple method to return users budget, handles in case 
* more than one budget has been created (modular in case
* program is expanded in the future)
*/
void viewBudget(char* user) {
    FILE *fileOpen = fopen(allBud(user), "r+");

    char line[1024];
    while (fgets(line, sizeof(line), fileOpen)) {
        printf("%s",line);
    }

    fclose(fileOpen);
    return;
}