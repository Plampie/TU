#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLIGHT_CODE_LEN 10
#define NAME_LEN 50

// store passenger info
typedef struct {
    char name[NAME_LEN];
    char status[20];
} Passenger;

// store flight info
typedef struct {
    char flightNumber[FLIGHT_CODE_LEN];
    char status[20];
    Passenger *passengers;
    int passengerCount;
    int passengerCapacity;
} Flight;

// array for flights
Flight *flights = NULL;
int flightCount = 0;
int flightCapacity = 10; // initial capacity

// flights array
void initializeFlights() {
    flights = (Flight *)malloc(flightCapacity * sizeof(Flight));
    if (!flights) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// print header
void printHeader() {
    printf("==================================================\n");
    printf("            AIRPORT MANAGEMENT SYSTEM v9.2.1       \n");
    printf("==================================================\n");
}

// print author
void printAuthorInfo() {
    printf("--------------------------------------------------\n");
    printf(" Author: Plamena Georgieva                         \n");
    printf(" Version: 4.5.6                                    \n");
    printf("--------------------------------------------------\n");
}

// print the main menu
void printMenu() {
    printf("\nMENU:\n");
    printf("0  - Print help information\n");
    printf("1  - View list of flights\n");
    printf("2  - Select a flight to update status\n");
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

// print help info
void print_help() {
    printf("\nHelp Information:\n");
    printf("This program manages airport operations including flights and passengers.\n");
    printf("Use the menu options to add, update, and view flight and passenger data.\n");
    printf("Enter the corresponding number for the operation you wish to perform.\n");
}

// dynamically add a flight
void add_flight() {
    if (flightCount >= flightCapacity) {
        flightCapacity *= 2; //double the capacity if reaches limit
        flights = (Flight *)realloc(flights, flightCapacity * sizeof(Flight));
        if (!flights) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    printf("Enter flight number: ");
    scanf("%s", flights[flightCount].flightNumber);
    printf("Enter flight status (Active/Delayed/Canceled): ");
    scanf("%s", flights[flightCount].status);
    printf("Enter initial passenger capacity: ");
    scanf("%d", &flights[flightCount].passengerCapacity);
    flights[flightCount].passengerCount = 0;
    flights[flightCount].passengers = (Passenger *)malloc(flights[flightCount].passengerCapacity * sizeof(Passenger));
    if (!flights[flightCount].passengers) {
        printf("Memory allocation for passengers failed!\n");
        exit(1);
    }
    flightCount++;
    printf("Flight added successfully!\n");
}


// print all flights
void print_flights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("\nList of Flights:\n");
    for (int i = 0; i < flightCount; i++) {
        printf("%d. Flight Number: %s | Status: %s | Passengers: %d\n", 
               i + 1, flights[i].flightNumber, flights[i].status, flights[i].passengerCount);
    }
}

// delete a flight
void delete_flight() {
    int index;
    printf("Enter flight index to delete (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    free(flights[index].passengers);
    for (int i = index; i < flightCount - 1; i++) {
        flights[i] = flights[i + 1];
    }
    flightCount--;
    printf("Flight deleted successfully!\n");
}

// edit a flight
void edit_flight() {
    int index, option;
    printf("Enter flight index to edit (1-%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    printf("What would you like to edit?\n");
    printf("1 - Flight Number\n");
    printf("2 - Status\n");
    printf("3 - Passenger Capacity\n");
    printf("Select option: ");
    scanf("%d", &option);
    
    switch (option) {
        case 1:
            printf("Enter new flight number: ");
            scanf("%s", flights[index].flightNumber);
            break;
        case 2:
            printf("Enter new status (Active/Delayed/Canceled): ");
            scanf("%s", flights[index].status);
            break;
        case 3:
            printf("Enter new passenger capacity: ");
            scanf("%d", &flights[index].passengerCapacity);
            break;
        default:
            printf("Invalid option!\n");
            return;
    }
    printf("Flight updated successfully!\n");
}

// update flight status
void update_flight_status() {
    if (flightCount == 0) {
        printf("No flights available to update.\n");
        return;
    }
    int index;
    printf("Enter flight index to update status (%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    printf("Enter new status (Active/Delayed/Canceled): ");
    scanf("%s", flights[index].status);
    printf("Flight status updated successfully!\n");
}

// add a passenger at the airport
void add_passenger_airport() {
    char name[NAME_LEN];
    printf("Enter passenger name: ");
    scanf("%s", name);
    printf("Passenger %s added at the airport. Assign them to a flight later.\n", name);
}

// add a passenger to a flight
void add_passenger_flight() {
    int index;
    if (flightCount == 0) {
        printf("No flights available to add a passenger.\n");
        return;
    }
    printf("Enter flight index to add passenger (%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    if (flights[index].passengerCount >= flights[index].passengerCapacity) {
        flights[index].passengerCapacity *= 2;
        flights[index].passengers = (Passenger *)realloc(flights[index].passengers, flights[index].passengerCapacity * sizeof(Passenger));
        if (!flights[index].passengers) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    printf("Enter passenger name: ");
    scanf("%s", flights[index].passengers[flights[index].passengerCount].name);
    strcpy(flights[index].passengers[flights[index].passengerCount].status, "CheckedIn");
    flights[index].passengerCount++;
    printf("Passenger added successfully!\n");
}

// change passenger status
void change_passenger_status() {
    int flightIndex, passengerIndex;
    printf("Enter flight index (1-%d): ", flightCount);
    scanf("%d", &flightIndex);
    if (flightIndex < 1 || flightIndex > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    flightIndex--;
    if (flights[flightIndex].passengerCount == 0) {
        printf("No passengers on this flight.\n");
        return;
    }
    printf("Enter passenger index (%d): ", flights[flightIndex].passengerCount);
    scanf("%d", &passengerIndex);
    if (passengerIndex < 1 || passengerIndex > flights[flightIndex].passengerCount) {
        printf("Invalid passenger index!\n");
        return;
    }
    passengerIndex--;
    printf("Enter new status for passenger %s: ", flights[flightIndex].passengers[passengerIndex].name);
    scanf("%s", flights[flightIndex].passengers[passengerIndex].status);
    printf("Passenger status updated successfully!\n");
}

// print passenger list for a flight
void print_passenger_list() {
    int index;
    printf("Enter flight index to view passengers (%d): ", flightCount);
    scanf("%d", &index);
    if (index < 1 || index > flightCount) {
        printf("Invalid flight index!\n");
        return;
    }
    index--;
    if (flights[index].passengerCount == 0) {
        printf("No passengers on this flight.\n");
        return;
    }
    printf("\nPassengers on Flight %s:\n", flights[index].flightNumber);
    for (int i = 0; i < flights[index].passengerCount; i++) {
        printf("%d. %s - %s\n", i + 1, flights[index].passengers[i].name, flights[index].passengers[i].status);
    }
}

// free allocated memory
void freeMemory() {
    for (int i = 0; i < flightCount; i++) {
        free(flights[i].passengers);
    }
    free(flights);
}

// main menu 
void mainMenu() {
    int choice;
    while (1) {
        printHeader();
        printMenu();
        printAuthorInfo();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0: print_help(); break;
            case 1: print_flights(); break;
            case 2: update_flight_status(); break;
            case 3: add_flight(); break;
            case 4: delete_flight(); break;
            case 5: edit_flight(); break;
            case 6: print_flights(); break;
            case 7: add_passenger_airport(); break;
            case 8: add_passenger_flight(); break;
            case 9: change_passenger_status(); break;
            case 10: print_passenger_list(); break;
            case 11: printf("Exiting program...\n"); freeMemory(); exit(0);
            default: printf("Invalid choice, please try again!\n");
        }
    }
}

int main() {
    initializeFlights();
    mainMenu();
    return 0;
}