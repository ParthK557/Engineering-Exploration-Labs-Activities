#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isAlphabetic(const char *str) {
    while (*str) {
        if (!isalpha(*str) && *str != ' ') {
            return 0;
        }
        str++;
    }
    return 1;
}

int isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str) && *str != '.') {
            return 0;
        }
        str++;
    }
    return 1;
}

void calculateFunds(float *budget, float *total) {
    char fundName[50];
    char fundAmountStr[20];
    float fundAmount;

    
    if (*total > *budget) {
        printf("\nWarning: Your total expense is above the budget of %.2f!\n", *budget);
        return;
    }

    printf("\nEnter the fund name (or type 'over' to finish): ");
    scanf(" %[^\n]s", fundName); 

    
    if (strcmp(fundName, "over") == 0) {
        printf("\nTotal expenses: %.2f\n", *total);
        if (*total <= *budget) {
            printf("You are within the budget.\n");
        }
        return;
    }

    printf("Enter the amount for %s: ", fundName);
    scanf(" %s", fundAmountStr);

    
    if (!isNumeric(fundAmountStr)) {
        printf("Invalid input. Please enter a valid numeric value for the amount.\n");
        calculateFunds(budget, total);
        return;
    }

    fundAmount = atof(fundAmountStr);
    *total += fundAmount; 

    
    calculateFunds(budget, total);
}

int main() {
    char name[50];
    char identity[15];
    char budgetStr[20];
    float budget, total = 0;

    
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; 

    if (!isAlphabetic(name)) {
        printf("Invalid input. Name should contain only alphabets.\n");
        return 1;
    }

    printf("Enter your Identification number: ");
    fgets(identity, sizeof(identity), stdin);
    identity[strcspn(identity, "\n")] = '\0';

    
    printf("Enter the budget for the party: ");
    scanf(" %s", budgetStr);

    if (!isNumeric(budgetStr)) {
        printf("Invalid input. Budget should be a numeric value.\n");
        return 1;
    }

    budget = atof(budgetStr);

    printf("\nParty Budget Tracker\n");
    printf("Name: %s\n", name);
    printf("Identification Number: %s\n", identity);
    printf("Budget: %.2f\n", budget);


    printf("\nProvide Expenses Name  (e.g., food, decoration, etc.):\n");
    printf("Type 'over' when finished.\n");
    calculateFunds(&budget, &total); 

    return 0;
}