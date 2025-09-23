#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 50
#define FLIGHT_CODE_LEN 10
#define STATUS_LEN 20
#define MAX_PASSENGERS 256
#define NAME_LEN 50

// Arrays to store flight and passenger data
char flights[MAX_FLIGHTS][FLIGHT_CODE_LEN];
char statuses[MAX_FLIGHTS][STATUS_LEN];
char passengers[MAX_FLIGHTS][MAX_PASSENGERS][NAME_LEN];
int passengerCounts[MAX_FLIGHTS] = {0};
int flightCount = 0;

// Print header
void printHeader() {
    printf("==================================================\n");
    printf("            AIRPORT MANAGEMENT SYSTEM            \n");
    printf("==================================================\n");
}

// Print menu
void printMenu() {
    printf("\nMENU:\n");
    printf("0  - Print help information\n");
    printf("1  - View list of flights\n");
    printf("2  - Update flight status\n");
    printf("3  - Add a new flight\n");
    printf("4  - Delete a flight\n");
    printf("5  - Edit a flight\n");
    printf("6  - Print flight summary\n");
    printf("7  - Add a passenger at the airport\n");
    printf("8  - Add a passenger to a flight\n");
    printf("9  - Change passenger status\n");
    printf("10 - Print passenger list for a flight\n");
    printf("11 - Exit program\n");
}

// Print flights
void printFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("\nList of Flights:\n");
    for (int i = 0; i < flightCount; i++) {
        printf("%d. Flight Number: %s | Status: %s | Passengers: %d\n", i + 1, flights[i], statuses[i], passengerCounts[i]);
    }
}

// Update flight status
void updateFlightStatus() {
    if (flightCount == 0) {
        printf("No flights available to update.\n");
        return;
    }
    int index;
    printf("Enter flight index to update status (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    printf("Enter new status (Active/Delayed/Canceled): ");
    scanf("%s", statuses[index]);
    printf("Flight status updated successfully!\n");
}

// Add a flight
void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        printf("Flight limit reached!\n");
        return;
    }
    printf("Enter flight number: ");
    scanf("%s", flights[flightCount]);
    printf("Enter flight status (Active/Delayed/Canceled): ");
    scanf("%s", statuses[flightCount]);
    passengerCounts[flightCount] = 0;
    flightCount++;
    printf("Flight added successfully!\n");
}

// Delete a flight
void deleteFlight() {
    if (flightCount == 0) {
        printf("No flights available to delete.\n");
        return;
    }
    int index;
    printf("Enter flight index to delete (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    for (int i = index; i < flightCount - 1; i++) {
        strcpy(flights[i], flights[i + 1]);
        strcpy(statuses[i], statuses[i + 1]);
        for (int j = 0; j < passengerCounts[i + 1]; j++) {
            strcpy(passengers[i][j], passengers[i + 1][j]);
        }
        passengerCounts[i] = passengerCounts[i + 1];
    }
    flightCount--;
    printf("Flight deleted successfully!\n");
}

// Print flight summary
void printFlightSummary() {
    printFlights();
}

// Add a passenger to a flight
void addPassenger() {
    int index;
    if (flightCount == 0) {
        printf("No flights available to add a passenger.\n");
        return;
    }
    printf("Enter flight index to add a passenger (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    if (passengerCounts[index] >= MAX_PASSENGERS) {
        printf("Passenger limit reached for this flight!\n");
        return;
    }
    printf("Enter passenger name: ");
    scanf("%s", passengers[index][passengerCounts[index]]);
    passengerCounts[index]++;
    printf("Passenger added successfully!\n");
}

// Print passengers of a flight
void printPassengers() {
    int index;
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("Enter flight index to view passengers (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    printf("Passengers on Flight %s:\n", flights[index]);
    for (int i = 0; i < passengerCounts[index]; i++) {
        printf("%d. %s\n", i + 1, passengers[index][i]);
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printHeader();
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printFlights(); break;
            case 2: updateFlightStatus(); break;
            case 3: addFlight(); break;
            case 4: deleteFlight(); break;
            case 6: printFlightSummary(); break;
            case 8: addPassenger(); break;
            case 10: printPassengers(); break;
            case 11: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
