#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GUI.h"

#define HEIGHT 20
#define WIDTH 41

void welcome() {
    printf("\n\n");
    makeTop();
    makeSides(4);
    printText("WELCOME!");
    printText("SELECT OPTION BELOW:");
    makeSides(2);
    printText("TYPE 1 FOR SIGN-IN");
    makeSides(2);
    printText("TYPE 2 FOR SIGN-UP");
    makeSides(2);
    printText("TYPE 3 TO QUIT");
    makeSides(4);
    makeBase();
}

void homePage() {
    makeBase();
    makeSides(4);
    printText("Hello13");
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