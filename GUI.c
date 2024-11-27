#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GUI.h"

#define HEIGHT 20
#define WIDTH 41

void welcome() {
    printf("\n\n");
    makeTop();
    makeSides(3);
    printText("WELCOME!");
    makeSides(1);
    printText("SELECT OPTION BELOW:");
    makeSides(2);
    printText("TYPE 1 FOR SIGN-IN");
    makeSides(2);
    printText("TYPE 2 FOR SIGN-UP");
    makeSides(2);
    printText("TYPE 3 TO QUIT");
    makeSides(4);
    printText("TYPE 4 FOR HELP");
    makeBase();
}

void homePage(char* user) {
    printf("\n\n");
    makeTop();
    makeSides(4);
    printText("Nice to see you");
    printText(user);
    makeSides(3);
    printText("TYPE 1 FOR TRANSACTIONS");
    makeSides(1);
    printText("TYPE 2 FOR BUDGETING");
    makeSides(1);
    printText("TYPE 3 TO EXIT");
    makeSides(3);
    makeBase();
}

void transactionMenu(char* user) {
    makeTop();
    makeSides(4);
    printText("What would you like to do");
    printText(user);
    makeSides(2);
    printText("TYPE 1 TO ADD TRANSACTION");
    makeSides(2);
    //printText("TYPE 2 TO VIEW TRANSACTIONS");
    makeSides(2);
    printText("TYPE 3 TO EXIT");
    makeSides(3);
    printText("TYPE 4 FOR HELP");
    makeBase();
}

void budgetMenu(char* user) {
    makeTop();
    makeSides(4);
    printText("What would you like to do");
    printText(user);
    makeSides(2);
    printText("TYPE 1 TO ADD BUDGET");
    makeSides(2);
    printText("TYPE 2 TO VIEW BUDGET");
    makeSides(2);
    printText("TYPE 3 TO EXIT");
    makeSides(3);
    printText("TYPE 4 FOR HELP");
    makeBase();
}


void makeSides(int h) {
    for (int i = 0; i < h; i++) {
        printf("|%*s", WIDTH, "|\n");
    }
}

void makeTop() {
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");
}

void makeBase() {
    printf("|");
    for (int i = 0; i < WIDTH-2; i++) {
        printf("_");
    }
    printf("|\n");
}

void printText(char* text) {
    int width = WIDTH-2;
    int textLen = strlen(text);
    int padding = (width - textLen) / 2;

    printf("|");
    printf("%*s%-*s", padding, "", (width-padding), text);
    printf("|\n");
}