#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GUI.h"

#define HEIGHT 20
#define WIDTH 41

void homePage() {
    makeLine(WIDTH);
    makeSides(4);
    printText("Hello", WIDTH-2);
    

}

void makeSides(int h) {
    for (int i = 0; i < h; i++) {
        printf("|%*s", WIDTH, "|\n");
    }
}

void makeLine(int w) {
    for (int i = 0; i < w; i++) {
        printf("_");
    }
    printf("\n");
}

void printText(char* text, int width) {
    int textLen = strlen(text);
    int padding = (width - textLen) / 2;
    padding += (width - textLen) % 2;

    printf("|");
    printf("%*s%-*s", padding, "", textLen + padding, text);
    printf("|\n");
}