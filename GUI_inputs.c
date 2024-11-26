#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "GUI_inputs.h"

void  loading() {
    for (int i = 1; i < 11; i++) {
        printf("\r");
        printf("Loading %d%%", i*10);
        for (int j = 0; j<i; j++) {
            printf("█████");
        }
        fflush(stdout);
        usleep(500000);
    }
    printf("\033[2K");
}
void signIn_or_Up() {
    printf("\n\n");
    int input;
    int inputCheck;
    int c;
    while(1) {
        inputCheck = scanf("%d", &input);
        if (inputCheck && input < 4 && input > 0) {
            if (input == 1) {
                //checkUser()
                loading();
                printf("\nSign-in\n");
                exit(0);
            }
            else if (input == 2) {
                //addUser()
                loading();
                printf("Sign-up");
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
    }
}
