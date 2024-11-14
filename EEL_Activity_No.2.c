#include <stdio.h>

int main() {
    char name[50];
    int preMarks, optMarks, mainsMarks = 0, totalMarks = 0;

    // Input name without string.h
    printf("Enter your name: ");
    scanf("%49s", name);

    // Function to input and validate marks
    int inputMarks(char *exam) {
        int marks;
        do {
            printf("Enter %s marks (0-100): ", exam);
            scanf("%d", &marks);
            if (marks < 0 || marks > 100) {
                printf("Invalid input! Marks should be between 0 and 100.\n");
            }
        } while (marks < 0 || marks > 100);
        return marks;
    }

    // Input marks for Preliminary, Optional, and Mains
    preMarks = inputMarks("Preliminary");
    if (preMarks < 45) {
        printf("Failed in Preliminary. Total Marks: %d out of 300\n", preMarks);
        return 0;
    }
    totalMarks += preMarks;

    optMarks = inputMarks("Optional");
    if (optMarks < 33) {
        printf("Failed in Optional. Total Marks: %d out of 300\n", totalMarks + optMarks);
        return 0;
    }
    totalMarks += optMarks;

    mainsMarks = inputMarks("Mains");
    totalMarks += mainsMarks;

    // Display total marks and post eligibility
    printf("Total Marks: %d out of 300\n", totalMarks);
    if (totalMarks >= 198) printf("Eligible for Post  CHIEF FIELD OFFICER\n");
    else if (totalMarks >= 176) printf("Eligible for Post DEPUTY FIELD OFFICER\n");
    else if (totalMarks >= 126) printf("Eligible for Post ASSISTANT FIELD OFFICER\n");
    else printf("Not eligible for any post\n");

    return 0;
}