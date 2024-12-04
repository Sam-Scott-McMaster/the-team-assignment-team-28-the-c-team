/* Viraj Patel, 400523560, December 5, 2024
 *
 * This file implements various helper functions for validating and adding transaction details such as date, name, cost, and category.
 * It also includes error handling to ensure correct input formatting and prompting for the user.
 */

#include "transaction_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* checkDate
 * Validates the date format provided by the user. The expected format is YYYY-MM-DD.
 * prints an error message and returns 0 if invalid
 */
int checkDate(const char *date) {
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Error: Invalid date format. Use YYYY-MM-DD.\n");
        return 0;
    }
    return 1;
}

/* addDate
 * Prompts the user to enter a date in the format YYYY-MM-DD.
 * Validates the input using checkDate and repeats until a valid date is entered.
 * Returns a dynamically allocated string containing the valid date.
 */
char *addDate() {
    char *date = malloc(11 * sizeof(char)); // Allocate memory for date string
    do {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
    } while (!checkDate(date)); // Loop until a valid date is entered
    return date;
}

/* checkName
 * Ensures that the provided transaction name is not empty.
 * Returns if valid, otherwise prints an error message
 */
int checkName(const char *name) {
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return 0;
    }
    return 1;
}

/* addName
 * Prompts the user to enter a transaction name.
 * Validates the input using checkName and repeats until a valid name is entered.
 * Returns a dynamically allocated string containing the valid name.
 */
char *addName() {
    char *name = malloc(100 * sizeof(char)); // Allocate memory for name string
    do {
        printf("Enter transaction name: ");
        scanf("%s", name);
    } while (!checkName(name)); // Loop until a valid name is entered
    return name;
}

/* checkCost
 * Validates that the transaction cost is greater than zero.
 * prints an error message if not valid
 */
int checkCost(double cost) {
    if (cost <= 0) {
        printf("Error: Cost must be greater than zero.\n");
        return 0;
    }
    return 1;
}

/* addCost
 * Prompts the user to enter a transaction cost.
 * Validates the input using checkCost and repeats until a valid cost is entered.
 * Returns the valid transaction cost as a double.
 */
double addCost() {
    double cost;
    do {
        printf("Enter transaction cost: ");
        scanf("%lf", &cost);
    } while (!checkCost(cost)); // Loop until a valid cost is entered
    return cost;
}

/* checkCategory
 * Validates the transaction category based on predefined options (1: Food, 2: Entertainment, 3: Bills, 4: Other).
 * Copies the corresponding category name to cata
 * prints an error message if not valid
 */
int checkCategory(int category, char *cata) {
    const char *categories[] = {"Food", "Entertainment", "Bills", "Other"};
    int valid = 0;

    if (category > 0 && category < 5) {
        strcpy(cata, categories[category - 1]); // Map category index to category name
        valid = 1;
    }
    if (!valid) {
        printf("Error: Invalid category. Choose from: Food, Entertainment, Bills, Other.\n");
    }
    return valid;
}
