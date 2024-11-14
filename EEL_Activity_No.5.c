#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 10
#define PHONE_LENGTH 11
#define NAME_LENGTH 50
#define LOCATION_LENGTH 50


typedef struct {
    char phoneNumber[PHONE_LENGTH];
    char location[LOCATION_LENGTH];
} DirectoryEntry;


int isValidIndianPhoneNumber(char *phone) {
    if (strlen(phone) != 10) {
        return 0; 
    }
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) {
            return 0; 
        }
    }
    return 1;
}


int searchDirectory(DirectoryEntry directory[], int size, char *phone, char *location) {
    for (int i = 0; i < size; i++) {
        if (strcmp(directory[i].phoneNumber, phone) == 0) {
            strcpy(location, directory[i].location);
            return 1; 
        }
    }
    return 0;
}

int main() {
    
    DirectoryEntry directory[MAX_ENTRIES] = {
        {"9370607739", "Delhi"},
        {"8605303098", "Mumbai"},
        {"8668337547", "Kolkata"},
        {"9090909090", "Bangalore"},
        {"7070707070", "Chennai"},
        {"8080808080", "Nagpur"},
        {"6060606060", "Pune"}
    };
    int directorySize = 7;

    char customerName[NAME_LENGTH];
    char inputPhone[PHONE_LENGTH];
    char location[LOCATION_LENGTH];

    printf("Welcome to DELIVERY EXPRESS INDIA\n");

    
    printf("Enter the customer's name: ");
    fgets(customerName, NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; 

    
    printf("Enter the customer's phone number: ");
    scanf("%s", inputPhone);

    
    if (!isValidIndianPhoneNumber(inputPhone)) {
        printf("Invalid phone number. Please enter a valid 10-digit Indian phone number.\n");
        return 1;
    }

    
    if (searchDirectory(directory, directorySize, inputPhone, location)) {
        printf("\nDelivery Details:\n");
        printf("Customer Name: %s\n", customerName);
        printf("Phone Number: %s\n", inputPhone);
        printf("Delivery Location: %s\n", location);
        printf("Delivery Status: Scheduled for dispatch\n");
    } else {
        printf("\nSorry no such phone number found in directory.Cant locate the location .\n");
    }

    return 0;
}
