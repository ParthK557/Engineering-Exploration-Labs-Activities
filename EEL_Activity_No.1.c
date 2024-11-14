#include <stdio.h>

#define MIN_WEIGHT 1   // Minimum weight in kg
#define MAX_WEIGHT 8 // Maximum weight in kg
#define TIME_PER_KG 7 // Time in minutes per kg

washCycle(int weight) {
    // Estimate time based on weight
    int time = weight * TIME_PER_KG; 
    printf("Washing in progress for %d minutes...\n", time);
}

int main() {
    int input;
    int weight;

    while (1) {
        // Input weight of laundry
        printf("Enter the weight of the laundry (in kg, %d to %d, -1 to exit): ", MIN_WEIGHT, MAX_WEIGHT);
        scanf("%d", &weight);

        // Exit condition
        if (weight == -1) {
            printf("Exiting the program.\n");
            break;
        }

        // Validate weight input
        if (weight < MIN_WEIGHT || weight > MAX_WEIGHT) {
            printf("Invalid weight! Please enter a value between %d and %d kg.\n", MIN_WEIGHT, MAX_WEIGHT);
            continue; // Prompt again
        }

        printf("Weight entered: %d kg\n", weight);
        printf("Estimated washing time: %d minutes\n", weight * TIME_PER_KG);
        
        printf("Enter 1 to start washing, 0 to stop: ");
        
        while (1) {
            scanf("%d", &input);

            if (input == 1) {
                // Start washing cycle
                washCycle(weight);
                break; // Exit the inner loop to allow for re-entering weight
            } else if (input == 0) {
                // Stop washing cycle
                printf("Washing stopped.\n");
                break; // Exit the inner loop
            } else {
                // Handle invalid input
                printf("Invalid input! Please enter 1 to start or 0 to stop: ");
            }
        }
    }

    return 0;
}
