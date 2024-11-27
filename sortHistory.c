#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allTrans(char* userName);

int compareLines(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

void sortHistory(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char** lines = NULL;
    size_t lineCount = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file)) {
        lines = realloc(lines, (lineCount + 1) * sizeof(char*));
        lines[lineCount] = strdup(buffer); 
        lineCount++;
    }
    fclose(file);

    qsort(lines, lineCount, sizeof(char*), compareLines);

    file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        for (size_t i = 0; i < lineCount; i++) {
            free(lines[i]);
        }
        free(lines);
        return;
    }

    for (size_t i = 0; i < lineCount; i++) {
        fprintf(file, "%s", lines[i]); 
        free(lines[i]);               
    }

    free(lines);
    fclose(file);

    printf("History sorted and saved to file: %s\n", filename); //needed?
}
// how it should be used:
// calling this function with the filename made by allTrans()
// in geeneral: char* filename = allTrans("username");
// and then: sortHistory(filename);


