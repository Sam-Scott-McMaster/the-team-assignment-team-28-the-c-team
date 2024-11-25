#include <stdio.h>
#include <stdlib.h>

void addTransaction() {
    printf("Enter transaction date (YYYY-MM-DD): ");
    char date[11];
    scanf("%10s", date);
    if (!checkDate(date)) {
        printf("Invalid date format. Please try again.\n");
        return;
    }

    printf("Enter transaction name: ");
    char name[50];
    scanf("%49s", name);
    if (!checkName(name)) {
        printf("Invalid name. Please try again.\n");
        return;
    }

    printf("Enter transaction cost: ");
    float cost;
    if (scanf("%f", &cost) != 1 || !checkCost(cost)) {
        printf("Invalid cost. Please try again.\n");
        return;
    }

    printf("Choose a category: 1) Food 2) Entertainment 3) Bills 4) Other: ");
    int category;
    if (scanf("%d", &category) != 1 || !checkCategory(category)) {
        printf("Invalid category. Please try again.\n");
        return;
    }

    addDate(date);
    addName(name);
    addCost(cost);
    addCategory(category);

    writeTransaction();
}
