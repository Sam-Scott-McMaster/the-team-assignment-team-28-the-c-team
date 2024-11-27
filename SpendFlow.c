#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GUI.h"
#include "GUI_inputs.h"

int main(int argc, char* argv[]) {
    int running = 1;
    char currentUser[200] = "";
    while (running) {
        welcome();
        signIn_or_Up(currentUser);



        running = 0;
    }

    return EXIT_SUCCESS;
}