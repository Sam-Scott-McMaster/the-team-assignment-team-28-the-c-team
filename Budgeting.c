#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void checkDate(char *date);
void addDate(char *date);
void checkName(char *name);
void addName(char *name);
void checkCost(float *cost);
void addCost(float *cost);
void checkCategory(int *category);
void addCategory(int *category);
void writeTransaction(const char *date, const char *name, float cost, int category);

void addBudget(float income, float expenses, float *suggestedBudget, float *categoryBudgets);
void writeBudget(const char *filename, float suggestedBudget, float *categoryBudgets);

void checkDate(char *date) {
    // Ensure the date format is valid (e.g., YYYY-MM-DD)
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    // You can add validation logic here to ensure the format is correct
}

void addDate(char *date) {
    checkDate(date);
}

void checkName(char *name) {
    // Ensure the transaction name is valid
    printf("Enter transaction name: ");
    scanf("%s", name);
    // Additional validation logic can be added here
}

void addName(char *name) {
    checkName(name);
}

void checkCost(float *cost) {
    // Ensure the cost is a positive number
    printf("Enter transaction cost: ");
    scanf("%f", cost);
    if (*cost <= 0) {
        printf("Cost must be a positive value.\n");
        checkCost(cost);
    }
}

void addCost(float *cost) {
    checkCost(cost);
}

void checkCategory(int *category) {
    // Provide predefined category options
    printf("Select a category:\n");
    printf("1 - Food\n2 - Entertainment\n3 - Bills\n4 - Other\n");
    scanf("%d", category);
    if (*category < 1 || *category > 4) {
        printf("Invalid category. Try again.\n");
        checkCategory(category);
    }
}

void addCategory(int *category) {
    checkCategory(category);
}

void writeTransaction(const char *date, const char *name, float cost, int category) {
    FILE *file = fopen("transactions.txt", "a");
    if (file == NULL) {
        printf("Error opening transaction file.\n");
        return;
    }
    fprintf(file, "%s,%s,%.2f,%d\n", date, name, cost, category);
    fclose(file);
}

void addBudget(float income, float expenses, float *suggestedBudget, float *categoryBudgets) {
    // Calculate suggested budget and breakdown per category
    *suggestedBudget = income - expenses;
    if (*suggestedBudget < 0) {
        printf("Warning: You are overspending!\n");
    }
    //later on let user decide how much each category should be
    categoryBudgets[0] = 0.5 * (*suggestedBudget); // 50% for Food
    categoryBudgets[1] = 0.2 * (*suggestedBudget); // 20% for Entertainment
    categoryBudgets[2] = 0.2 * (*suggestedBudget); // 20% for Bills
    categoryBudgets[3] = 0.1 * (*suggestedBudget); // 10% for Other
}

void writeBudget(const char *filename, float suggestedBudget, float *categoryBudgets) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening budget file.\n");
        return;
    }
    fprintf(file, "Suggested Budget: %.2f\n", suggestedBudget);
    fprintf(file, "Food: %.2f\n", categoryBudgets[0]);
    fprintf(file, "Entertainment: %.2f\n", categoryBudgets[1]);
    fprintf(file, "Bills: %.2f\n", categoryBudgets[2]);
    fprintf(file, "Other: %.2f\n", categoryBudgets[3]);
    fclose(file);
}
