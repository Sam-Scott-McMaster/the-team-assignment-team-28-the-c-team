//team 28 - Provides functions for validating and prompting user input for transaction details including date, name, cost, and category.

#include "transaction_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to prompt the user for a date and validate the input
// Prompts until a valid date is entered
// Returns: a dynamically allocated string containing the valid date
int checkDate(const char *date) {
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Error: Invalid date format. Use YYYY-MM-DD.\n");
        return 0;
    }
    return 1;
}

// Function to prompt the user for a date and validate the input
// Prompts until a valid date is entered
// Returns: a dynamically allocated string containing the valid date
char *addDate() {
    char *date = malloc(11 * sizeof(char));
    do {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
    } while (!checkDate(date));
    return date;
}


// Function to validate a transaction name
// Parameters: name (const char*)
// Returns: 1 if the name is valid, 0 otherwise
int checkName(const char *name) {
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return 0;
    }
    return 1;
}

// Function to prompt the user for a transaction name and validate the input
// Prompts until a valid name is entered
// Returns: a dynamically allocated string containing the valid name
char *addName() {
    char *name = malloc(100 * sizeof(char));
    do {
        printf("Enter transaction name: ");
        scanf("%s", name);
    } while (!checkName(name));
    return name;
}

// Function to validate a transaction cost
// Parameters: cost (double)
// Returns: 1 if the cost is valid, 0 otherwise
int checkCost(double cost) {
    if (cost <= 0) {
        printf("Error: Cost must be greater than zero.\n");
        return 0;
    }
    return 1;
}

// Function to prompt the user for a transaction cost and validate the input
// Prompts until a valid cost is entered
// Returns: the valid cost as a double
double addCost() {
    double cost;
    do {
        printf("Enter transaction cost: ");
        scanf("%lf", &cost);
    } while (!checkCost(cost));
    return cost;
}

// Function to validate a transaction category
// Parameters: category (int), cata (char* to append category name)
// Returns: 1 if the category is valid, 0 ot
int checkCategory(int category, char *cata) {
    const char *categories[] = {"Food", "Entertainment", "Bills", "Travel", "Others"};
    int valid = 0;

    if (category > 0 && category < 5) {
        strcat(cata, categories[category-1]);
        valid = 1;
    }
    if (!valid) {
        printf("Error: Invalid category. Choose from: Food, Entertainment, Bills, Travel, Others.\n");
    }
    return valid;
}

/*validates a category
char *addCategory() {
    char *category = malloc(50 * sizeof(char));
    do {
        printf("Enter transaction category (Food, Entertainment, Bills, Travel, Others): ");
        scanf("%s", category);
    } while (!checkCategory(category));
    return category;
}
*/