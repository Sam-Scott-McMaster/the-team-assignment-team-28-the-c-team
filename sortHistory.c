//Team 28 - Contains functions to validate, sort, and display transaction data based on date.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compare two lines by date in the yyyy-mm-dd format
// Parameters: two void pointers to lines (strings)
// Returns: an integer based on strcmp (negative, zero, or positive)
int compareDates(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Function to check if a line starts with a valid date in the yyyy-mm-dd format
// Parameter: a string (line) to validate
// Returns: 1 if the line starts with a valid date, 0 otherwise
int isValidDate(const char* line) {
    if (strlen(line) < 10) return 0; //  checks for if line is at least 10 characters
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (line[i] != '-') return 0; 
        } else {
            if (!isdigit(line[i])) return 0; 
        }
    }
    return 1;
}

// Function to read lines from an input file, filter for valid date lines, and sort them by date
// Parameters: inputFile (name of the input file), outputFile (name of the output file)
// Creates a sorted list of lines starting with valid dates and writes them to the output file
void sortHistory(char* inputFile, char* outputFile) {
    FILE* file = fopen(inputFile, "r");
    if (!file) {
        perror("Error opening input file");
        return;
    }

    char** lines = NULL;
    size_t lineCount = 0;
    char buffer[256];

    //read lines starting with dates
    while (fgets(buffer, sizeof(buffer), file)) {
        if (isValidDate(buffer)) {
            lines = realloc(lines, (lineCount + 1) * sizeof(char*));
            lines[lineCount] = strdup(buffer);
            lineCount++;
        }
    }
    fclose(file);

    // should sort the lines by date
    qsort(lines, lineCount, sizeof(char*), compareDates);

    //Sorted lines to ouptut file
    FILE* outFile = fopen(outputFile, "w");
    
    fprintf(outFile, "Sorted Transactions\n");
    fprintf(outFile, "--------------------\n");

    for (size_t i = 0; i < lineCount; i++) {
        fprintf(outFile, "%s", lines[i]);
        free(lines[i]);
    }

    free(lines);
    fclose(outFile);

}

// Function to print the contents of a file to the terminal
// Parameter: filename (name of the file to print)
// Reads the file line by line and prints each line to the terminal
void printFileToTerminal(const char* filename) {
    FILE* file = fopen(filename, "r");

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer); // Print each line to the terminal
    }

    fclose(file);
}

// how it should be used:
// calling this function with the filename made by allTrans()
// in geeneral: char* filename = allTrans("username");
// and then: sortHistory(filename);


