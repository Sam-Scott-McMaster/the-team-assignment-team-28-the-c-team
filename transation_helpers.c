#include "transaction_helpers.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkDate(const char *date) {
    // Validate format YYYY-MM-DD
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Error: Invalid date format. Use YYYY-MM-DD.\n");
        return 0;
    }

    // Further validations for year, month, day can be added
    return 1;
}

int checkName(const char *name) {
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return 0;
    }
    return 1;
}

int checkCost(double cost) {
    if (cost <= 0) {
        printf("Error: Cost must be greater than zero.\n");
        return 0;
    }
    return 1;
}

int checkCategory(const char *category) {
    // Preset categories
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
