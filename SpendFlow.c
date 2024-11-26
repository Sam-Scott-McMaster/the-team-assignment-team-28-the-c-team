#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GUI.h"

int main(int argc, char* argv[]) {
    int running = 1;

    while (running) {
        homePage();
        
        running = 0;
    }

    return EXIT_SUCCESS;
}