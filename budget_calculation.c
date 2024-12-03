#include "budget_calculation.h"
#include "users.h"
#include <stdio.h>

void addBudget(char *user) {
    double income, needs, disposableIncome, suggestedSavings;
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

        // Prompt for money spent on needs
        printf("Enter your monthly spending on needs: ");
        validInput = scanf("%lf", &needs);
        if (validInput != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        // Validate inputs
        if (income > 0 && needs >= 0 && needs <= income) {
            break;
        } else {
            printf("Error: Invalid values, should be non-negative and less than or equal to income.\n");
        }
    }

    // Calculate disposable income and suggested savings
    disposableIncome = income - needs;
    suggestedSavings = disposableIncome * 0.20;

    // Prepare the budget entry
    char budget[200];
    snprintf(budget, sizeof(budget),
             "Income: %.2lf | Needs: %.2lf | Disposable Income: %.2lf | Suggested Savings: %.2lf",
             income, needs, disposableIncome, suggestedSavings);

    // Save the budget data
    writeBudget(user, budget);
    printf("Budget added successfully!\n");
}
