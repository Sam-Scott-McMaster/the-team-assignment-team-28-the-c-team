#ifndef SORTHISTORY_H
#define SORTHISTORY_H

void sortHistory(char* inputFile, char* outputFile);
int isValidDate(const char* line);
int compareDates(const void* a, const void* b);
void printFileToTerminal(const char* filename); // Added function prototype

#endif // SORTHISTORY_H
