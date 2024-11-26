#include "transaction_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function for date validation
int checkDate(const char *date) {
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Error: Invalid date format. Use YYYY-MM-DD.\n");
        return 0;
    }
    return 1;
}

//prompts and validates a date
char *addDate() {
    char *date = malloc(11 * sizeof(char));
    do {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
    } while (!checkDate(date));
    return date;
}

//function for name validation
int checkName(const char *name) {
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return 0;
    }
    return 1;
}

//validates a transaction name
char *addName() {
    char *name = malloc(100 * sizeof(char));
    do {
        printf("Enter transaction name: ");
        scanf("%s", name);
    } while (!checkName(name));
    return name;
}

//function for cost validation
int checkCost(double cost) {
    if (cost <= 0) {
        printf("Error: Cost must be greater than zero.\n");
        return 0;
    }
    return 1;
}

//validates transaction cost
double addCost() {
    double cost;
    do {
        printf("Enter transaction cost: ");
        scanf("%lf", &cost);
    } while (!checkCost(cost));
    return cost;
}

//function for category validation
int checkCategory(const char *category) {
    const char *categories[] = {"Food", "Entertainment", "Bills", "Travel", "Others"};
    int valid = 0;

    for (int i = 0; i < 5; ++i) {
        if (strcmp(category, categories[i]) == 0) {
            valid = 1;
            break;
        }
    }

    if (!valid) {
        printf("Error: Invalid category. Choose from: Food, Entertainment, Bills, Travel, Others.\n");
    }
    return valid;
}

//validates a category
char *addCategory() {
    char *category = malloc(50 * sizeof(char));
    do {
        printf("Enter transaction category (Food, Entertainment, Bills, Travel, Others): ");
        scanf("%s", category);
    } while (!checkCategory(category));
    return category;
}
