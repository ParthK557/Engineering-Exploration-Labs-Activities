#include <stdio.h>
#include <string.h>

// Custom function to convert a string to a float
float stringToFloat(char *str) {
    float result = 0.0;
    int decimalFound = 0;
    float decimalDivisor = 1.0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            if (decimalFound) return -1;  // Invalid input: multiple decimal points
            decimalFound = 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (decimalFound) {
                decimalDivisor *= 10.0;
                result = result + (str[i] - '0') / decimalDivisor;
            } else {
                result = result * 10.0 + (str[i] - '0');
            }
        } else {
            return -1;  // Invalid character in input
        }
    }

    return result;
}

// Function to calculate and display wheat contributions
void calculateWheatProduction(float *production, int n) {
    float totalProduction = 0;
    int highestExportIndex = 0;

    // Calculate total production
    for (int i = 0; i < n; i++) {
        totalProduction += production[i];
    }

    // Display total production and percentage contributions
    printf("\nOverall Wheat Production: %.2f tons\n", totalProduction);
    printf("Percentage Contribution of Each Country:\n");

    for (int i = 0; i < n; i++) {
        float percentage = (production[i] / totalProduction) * 100;
        printf("Country %d: %.2f%%\n", i + 1, percentage);

        // Track the highest export country
        if (production[i] > production[highestExportIndex]) {
            highestExportIndex = i;
        }
    }

    // Display the country with the highest wheat export
    printf("\nCountry %d has the highest wheat export with %.2f tons.\n", highestExportIndex + 1, production[highestExportIndex]);
}

int main() {
    int n;

    // Get the number of countries
    printf("Enter the number of countries: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. The number of countries must be positive.\n");
        return 1;
    }

    // Array to store wheat production for each country
    float production[n];
    char input[100];

    // Get input for each country's wheat production in tons
    for (int i = 0; i < n; i++) {
        printf("Enter wheat production for country %d (in tons): ", i + 1);
        scanf("%s", input);

        // Convert input string to float
        production[i] = stringToFloat(input);

        // Check for non-positive or invalid input
        if (production[i] <= 0) {
            printf("Invalid input. Wheat production must be a positive number.\n");
            return 1;
        }
    }

    // Calculate and display results
    calculateWheatProduction(production, n);

    return 0;
}
