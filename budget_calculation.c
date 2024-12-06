/* Viraj Patel, 400523560, December 5, 2024
 *
 * This file implements a helper function `addBudget` that calculates and stores a user's budget. 
 * The function prompts the user for their monthly income and spending on needs, validates the input, 
 * calculates the disposable income, and suggests a savings amount.
 * It then stores the budget data using the `writeBudget` function.
 */
#include "budget_calculation.h"
#include "users.h"
#include <stdio.h>

/* addBudget
 * This function calculates and adds a user's budget by prompting for their income and monthly needs, then calculating their disposable income and suggested savings.
 * The budget data is then stored using the writeBudget function.
 *
 * Parameters:
 * - user: A pointer to the username of the currently signed-in user. This is used to associate the budget with the correct user.
 */
void addBudget(char *user) {
    double income, needs, disposableIncome, suggestedSavings;  // Variables for income, needs, disposable income, and suggested savings
    int validInput; 

    //Loop until valid inputs are received
    while (1) {
        //Prompt for income and check if it's a valid number
        printf("Enter your monthly income: ");
        validInput = scanf("%lf", &income);
        if (validInput != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');  
            continue;  
        }

        //Prompt for money spent on needs and check if it's a valid number
        printf("Enter your monthly spending on needs: ");
        validInput = scanf("%lf", &needs);
        if (validInput != 1) {
            printf("Error: Please enter a valid number.\n");
            while (getchar() != '\n');  
            continue; 
        }

        //Validate inputs: income must be greater than 0, needs must be between 0 and income
        if (income > 0 && needs >= 0 && needs <= income) {
            break;  //Exit the loop if inputs are valid
        } else {
            printf("Error: Invalid values, should be non-negative and less than or equal to income.\n");
        }
    }

    // Calculate disposable income and suggested savings (20% of disposable income)
    disposableIncome = income - needs;
    suggestedSavings = disposableIncome * 0.20;

    // Prepare the budget entry string with formatted values
    char budget[200];
    snprintf(budget, sizeof(budget),
             "Income: %.2lf | Needs: %.2lf | Disposable Income: %.2lf | Suggested Savings: %.2lf",
             income, needs, disposableIncome, suggestedSavings);

    //Save the budget data to the file using the writeBudget function
    writeBudget(user, budget);
    printf("Budget added successfully!\n");
    return;
}
