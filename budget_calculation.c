#include "budget_calculation.h"
#include "users.h" 
#include <stdio.h>

void addBudget(const char *user) {
    double income, limit, savingsPercentage;

    // Prompt for income and budget limit
    printf("Enter your monthly income: ");
    scanf("%lf", &income);
    printf("Enter your monthly budget limit: ");
    scanf("%lf", &limit);

    // Validate inputs
    if (income <= 0 || limit <= 0 || limit > income) {
        printf("Error: Invalid budget values. Please try again.\n");
        return;
    }

    // Calculate suggested savings percentage
    savingsPercentage = (income - limit) / income * 100;

    // Prepare the budget entry
    char budget[200];
    snprintf(budget, sizeof(budget), "Income: %.2lf | Limit: %.2lf | Suggested Savings: %.2lf%%",
             income, limit, savingsPercentage);

    // Save the budget data
    //writeBudget(user, budget);
    printf("Budget added successfully!\n");
}
