#include "budget_calculation.h"
#include "users.h"
#include <stdio.h>

void addBudget(char *user) {
    double income, limit, savingsPercentage;
    int validInput;

    // Loop until valid inputs are received
    while (1) {
        // Prompt for income
        printf("Enter your monthly income: ");
        validInput = scanf("%lf", &income);
        if (validInput != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        // Prompt for budget limit
        printf("Enter your monthly budget limit: ");
        validInput = scanf("%lf", &limit);
        if (validInput != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        // Validate inputs
        if (income > 0 && limit > 0 && limit <= income) {
            break;
        } else {
            printf("Error: Invalid budget values. Please try again.\n");
        }
    }

    // Calculate suggested savings percentage
    savingsPercentage = (income - limit) / income * 100;

    // Prepare the budget entry
    char budget[200];
    snprintf(budget, sizeof(budget), "Income: %.2lf | Limit: %.2lf | Suggested Savings: %.2lf%%",
             income, limit, savingsPercentage);

    // Save the budget data
    writeBudget(user, budget);
    printf("Budget added successfully!\n");
}
