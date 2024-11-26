#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GUI.h"
#include "GUI_inputs.h"

int main(int argc, char* argv[]) {
    int running = 1;
    
    while (running) {
        homePage();
        //welcome();
        //signIn_or_Up();



        running = 0;
    }

    return EXIT_SUCCESS;
}