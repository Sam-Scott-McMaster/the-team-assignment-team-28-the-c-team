<<<<<<< HEAD
//team 28 - Provides functions for validating and prompting user input for transaction details including date, name, cost, and category.
=======
/* Viraj Patel, 400523560, December 5, 2024
 *
 * This file implements various helper functions for validating and adding transaction details such as date, name, cost, and category.
 * It also includes error handling to ensure correct input formatting and prompting for the user.
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5

#include "transaction_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

<<<<<<< HEAD
// Function to prompt the user for a date and validate the input
// Prompts until a valid date is entered
// Returns: a dynamically allocated string containing the valid date
=======
/* checkDate
 * Validates the date format provided by the user. The expected format is YYYY-MM-DD.
 * prints an error message and returns 0 if invalid
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
int checkDate(const char *date) {
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Error: Invalid date format. Use YYYY-MM-DD.\n");
        return 0;
    }
    return 1;
}

<<<<<<< HEAD
// Function to prompt the user for a date and validate the input
// Prompts until a valid date is entered
// Returns: a dynamically allocated string containing the valid date
=======
/* addDate
 * Prompts the user to enter a date in the format YYYY-MM-DD.
 * Validates the input using checkDate and repeats until a valid date is entered.
 * Returns a dynamically allocated string containing the valid date.
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
char *addDate() {
    char *date = malloc(11 * sizeof(char)); // Allocate memory for date string
    do {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);
    } while (!checkDate(date)); // Loop until a valid date is entered
    return date;
}

<<<<<<< HEAD

// Function to validate a transaction name
// Parameters: name (const char*)
// Returns: 1 if the name is valid, 0 otherwise
=======
/* checkName
 * Ensures that the provided transaction name is not empty.
 * Returns if valid, otherwise prints an error message
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
int checkName(const char *name) {
    if (strlen(name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return 0;
    }
    return 1;
}

<<<<<<< HEAD
// Function to prompt the user for a transaction name and validate the input
// Prompts until a valid name is entered
// Returns: a dynamically allocated string containing the valid name
=======
/* addName
 * Prompts the user to enter a transaction name.
 * Validates the input using checkName and repeats until a valid name is entered.
 * Returns a dynamically allocated string containing the valid name.
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
char *addName() {
    char *name = malloc(100 * sizeof(char)); // Allocate memory for name string
    do {
        printf("Enter transaction name: ");
        scanf("%s", name);
    } while (!checkName(name)); // Loop until a valid name is entered
    return name;
}

<<<<<<< HEAD
// Function to validate a transaction cost
// Parameters: cost (double)
// Returns: 1 if the cost is valid, 0 otherwise
=======
/* checkCost
 * Validates that the transaction cost is greater than zero.
 * prints an error message if not valid
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
int checkCost(double cost) {
    if (cost <= 0) {
        printf("Error: Cost must be greater than zero.\n");
        return 0;
    }
    return 1;
}

<<<<<<< HEAD
// Function to prompt the user for a transaction cost and validate the input
// Prompts until a valid cost is entered
// Returns: the valid cost as a double
=======
/* addCost
 * Prompts the user to enter a transaction cost.
 * Validates the input using checkCost and repeats until a valid cost is entered.
 * Returns the valid transaction cost as a double.
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
double addCost() {
    double cost;
    do {
        printf("Enter transaction cost: ");
        scanf("%lf", &cost);
    } while (!checkCost(cost)); // Loop until a valid cost is entered
    return cost;
}

<<<<<<< HEAD
// Function to validate a transaction category
// Parameters: category (int), cata (char* to append category name)
// Returns: 1 if the category is valid, 0 ot
=======
/* checkCategory
 * Validates the transaction category based on predefined options (1: Food, 2: Entertainment, 3: Bills, 4: Other).
 * Copies the corresponding category name to cata
 * prints an error message if not valid
 */
>>>>>>> ddb95419ff7c388f20297ddd646fd82d20aafff5
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
