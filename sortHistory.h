#ifndef SORTHISTORY_H
#define SORTHISTORY_H

void sortHistory(char* inputFile, char* outputFile);
int isValidDate(const char* line);
int compareDates(const void* a, const void* b);

#endif // SORTHISTORY_H
