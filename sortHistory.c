#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to compare two lines by date ( in the yyyy-mm-dd format)
int compareDates(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

//will chekc if  a line starts with a valid date in yyyy-mm-dd format
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
    if (!outFile) {
        perror("Error opening output file");
        for (size_t i = 0; i < lineCount; i++) {
            free(lines[i]);
        }
        free(lines);
        return;
    }

    for (size_t i = 0; i < lineCount; i++) {
        fprintf(outFile, "%s", lines[i]);
        free(lines[i]);
    }

    free(lines);
    fclose(outFile);

    printf("Sorted history saved to file: %s\n", outputFile);
}

// how it should be used:
// calling this function with the filename made by allTrans()
// in geeneral: char* filename = allTrans("username");
// and then: sortHistory(filename);


