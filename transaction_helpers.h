#ifndef TRANSACTION_HELPERS_H
#define TRANSACTION_HELPERS_H


int checkDate(const char *date);
int checkName(const char *name);
int checkCost(double cost);
int checkCategory(int category, char* cata);

char *addDate();
char *addName();
double addCost();
char *addCategory();
void addTransaction(char* userName);
#endif
