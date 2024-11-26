#ifndef TRANSACTION_HELPERS_H
#define TRANSACTION_HELPERS_H

int checkDate(const char *date);
int checkName(const char *name);
int checkCost(double cost);
int checkCategory(const char *category);

char *addDate();
char *addName();
double addCost();
char *addCategory();

#endif
