#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "GUI.h"
#include "GUI_inputs.h"
#include "users.h"
#include "budget_calculation.h"
#include "transaction_helpers.h"
#include "sortHistory.h"

void action(char* user) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0 || input == 1738) {
            if (input == 1) {
                loading();
                transactionMenu(user);
                transaction(user);
                return;
            }
            else if (input == 2) {
                loading();
                budgetMenu(user);
                budget(user);
                return;
            }
            else if (input == 3) {
                exit(0);
            }
            else if (input == 1738) { //Testing code
                loading();
                return;
            }
        }
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}


void budget(char* user) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0) {
            if (input == 1) {
                addBudget(user);
            }
            else if (input == 2) {
                viewBudget(user);
            }
            else if (input == 3) {
                exit(0);
            }
        }
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        
        while ((c = getchar()) != '\n' && c != EOF) { }
        budgetMenu(user);

    }
}

void transaction(char* user) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0) {
            if (input == 1) {
                addTransaction(user);
            }
            else if (input == 2) {
                printf("sort history");
                //sortHistory();
                exit(0);
            }
            else if (input == 3) {
                exit(0);
            }
        }
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }

        while ((c = getchar()) != '\n' && c != EOF) { }
       transactionMenu(user);

    }
}

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
void signIn_or_Up(char* user) {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0 || input == 1738) {
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
            else if (input == 1738) { //Testing code
                loading();
                return;
            }
        }
        else {
            printf("\033[1A");
            printf("\033[2K");
            printf("Invalid input, try again: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

void viewBudget(char* user) {
    FILE *fileOpen = fopen(allBud(user), "r+");

    char line[1024];
    while (fgets(line, sizeof(line), fileOpen)) {
        printf("%s", line);
    }

    fclose(fileOpen);
    return;
}
