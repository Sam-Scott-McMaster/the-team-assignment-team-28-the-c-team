#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "GUI_inputs.h"
#include "users.h"

void  loading() {
    for (int i = 1; i < 11; i++) {
        printf("\r");
        printf("Loading %d%%", i*10);
        for (int j = 0; j<i; j++) {
            printf("█████");
        }
        fflush(stdout);
        usleep(180000);
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
                checkUser();
                exit(0);
            }
            else if (input == 2) {
                loading();
                addUser();
                exit(0);
            }
            else if (input == 3) {
                exit(0);
            }
            else if (input == 1738) {
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
